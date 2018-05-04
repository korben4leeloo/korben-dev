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

//struct IDXGISwapChain;
//struct ID3D11Device;
//struct ID3D11DeviceContext;
//struct ID3D11RenderTargetView;

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

	/*IDXGISwapChain*			_pSwapChain;
	ID3D11Device*			_pD3D11Device;
	ID3D11DeviceContext*	_pD3D11DeviceContext;
	ID3D11RenderTargetView* _pRenderTargetView;*/
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