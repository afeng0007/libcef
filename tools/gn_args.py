# Copyright 2016 The Chromium Embedded Framework Authors. Portions copyright
# 2012 Google Inc. All rights reserved. Use of this source code is governed by
# a BSD-style license that can be found in the LICENSE file.

import os
import shlex
import sys

# Determine the platform.
if sys.platform == 'win32':
  platform = 'windows'
elif sys.platform == 'darwin':
  platform = 'macosx'
elif sys.platform.startswith('linux'):
  platform = 'linux'
else:
  print 'Unknown operating system platform'
  sys.exit()

def msg(msg):
  print 'NOTE: ' + msg

def NameValueListToDict(name_value_list):
  """
  Takes an array of strings of the form 'NAME=VALUE' and creates a dictionary
  of the pairs. If a string is simply NAME, then the value in the dictionary
  is set to True. If VALUE can be converted to a boolean or integer, it is.
  """
  result = { }
  for item in name_value_list:
    tokens = item.split('=', 1)
    if len(tokens) == 2:
      token_value = tokens[1]
      if token_value.lower() == 'true':
        token_value = True
      elif token_value.lower() == 'false':
        token_value = False
      else:
        # If we can make it an int, use that, otherwise, use the string.
        try:
          token_value = int(token_value)
        except ValueError:
          sys.exc_clear()
      # Set the variable to the supplied value.
      result[tokens[0]] = token_value
    else:
      # No value supplied, treat it as a boolean and set it.
      result[tokens[0]] = True
  return result

def ShlexEnv(env_name):
  """
  Split an environment variable using shell-like syntax.
  """
  flags = os.environ.get(env_name, [])
  if flags:
    flags = shlex.split(flags)
  return flags

def MergeDicts(*dict_args):
  """
  Given any number of dicts, shallow copy and merge into a new dict.
  Precedence goes to key value pairs in latter dicts.
  """
  result = {}
  for dictionary in dict_args:
    result.update(dictionary)
  return result

def GetChromiumDefaultArgs():
  """
  Return default GN args. These must match the Chromium defaults.
  Only args that may be retrieved via GetArgValue() need to be specified here.
  """
  # Search for these values in declare_args() sections of *.gni files to find
  # the defaults.

  defaults = {
    'dcheck_always_on': False,
    'is_asan': False,
    'is_debug': True,
    'is_official_build': False,
    'target_cpu': 'x64',
  }

  if platform == 'linux':
    defaults['use_sysroot'] = True

  if platform == 'windows':
    defaults['is_win_fastlink'] = False
    defaults['visual_studio_path'] = ''
    defaults['visual_studio_version'] = ''
    defaults['visual_studio_runtime_dirs'] = ''
    defaults['windows_sdk_path'] = ''

  return defaults

def GetArgValue(args, key):
  """
  Return an existing GN arg value or the Chromium default.
  """
  defaults = GetChromiumDefaultArgs()
  assert key in defaults, "No default Chromium value specified for %s" % key
  return args.get(key, defaults[key])

def GetRecommendedDefaultArgs():
  """
  Return recommended default GN args that differ from Chromium defaults.
  """
  # Search for these values in declare_args() sections of *.gni files to find
  # the defaults.

  result = {
    # Enable NaCL. Default is true. False is recommended for faster builds.
    'enable_nacl': False,
  }

  if platform == 'linux':
    # Use a sysroot environment. Default is true. False is recommended for local
    # builds.
    # Run the following commands to download the sysroot environment:
    # x86 build only:   $ export GYP_DEFINES='target_arch=ia32'
    # x86 or x64 build: $ gclient runhooks
    result['use_sysroot'] = False

  return result

def GetGNEnvArgs():
  """
  Return GN args specified via the GN_DEFINES env variable.
  """
  return NameValueListToDict(ShlexEnv('GN_DEFINES'))

def GetRequiredArgs():
  """
  Return required GN args. Also enforced by assert() in //cef/BUILD.gn.
  """
  result = {
    # Set ENABLE_PRINTING=1 ENABLE_BASIC_PRINTING=1.
    'enable_basic_printing': True,
    'enable_print_preview': False,

    # Enable support for Widevine CDM.
    'enable_widevine': True,

    # Disable support for plugin installation.
    'enable_plugin_installation': False,

    # CEF does not currently support component builds. See
    # https://bitbucket.org/chromiumembedded/cef/issues/1617
    'is_component_build': False,
  }

  if platform == 'linux' or platform == 'macosx':
    # Don't use the chrome style plugin.
    result['clang_use_chrome_plugins'] = False

  return result

def GetMergedArgs(build_args):
  """
  Return merged GN args.
  """
  return MergeDicts(GetRecommendedDefaultArgs(), GetGNEnvArgs(), build_args, GetRequiredArgs())

def ValidateArgs(args):
  """
  Validate GN arg combinations that we know about. Also provide suggestions
  where appropriate.
  """
  dcheck_always_on = GetArgValue(args, 'dcheck_always_on')
  is_asan = GetArgValue(args, 'is_asan')
  is_debug = GetArgValue(args, 'is_debug')
  is_official_build = GetArgValue(args, 'is_official_build')
  target_cpu = GetArgValue(args, 'target_cpu')

  if platform == 'linux':
    use_sysroot = GetArgValue(args, 'use_sysroot')

  if platform == 'windows':
    is_win_fastlink = GetArgValue(args, 'is_win_fastlink')
    visual_studio_path = GetArgValue(args, 'visual_studio_path')
    visual_studio_version = GetArgValue(args, 'visual_studio_version')
    visual_studio_runtime_dirs = GetArgValue(args, 'visual_studio_runtime_dirs')
    windows_sdk_path = GetArgValue(args, 'windows_sdk_path')

  # Target CPU architecture.
  # - Windows supports "x86" and "x64".
  # - Mac supports only "x64".
  # - Linux supports only "x64" unless using a sysroot environment.
  if platform == 'macosx':
    assert target_cpu == 'x64', 'target_cpu must be "x64"'
  else:
    assert target_cpu in ('x86', 'x64'), 'target_cpu must be "x86" or "x64"'

  if platform == 'linux' and target_cpu == 'x86':
    assert use_sysroot, 'target_cpu="x86" requires use_sysroot=true'

  # ASAN requires Release builds.
  if is_asan:
    assert not is_debug, "is_asan=true requires is_debug=false"
    if not dcheck_always_on:
      msg('is_asan=true recommends dcheck_always_on=true')

  # Official build requires Release builds.
  if is_official_build:
    assert not is_debug, "is_official_build=true requires is_debug=false"

  if platform == 'windows':
    # Official builds should not use /DEBUG:FASTLINK.
    if is_official_build:
      assert not is_win_fastlink, "is_official_build=true precludes is_win_fastlink=true"

    # Non-official debug builds should use /DEBUG:FASTLINK.
    if not is_official_build and is_debug and not is_win_fastlink:
        msg('is_official_build=false + is_debug=true recommends is_win_fastlink=true')

    # Windows custom toolchain requirements.
    #
    # Required GN arguments:
    #   visual_studio_path="<path to VS root>"
    #     The directory that contains Visual Studio. For example, a subset of
    #     "C:\Program Files (x86)\Microsoft Visual Studio 14.0".
    #   visual_studio_version="<VS version>"
    #     The VS version. For example, "2015".
    #   visual_studio_runtime_dirs="<path to VS CRT>"
    #     The directory that contains the VS CRT. For example, the contents of
    #     "C:\Program Files (x86)\Windows Kits\10\Redist\ucrt\DLLs\x64" plus
    #     "C:\Windows\System32\ucrtbased.dll"
    #   windows_sdk_path="<path to WinSDK>"
    #     The directory that contains the Win SDK. For example, a subset of
    #     "C:\Program Files (x86)\Windows Kits\10".
    #
    # Required environment variables:
    #   DEPOT_TOOLS_WIN_TOOLCHAIN=0
    #   GYP_MSVS_OVERRIDE_PATH=<path to VS root, must match visual_studio_path>
    #   GYP_MSVS_VERSION=<VS version, must match visual_studio_version>
    #   CEF_VCVARS=none
    #   INCLUDE=<VS include paths>
    #   LIB=<VS library paths>
    #   PATH=<VS executable paths>
    #
    # See comments in gclient_hook.py for environment variable usage.
    #
    if visual_studio_path != '':
      assert visual_studio_version != '', 'visual_studio_path requires visual_studio_version'
      assert visual_studio_runtime_dirs != '', 'visual_studio_path requires visual_studio_runtime_dirs'
      assert windows_sdk_path != '', 'visual_studio_path requires windows_sdk_path'

      assert os.environ.get('DEPOT_TOOLS_WIN_TOOLCHAIN', '') == '0', \
        "visual_studio_path requires DEPOT_TOOLS_WIN_TOOLCHAIN=0 env variable"

      msvs_path = os.environ.get('GYP_MSVS_OVERRIDE_PATH', '')
      assert msvs_path == visual_studio_path and os.path.exists(msvs_path), \
        "visual_studio_path requires matching GYP_MSVS_OVERRIDE_PATH env variable"

      msvs_version = os.environ.get('GYP_MSVS_VERSION', '')
      assert msvs_version == visual_studio_version, \
        "visual_studio_version requires matching GYP_MSVS_VERSION env variable"

      assert os.environ.get('CEF_VCVARS', '') == 'none', \
        "visual_studio_path requires CEF_VCVARS=none env variable"

      assert 'INCLUDE' in os.environ \
        and 'LIB' in os.environ \
        and 'PATH' in os.environ, \
        "visual_studio_path requires INCLUDE, LIB and PATH env variables"

      # If "%GYP_MSVS_OVERRIDE_PATH%\VC\vcvarsall.bat" exists then environment
      # variables will be derived from there and the specified INCLUDE/LIB/PATH
      # values will be ignored by Chromium. If this file does not exist then the
      # INCLUDE/LIB/PATH values are also required by Chromium.
      vcvars_path = os.path.join(msvs_path, 'VC', 'vcvarsall.bat')
      if (os.path.exists(vcvars_path)):
        msg('INCLUDE/LIB/PATH values will be derived from %s' % vcvars_path)

def GetConfigArgs(args, is_debug, is_x64):
  """
  Return merged GN args for the configuration and validate.
  """
  add_args = {}

  # Cannot create is_official_build=true is_debug=true builds.
  # This restriction is enforced in //build/config/BUILDCONFIG.gn.
  # Instead, our "official Debug" build is a Release build with dchecks and
  # symbols. Symbols will be generated by default for official builds; see the
  # definition of 'symbol_level' in //build/config/compiler/compiler.gni.
  if is_debug and GetArgValue(args, 'is_official_build'):
    is_debug = False
    add_args['dcheck_always_on'] = True

  result = MergeDicts(args, add_args, {
    'is_debug': is_debug,
    'target_cpu': 'x64' if is_x64 else 'x86',
  })
  ValidateArgs(result)
  return result

def GetAllPlatformConfigs(build_args):
  """
  Return a map of directory name to GN args for the current platform.
  """
  result = {}

  # Merged args without validation.
  args = GetMergedArgs(build_args)

  create_debug = True

  # Don't create debug directories for asan builds.
  if GetArgValue(args, 'is_asan'):
    create_debug = False
    msg('Not generating Debug configuration due to is_asan=true')

  # Always create x64 configs.
  if create_debug:
    result['Debug_GN_x64'] = GetConfigArgs(args, True, True)
  result['Release_GN_x64'] = GetConfigArgs(args, False, True)

  # Create x86 configs on Windows and on Linux when using the sysroot.
  if platform == 'windows' or \
    (platform == 'linux' and GetArgValue(args, 'use_sysroot') == True):
    if create_debug:
      result['Debug_GN_x86'] = GetConfigArgs(args, True, False)
    result['Release_GN_x86'] = GetConfigArgs(args, False, False)

  return result

def GetConfigFileContents(args):
  """
  Generate config file contents for the arguments.
  """
  pairs = []
  for k in sorted(args.keys()):
    val = args[k]
    if isinstance(val, basestring):
      val = '"%s"' % val
    elif isinstance(val, bool):
      if val:
        val = 'true'
      else:
        val = 'false'
    pairs.append("%s=%s" % (k, val))
  return "\n".join(pairs)


# Program entry point.
if __name__ == '__main__':
  import sys

  # Allow override of the platform via the command-line for testing.
  if len(sys.argv) > 1:
    platform = sys.argv[1]
    if not platform in ('linux', 'macosx', 'windows'):
      sys.stderr.write('Usage: %s <platform>' % sys.argv[0])
      sys.exit()

  print 'Platform: %s' % platform

  # Dump the configuration based on platform and environment.
  configs = GetAllPlatformConfigs({})
  for dir, config in configs.items():
    print '\n\nout/%s:\n' % dir
    print GetConfigFileContents(config)
