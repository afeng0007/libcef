// Copyright (c) 2011 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#include "webview_host.h"

WebViewHost::WebViewHost()
{
}

#if !defined(OS_MACOSX)
WebViewHost::~WebViewHost()
{
}
#endif
