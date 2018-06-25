//*****************************************************************************
//
//	Class:		QmD3DShader
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __QUANTUM_CORE_D3D_SHADER_H__
#define __QUANTUM_CORE_D3D_SHADER_H__

#include "Root.h"

struct D3D12_SHADER_BYTECODE;

class QmD3DShader
{
public:
	enum ShaderType
	{
		ShaderTypeVertex,
		ShaderTypePixel
	};
	
private:
							QmD3DShader( const ShaderType eShaderType );
							~QmD3DShader();

	ShaderType				_eShaderTYpe;
	D3D12_SHADER_BYTECODE*	_pByteCode = nullptr;
};

#endif