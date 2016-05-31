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
public:
	virtual void	compile();

private:
					OkdOpenGLShader();
	virtual			~OkdOpenGLShader();

	GLuint			_uiShaderId;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif
