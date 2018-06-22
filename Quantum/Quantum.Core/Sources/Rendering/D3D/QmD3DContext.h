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

struct IDXGIFactory5;
struct ID3D12Device;
struct ID3D12InfoQueue;
struct ID3D12CommandQueue;
struct IDXGISwapChain1;
struct IDXGIAdapter1;
struct ID3D12Resource;
struct ID3D12CommandAllocator;
struct ID3D12GraphicsCommandList;
struct ID3D12Fence;
struct ID3D12RootSignature;

class QmD3DContext
{
	friend class QmApplication;

public:
	//inline bool				isValid() const;

private:
								QmD3DContext();
								~QmD3DContext();

	bool						create( QmWindow* pWindow );
	void						destroy();

	IDXGIAdapter1*				findAdapter() const;

	// DirectX interfaces
	IDXGIFactory5*				_pDXGIFactory				= nullptr;
	ID3D12Device*				_pD3DDevice					= nullptr;
	ID3D12InfoQueue*			_pD3DInfoQueue				= nullptr;	
	ID3D12CommandQueue*			_pD3DCommandQueue			= nullptr;
	IDXGISwapChain1*			_pD3DSwapChain				= nullptr;
	ID3D12Resource**			_ppRenderTargetArray		= nullptr;
	ID3D12CommandAllocator**	_ppCommandAllocatorArray	= nullptr;
	ID3D12GraphicsCommandList*	_pCommandList				= nullptr;
	ID3D12Fence*				_pFence						= nullptr;
	ID3D12RootSignature*		_pRootSignature				= nullptr;

	// Others
	QmWin32Handle				_hFenceEvent				= nullptr;
	uint64						_uiFenceValue				= 0;
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