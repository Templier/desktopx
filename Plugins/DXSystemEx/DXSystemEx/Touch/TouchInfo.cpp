///////////////////////////////////////////////////////////////////////////////////////////////
//
// DXSystemEx - Extended System Information
//
// Copyright (c) 2009-2011, Julien Templier
// All rights reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////
//
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
//  1. Redistributions of source code must retain the above copyright notice, this list of
//     conditions and the following disclaimer.
//  2. Redistributions in binary form must reproduce the above copyright notice, this list
//     of conditions and the following disclaimer in the documentation and/or other materials
//     provided with the distribution.
//  3. The name of the author may not be used to endorse or promote products derived from this
//     software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS
//  OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
//  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
//  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
//  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
//  GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
//  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
//  OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
//  POSSIBILITY OF SUCH DAMAGE.
//
///////////////////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TouchInfo.h"


void CTouchInfo::Init(HWND hwnd, TOUCHINPUT input) {
	// Coordinates
	_pt.x = TOUCH_COORD_TO_PIXEL(input.x);
	_pt.y = TOUCH_COORD_TO_PIXEL(input.y);
	ScreenToClient(hwnd, &_pt);

	_id = input.dwID;

	_time = (input.dwMask & TOUCHINPUTMASKF_TIMEFROMSYSTEM) ? input.dwTime : -1;

	_flags = input.dwFlags;

	if (input.dwMask & TOUCHINPUTMASKF_CONTACTAREA) {
		_size.x = input.cxContact;
		_size.y = input.cyContact;

		ScreenToClient(hwnd, &_size);
	} else {
		_size.x = -1;
		_size.y = -1;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ISupportErrorInfo
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
STDMETHODIMP CTouchInfo::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] =
	{
		&IID_ITouchInfo
	};

	for (unsigned int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ITouchInfo
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

STDMETHODIMP CTouchInfo::get_X(long* x)
{
	*x = _pt.x;
	return S_OK;
}

STDMETHODIMP CTouchInfo::get_Y(long* y)
{
	*y = _pt.y;
	return S_OK;
}

STDMETHODIMP CTouchInfo::get_Id(int* id)
{
	*id = _id;
	return S_OK;
}

STDMETHODIMP CTouchInfo::get_Time(int* time)
{
	*time = _time;
	return S_OK;
}

STDMETHODIMP CTouchInfo::HasFlag(int flagId, VARIANT_BOOL* hasFlag)
{
	if (_flags & flagId)
		*hasFlag = VARIANT_TRUE;
	else
		*hasFlag = VARIANT_FALSE;

	return S_OK;
}

STDMETHODIMP CTouchInfo::get_Width(long* width)
{
	*width = _size.x;

	return S_OK;
}

STDMETHODIMP CTouchInfo::get_Height(long* height)
{
	*height = _size.y;
	return S_OK;
}