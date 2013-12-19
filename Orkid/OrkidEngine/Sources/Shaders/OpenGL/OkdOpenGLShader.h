//*****************************************************************************
//
//	Class:		OkdOpenGLShader
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdOpenGLShader_h__
#define __OrkidEngine_OkdOpenGLShader_h__

#include	"Root.h"

#include	ORKID_ENGINE_H(OpenGL/OkdOpenGL_API)
#include	ORKID_ENGINE_H(Shaders/OkdAbstractShader)

class OkdOpenGLShader: public OkdAbstractShader
{
	//template<class T> friend class OkdResourceRef;
	//friend class OkdShaderPtr::OkdResourceRef<OkdOpenGLShader>;
	friend class OkdResourceHandler<OkdOpenGLShader>;

public:
	virtual void	compile();

private:
					OkdOpenGLShader();
	virtual			~OkdOpenGLShader();

	GLuint			_uiShaderId;
};

typedef OkdResourceHandler<OkdOpenGLShader> OkdOpenGLShaderResourceHandler;

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif
