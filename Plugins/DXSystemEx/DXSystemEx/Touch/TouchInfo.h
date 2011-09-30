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
// CTouchInfo
class ATL_NO_VTABLE CTouchInfo :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CTouchInfo, &CLSID_TouchInfo>,
	public IDispatchImpl<ITouchInfo, &IID_ITouchInfo, &LIBID_DXSystemExLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public ISupportErrorInfo
{
public:
	CTouchInfo() {
	}

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_TOUCHINFO)

DECLARE_NOT_AGGREGATABLE(CTouchInfo)

BEGIN_COM_MAP(CTouchInfo)
	COM_INTERFACE_ENTRY(ITouchInfo)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

	private:
		TOUCHINPUT _input;

	public:
		void Init(TOUCHINPUT input) { _input = input; }

		//////////////////////////////////////////////////////////////////////////
		// ISupportErrorInfo
		//////////////////////////////////////////////////////////////////////////
		STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

		//////////////////////////////////////////////////////////////////////////
		// ITouchInfo
		//////////////////////////////////////////////////////////////////////////
		STDMETHOD(get_X)(long* x);
		STDMETHOD(get_Y)(long* y);
		STDMETHOD(get_Id)(int* id);
		STDMETHOD(get_Time)(int* time);
		STDMETHOD(get_Width)(long* width);
		STDMETHOD(get_Height)(long* height);

		STDMETHOD(HasFlag)(int flagId, VARIANT_BOOL* hasFlag);
};

OBJECT_ENTRY_AUTO(__uuidof(TouchInfo), CTouchInfo)
