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

#ifndef _CONVERT_CSP_H_
#define _CONVERT_CSP_H_

typedef void (*funcConvertCSP) (void **dst, const void **src, int width, int src_y_pitch_byte, int src_uv_pitch_byte, int dst_y_pitch_byte, int height, int dst_height, int *crop);

enum VCE_CSP {
    VCE_CSP_NA,
    VCE_CSP_NV12,
    VCE_CSP_YV12,
    VCE_CSP_YV12_09,
    VCE_CSP_YV12_10,
    VCE_CSP_YV12_12,
    VCE_CSP_YV12_14,
    VCE_CSP_YV12_16,
    VCE_CSP_YUY2,
    VCE_CSP_YUV444,
    VCE_CSP_YUV444_09,
    VCE_CSP_YUV444_10,
    VCE_CSP_YUV444_12,
    VCE_CSP_YUV444_14,
    VCE_CSP_YUV444_16,
};

static const TCHAR *VCE_CSP_NAMES[] = {
    _T("Invalid"),
    _T("nv12"),
    _T("yv12"),
    _T("yv12 (9bit)"),
    _T("yv12 (10bit)"),
    _T("yv12 (12bit)"),
    _T("yv12 (14bit)"),
    _T("yv12 (16bit)"),
    _T("yuy2"),
    _T("yuv444"),
    _T("yuv444 (9bit)"),
    _T("yuv444 (10bit)"),
    _T("yuv444 (12bit)"),
    _T("yuv444 (14bit)"),
    _T("yuv444 (16bit)")
};

typedef struct ConvertCSP {
    VCE_CSP csp_from, csp_to;
    bool uv_only;
    funcConvertCSP func[2];
    unsigned int simd;
} ConvertCSP;

const ConvertCSP *get_convert_csp_func(VCE_CSP csp_from, VCE_CSP csp_to, bool uv_only);
const TCHAR *get_simd_str(unsigned int simd);

#endif //_CONVERT_CSP_H_
