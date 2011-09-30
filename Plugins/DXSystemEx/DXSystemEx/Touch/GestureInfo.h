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

#pragma once

#include "stdafx.h"
#include <comsvcs.h>

#include "COMError.h"
#include "DXSystemEx.h"

using namespace std;

/////////////////////////////////////////////////////////////////////////////
// CGestureInfo
class ATL_NO_VTABLE CGestureInfo :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CGestureInfo, &CLSID_GestureInfo>,
	public IDispatchImpl<IGestureInfo, &IID_IGestureInfo, &LIBID_DXSystemExLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public ISupportErrorInfo
{
public:
	CGestureInfo() : _id(0), _x(0), _y(0), _distance(0), _angle(0), _flags(0), _x1(0), _y1(0)
	{
	}

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_GESTUREINFO)

DECLARE_NOT_AGGREGATABLE(CGestureInfo)

BEGIN_COM_MAP(CGestureInfo)
	COM_INTERFACE_ENTRY(IGestureInfo)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

	private:
		int  _id;
		int  _x;
		int  _y;
		int  _distance;
		int  _angle;
		int  _flags;
		int  _x1;
		int  _y1;

		POINTS localizePoint(HWND hwnd, const POINTS &pt);

	public:
		void Init(HWND hwnd, GESTUREINFO info);

		//////////////////////////////////////////////////////////////////////////
		// ISupportErrorInfo
		//////////////////////////////////////////////////////////////////////////
		STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

		//////////////////////////////////////////////////////////////////////////
		// IGestureInfo
		//////////////////////////////////////////////////////////////////////////
		STDMETHOD(get_Id)(int* id);
		STDMETHOD(get_X)(int* x);
		STDMETHOD(get_Y)(int* y);
		STDMETHOD(get_Distance)(int* distance);
		STDMETHOD(get_Angle)(int* angle);
		STDMETHOD(get_X1)(int* x1);
		STDMETHOD(get_Y1)(int* y1);

		STDMETHOD(HasFlag)(int id, VARIANT_BOOL* hasFlag);

};

OBJECT_ENTRY_AUTO(__uuidof(GestureInfo), CGestureInfo)
