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
#include "GestureInfo.h"

#include <intsafe.h>

void CGestureInfo::Init(HWND hwnd, GESTUREINFO info)
{
	// Id
	_id = info.dwID;

	// Location
	POINTS pt = localizePoint(hwnd, info.ptsLocation);
	_x = pt.x;
	_y = pt.y;

	// Flags
	_flags = info.dwFlags;

	// Gesture-specific data
	switch (_id)
	{
	default:
		// Unrecognized gesture
		break;

	case GID_ZOOM:
	case GID_TWOFINGERTAP:
		_distance = LODWORD(info.ullArguments);
		break;

	case GID_PAN:
		_distance = LODWORD(info.ullArguments);

		// Handle inertia
		if (_flags & GF_INERTIA) {
			DWORD vec = HIDWORD(info.ullArguments);
			POINTS inertia = MAKEPOINTS(vec);
			_x1 = inertia.x;
			_y1 = inertia.y;
		}
		break;

	case GID_ROTATE:
		_angle = (int)GID_ROTATE_ANGLE_FROM_ARGUMENT(info.ullArguments);
		break;

	case GID_PRESSANDTAP:
		if (info.ullArguments > 0) {
			POINTS pts = MAKEPOINTS(info.ullArguments);
			POINT delta;
			POINTSTOPOINT(delta, pts);

			_x1 = delta.x;
			_y1 = delta.y;
		}
		break;
	}
}

POINTS CGestureInfo::localizePoint(HWND hwnd, const POINTS& pt)
{
	POINT point;
	point.x = pt.x;
	point.y = pt.y;

	ScreenToClient(hwnd, &point);

	POINTS pts;
	pts.x = (SHORT)point.x;
	pts.y = (SHORT)point.y;

	return pts;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ISupportErrorInfo
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
STDMETHODIMP CGestureInfo::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] =
	{
		&IID_IGestureInfo
	};

	for (unsigned int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// IGestureInfo
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
STDMETHODIMP CGestureInfo::get_Id(int* id)
{
	*id = _id;

	return S_OK;
}

STDMETHODIMP CGestureInfo::get_X(int* x)
{
	*x = _x;

	return S_OK;
}

STDMETHODIMP CGestureInfo::get_Y(int* y)
{
	*y = _y;

	return S_OK;
}

STDMETHODIMP CGestureInfo::get_Distance(int* distance)
{
	*distance = _distance;

	return S_OK;
}

STDMETHODIMP CGestureInfo::get_Angle(int* angle)
{
	*angle = _angle;

	return S_OK;
}

STDMETHODIMP CGestureInfo::get_X1(int* x1)
{
	*x1 = _x1;

	return S_OK;
}

STDMETHODIMP CGestureInfo::get_Y1(int* y1)
{
	*y1 = _y1;

	return S_OK;
}

STDMETHODIMP CGestureInfo::HasFlag(int id, VARIANT_BOOL* hasFlag)
{
	*hasFlag = (_flags & id) ? VARIANT_TRUE : VARIANT_FALSE;

	return S_OK;
}