﻿// -----------------------------------------------------------------------------------------
//     VCEEnc by rigaya
// -----------------------------------------------------------------------------------------
// The MIT License
//
// Copyright (c) 2014-2017 rigaya
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// IABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// ------------------------------------------------------------------------------------------

#pragma once

#include <mutex>
#include <d3d9.h>
#include <d3d11.h>
#pragma warning(push)
#pragma warning(disable:4100)
#include "VideoEncoderVCE.h"

#include "VCEUtil.h"
#include "VCEParam.h"
#pragma warning(pop)

class VCELog {
protected:
    int m_nLogLevel = VCE_LOG_INFO;
    const TCHAR *m_pStrLog = nullptr;
    bool m_bHtml = false;
    std::mutex m_mtx;
    static const char *HTML_FOOTER;
public:
    VCELog(const TCHAR *pLogFile, int log_level = VCE_LOG_INFO) {
        init(pLogFile, log_level);
    };
    virtual ~VCELog() {
    };
    void init(const TCHAR *pLogFile, int log_level = VCE_LOG_INFO);
    void writeFileHeader(const TCHAR *pDstFilename);
    void writeHtmlHeader();
    void writeFileFooter();
    int getLogLevel() {
        return m_nLogLevel;
    }
    int setLogLevel(int newLogLevel) {
        int prevLogLevel = m_nLogLevel;
        m_nLogLevel = newLogLevel;
        return prevLogLevel;
    }
    bool logFileAvail() {
        return m_pStrLog != nullptr;
    }
    virtual void write_log(int log_level, const TCHAR *buffer, bool file_only = false);
    virtual void write(int log_level, const TCHAR *format, ...);
    virtual void write(int log_level, const WCHAR *format, va_list args);
    virtual void write(int log_level, const char *format, va_list args, uint32_t codepage = CP_THREAD_ACP);
    virtual void write_line(int log_level, const char *format, va_list args, uint32_t codepage = CP_THREAD_ACP);
};
