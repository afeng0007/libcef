// Copyright (c) 2016 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool. If making changes by
// hand only do so within the body of existing method and function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//

#include "libcef_dll/cpptoc/request_handler_cpptoc.h"
#include "libcef_dll/cpptoc/resource_handler_cpptoc.h"
#include "libcef_dll/cpptoc/response_filter_cpptoc.h"
#include "libcef_dll/ctocpp/auth_callback_ctocpp.h"
#include "libcef_dll/ctocpp/browser_ctocpp.h"
#include "libcef_dll/ctocpp/frame_ctocpp.h"
#include "libcef_dll/ctocpp/request_ctocpp.h"
#include "libcef_dll/ctocpp/request_callback_ctocpp.h"
#include "libcef_dll/ctocpp/response_ctocpp.h"
#include "libcef_dll/ctocpp/sslinfo_ctocpp.h"


namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

int CEF_CALLBACK request_handler_on_before_browse(
    struct _cef_request_handler_t* self, cef_browser_t* browser,
    cef_frame_t* frame, cef_request_t* request, int is_redirect) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return 0;
  // Verify param: frame; type: refptr_diff
  DCHECK(frame);
  if (!frame)
    return 0;
  // Verify param: request; type: refptr_diff
  DCHECK(request);
  if (!request)
    return 0;

  // Execute
  bool _retval = CefRequestHandlerCppToC::Get(self)->OnBeforeBrowse(
      CefBrowserCToCpp::Wrap(browser),
      CefFrameCToCpp::Wrap(frame),
      CefRequestCToCpp::Wrap(request),
      is_redirect?true:false);

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK request_handler_on_open_urlfrom_tab(
    struct _cef_request_handler_t* self, cef_browser_t* browser,
    cef_frame_t* frame, const cef_string_t* target_url,
    cef_window_open_disposition_t target_disposition, int user_gesture) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return 0;
  // Verify param: frame; type: refptr_diff
  DCHECK(frame);
  if (!frame)
    return 0;
  // Verify param: target_url; type: string_byref_const
  DCHECK(target_url);
  if (!target_url)
    return 0;

  // Execute
  bool _retval = CefRequestHandlerCppToC::Get(self)->OnOpenURLFromTab(
      CefBrowserCToCpp::Wrap(browser),
      CefFrameCToCpp::Wrap(frame),
      CefString(target_url),
      target_disposition,
      user_gesture?true:false);

  // Return type: bool
  return _retval;
}

cef_return_value_t CEF_CALLBACK request_handler_on_before_resource_load(
    struct _cef_request_handler_t* self, cef_browser_t* browser,
    cef_frame_t* frame, cef_request_t* request,
    cef_request_callback_t* callback) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return RV_CONTINUE;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return RV_CONTINUE;
  // Verify param: frame; type: refptr_diff
  DCHECK(frame);
  if (!frame)
    return RV_CONTINUE;
  // Verify param: request; type: refptr_diff
  DCHECK(request);
  if (!request)
    return RV_CONTINUE;
  // Verify param: callback; type: refptr_diff
  DCHECK(callback);
  if (!callback)
    return RV_CONTINUE;

  // Execute
  cef_return_value_t _retval = CefRequestHandlerCppToC::Get(
      self)->OnBeforeResourceLoad(
      CefBrowserCToCpp::Wrap(browser),
      CefFrameCToCpp::Wrap(frame),
      CefRequestCToCpp::Wrap(request),
      CefRequestCallbackCToCpp::Wrap(callback));

  // Return type: simple
  return _retval;
}

struct _cef_resource_handler_t* CEF_CALLBACK request_handler_get_resource_handler(
    struct _cef_request_handler_t* self, cef_browser_t* browser,
    cef_frame_t* frame, cef_request_t* request) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return NULL;
  // Verify param: frame; type: refptr_diff
  DCHECK(frame);
  if (!frame)
    return NULL;
  // Verify param: request; type: refptr_diff
  DCHECK(request);
  if (!request)
    return NULL;

  // Execute
  CefRefPtr<CefResourceHandler> _retval = CefRequestHandlerCppToC::Get(
      self)->GetResourceHandler(
      CefBrowserCToCpp::Wrap(browser),
      CefFrameCToCpp::Wrap(frame),
      CefRequestCToCpp::Wrap(request));

  // Return type: refptr_same
  return CefResourceHandlerCppToC::Wrap(_retval);
}

void CEF_CALLBACK request_handler_on_resource_redirect(
    struct _cef_request_handler_t* self, cef_browser_t* browser,
    cef_frame_t* frame, cef_request_t* request,
    struct _cef_response_t* response, cef_string_t* new_url) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return;
  // Verify param: frame; type: refptr_diff
  DCHECK(frame);
  if (!frame)
    return;
  // Verify param: request; type: refptr_diff
  DCHECK(request);
  if (!request)
    return;
  // Verify param: response; type: refptr_diff
  DCHECK(response);
  if (!response)
    return;
  // Verify param: new_url; type: string_byref
  DCHECK(new_url);
  if (!new_url)
    return;

  // Translate param: new_url; type: string_byref
  CefString new_urlStr(new_url);

  // Execute
  CefRequestHandlerCppToC::Get(self)->OnResourceRedirect(
      CefBrowserCToCpp::Wrap(browser),
      CefFrameCToCpp::Wrap(frame),
      CefRequestCToCpp::Wrap(request),
      CefResponseCToCpp::Wrap(response),
      new_urlStr);
}

int CEF_CALLBACK request_handler_on_resource_response(
    struct _cef_request_handler_t* self, cef_browser_t* browser,
    cef_frame_t* frame, cef_request_t* request,
    struct _cef_response_t* response) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return 0;
  // Verify param: frame; type: refptr_diff
  DCHECK(frame);
  if (!frame)
    return 0;
  // Verify param: request; type: refptr_diff
  DCHECK(request);
  if (!request)
    return 0;
  // Verify param: response; type: refptr_diff
  DCHECK(response);
  if (!response)
    return 0;

  // Execute
  bool _retval = CefRequestHandlerCppToC::Get(self)->OnResourceResponse(
      CefBrowserCToCpp::Wrap(browser),
      CefFrameCToCpp::Wrap(frame),
      CefRequestCToCpp::Wrap(request),
      CefResponseCToCpp::Wrap(response));

  // Return type: bool
  return _retval;
}

struct _cef_response_filter_t* CEF_CALLBACK request_handler_get_resource_response_filter(
    struct _cef_request_handler_t* self, cef_browser_t* browser,
    cef_frame_t* frame, cef_request_t* request,
    struct _cef_response_t* response) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return NULL;
  // Verify param: frame; type: refptr_diff
  DCHECK(frame);
  if (!frame)
    return NULL;
  // Verify param: request; type: refptr_diff
  DCHECK(request);
  if (!request)
    return NULL;
  // Verify param: response; type: refptr_diff
  DCHECK(response);
  if (!response)
    return NULL;

  // Execute
  CefRefPtr<CefResponseFilter> _retval = CefRequestHandlerCppToC::Get(
      self)->GetResourceResponseFilter(
      CefBrowserCToCpp::Wrap(browser),
      CefFrameCToCpp::Wrap(frame),
      CefRequestCToCpp::Wrap(request),
      CefResponseCToCpp::Wrap(response));

  // Return type: refptr_same
  return CefResponseFilterCppToC::Wrap(_retval);
}

void CEF_CALLBACK request_handler_on_resource_load_complete(
    struct _cef_request_handler_t* self, cef_browser_t* browser,
    cef_frame_t* frame, cef_request_t* request,
    struct _cef_response_t* response, cef_urlrequest_status_t status,
    int64 received_content_length) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return;
  // Verify param: frame; type: refptr_diff
  DCHECK(frame);
  if (!frame)
    return;
  // Verify param: request; type: refptr_diff
  DCHECK(request);
  if (!request)
    return;
  // Verify param: response; type: refptr_diff
  DCHECK(response);
  if (!response)
    return;

  // Execute
  CefRequestHandlerCppToC::Get(self)->OnResourceLoadComplete(
      CefBrowserCToCpp::Wrap(browser),
      CefFrameCToCpp::Wrap(frame),
      CefRequestCToCpp::Wrap(request),
      CefResponseCToCpp::Wrap(response),
      status,
      received_content_length);
}

int CEF_CALLBACK request_handler_get_auth_credentials(
    struct _cef_request_handler_t* self, cef_browser_t* browser,
    cef_frame_t* frame, int isProxy, const cef_string_t* host, int port,
    const cef_string_t* realm, const cef_string_t* scheme,
    cef_auth_callback_t* callback) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return 0;
  // Verify param: frame; type: refptr_diff
  DCHECK(frame);
  if (!frame)
    return 0;
  // Verify param: host; type: string_byref_const
  DCHECK(host);
  if (!host)
    return 0;
  // Verify param: callback; type: refptr_diff
  DCHECK(callback);
  if (!callback)
    return 0;
  // Unverified params: realm, scheme

  // Execute
  bool _retval = CefRequestHandlerCppToC::Get(self)->GetAuthCredentials(
      CefBrowserCToCpp::Wrap(browser),
      CefFrameCToCpp::Wrap(frame),
      isProxy?true:false,
      CefString(host),
      port,
      CefString(realm),
      CefString(scheme),
      CefAuthCallbackCToCpp::Wrap(callback));

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK request_handler_on_quota_request(
    struct _cef_request_handler_t* self, cef_browser_t* browser,
    const cef_string_t* origin_url, int64 new_size,
    cef_request_callback_t* callback) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return 0;
  // Verify param: origin_url; type: string_byref_const
  DCHECK(origin_url);
  if (!origin_url)
    return 0;
  // Verify param: callback; type: refptr_diff
  DCHECK(callback);
  if (!callback)
    return 0;

  // Execute
  bool _retval = CefRequestHandlerCppToC::Get(self)->OnQuotaRequest(
      CefBrowserCToCpp::Wrap(browser),
      CefString(origin_url),
      new_size,
      CefRequestCallbackCToCpp::Wrap(callback));

  // Return type: bool
  return _retval;
}

void CEF_CALLBACK request_handler_on_protocol_execution(
    struct _cef_request_handler_t* self, cef_browser_t* browser,
    const cef_string_t* url, int* allow_os_execution) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return;
  // Verify param: url; type: string_byref_const
  DCHECK(url);
  if (!url)
    return;
  // Verify param: allow_os_execution; type: bool_byref
  DCHECK(allow_os_execution);
  if (!allow_os_execution)
    return;

  // Translate param: allow_os_execution; type: bool_byref
  bool allow_os_executionBool = (
      allow_os_execution && *allow_os_execution)?true:false;

  // Execute
  CefRequestHandlerCppToC::Get(self)->OnProtocolExecution(
      CefBrowserCToCpp::Wrap(browser),
      CefString(url),
      allow_os_executionBool);

  // Restore param: allow_os_execution; type: bool_byref
  if (allow_os_execution)
    *allow_os_execution = allow_os_executionBool?true:false;
}

int CEF_CALLBACK request_handler_on_certificate_error(
    struct _cef_request_handler_t* self, cef_browser_t* browser,
    cef_errorcode_t cert_error, const cef_string_t* request_url,
    struct _cef_sslinfo_t* ssl_info, cef_request_callback_t* callback) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return 0;
  // Verify param: request_url; type: string_byref_const
  DCHECK(request_url);
  if (!request_url)
    return 0;
  // Verify param: ssl_info; type: refptr_diff
  DCHECK(ssl_info);
  if (!ssl_info)
    return 0;
  // Verify param: callback; type: refptr_diff
  DCHECK(callback);
  if (!callback)
    return 0;

  // Execute
  bool _retval = CefRequestHandlerCppToC::Get(self)->OnCertificateError(
      CefBrowserCToCpp::Wrap(browser),
      cert_error,
      CefString(request_url),
      CefSSLInfoCToCpp::Wrap(ssl_info),
      CefRequestCallbackCToCpp::Wrap(callback));

  // Return type: bool
  return _retval;
}

void CEF_CALLBACK request_handler_on_plugin_crashed(
    struct _cef_request_handler_t* self, cef_browser_t* browser,
    const cef_string_t* plugin_path) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return;
  // Verify param: plugin_path; type: string_byref_const
  DCHECK(plugin_path);
  if (!plugin_path)
    return;

  // Execute
  CefRequestHandlerCppToC::Get(self)->OnPluginCrashed(
      CefBrowserCToCpp::Wrap(browser),
      CefString(plugin_path));
}

void CEF_CALLBACK request_handler_on_render_view_ready(
    struct _cef_request_handler_t* self, cef_browser_t* browser) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return;

  // Execute
  CefRequestHandlerCppToC::Get(self)->OnRenderViewReady(
      CefBrowserCToCpp::Wrap(browser));
}

void CEF_CALLBACK request_handler_on_render_process_terminated(
    struct _cef_request_handler_t* self, cef_browser_t* browser,
    cef_termination_status_t status) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return;

  // Execute
  CefRequestHandlerCppToC::Get(self)->OnRenderProcessTerminated(
      CefBrowserCToCpp::Wrap(browser),
      status);
}

}  // namespace


// CONSTRUCTOR - Do not edit by hand.

CefRequestHandlerCppToC::CefRequestHandlerCppToC() {
  GetStruct()->on_before_browse = request_handler_on_before_browse;
  GetStruct()->on_open_urlfrom_tab = request_handler_on_open_urlfrom_tab;
  GetStruct()->on_before_resource_load =
      request_handler_on_before_resource_load;
  GetStruct()->get_resource_handler = request_handler_get_resource_handler;
  GetStruct()->on_resource_redirect = request_handler_on_resource_redirect;
  GetStruct()->on_resource_response = request_handler_on_resource_response;
  GetStruct()->get_resource_response_filter =
      request_handler_get_resource_response_filter;
  GetStruct()->on_resource_load_complete =
      request_handler_on_resource_load_complete;
  GetStruct()->get_auth_credentials = request_handler_get_auth_credentials;
  GetStruct()->on_quota_request = request_handler_on_quota_request;
  GetStruct()->on_protocol_execution = request_handler_on_protocol_execution;
  GetStruct()->on_certificate_error = request_handler_on_certificate_error;
  GetStruct()->on_plugin_crashed = request_handler_on_plugin_crashed;
  GetStruct()->on_render_view_ready = request_handler_on_render_view_ready;
  GetStruct()->on_render_process_terminated =
      request_handler_on_render_process_terminated;
}

template<> CefRefPtr<CefRequestHandler> CefCppToC<CefRequestHandlerCppToC,
    CefRequestHandler, cef_request_handler_t>::UnwrapDerived(
    CefWrapperType type, cef_request_handler_t* s) {
  NOTREACHED() << "Unexpected class type: " << type;
  return NULL;
}

#if DCHECK_IS_ON()
template<> base::AtomicRefCount CefCppToC<CefRequestHandlerCppToC,
    CefRequestHandler, cef_request_handler_t>::DebugObjCt = 0;
#endif

template<> CefWrapperType CefCppToC<CefRequestHandlerCppToC, CefRequestHandler,
    cef_request_handler_t>::kWrapperType = WT_REQUEST_HANDLER;
