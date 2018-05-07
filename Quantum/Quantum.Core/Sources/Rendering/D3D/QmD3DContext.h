//*****************************************************************************
//
//	Class:		QmD3DContext
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __QUANTUM_CORE_D3D_CONTEXT_H__
#define __QUANTUM_CORE_D3D_CONTEXT_H__

#include "Root.h"

class QmWindow;

struct IDXGIFactory4;
struct ID3D12Device;

struct IDXGIAdapter1;

class QmD3DContext
{
	friend class QmApplication;

public:
	//inline bool				isValid() const;

private:
							QmD3DContext();
							~QmD3DContext();

	void					create( QmWindow* pWindow );
	void					destroy();

	IDXGIAdapter1*			findAdapter() const;

	IDXGIFactory4*			_pDXGIFactory	= nullptr;
	ID3D12Device*			_pD3D12Device	= nullptr;
};

//-----------------------------------------------------------------------------
// Name:		isValid
//
// Created:		2013-08-26
//-----------------------------------------------------------------------------
//bool QmD3DContext::isValid() const
//{
//	return ( _pRenderTargetView != nullptr );
//}

#endif