//*****************************************************************************
//
//	Class:		OkdAbstractShader
//
//	Created:	2013-08-26
//
//*****************************************************************************

#ifndef __OrkidEngine_OkdAbstractShader_h__
#define __OrkidEngine_OkdAbstractShader_h__

#include	"Root.h"

#include	ORKID_ENGINE_H(Resources/OkdAbstractResource)
#include	ORKID_ENGINE_H(Resources/OkdResourcePtr)
#include	ORKID_CORE_H(String/OkdString)

enum OrkidShaderType
{
	OrkidVertexShader,
	OrkidFragmentShader,
	OrkidGeometryShader
};

class OkdAbstractShader;
typedef OkdResourcePtr<OkdAbstractShader, OrkidShader> OkdShaderPtr;

class OkdAbstractShader: public OkdAbstractResource
{
	//template<class T> friend class OkdResourceRef;
	//friend class OkdShaderPtr::OkdResourceRef<OkdAbstractShader>;

public:
	virtual void			compile() = 0;

	inline OrkidShaderType	getShadertType() const;

private:
							OkdAbstractShader();
							virtual ~OkdAbstractShader();

	OrkidShaderType			_eShaderType;
	OkdString				_strShaderCode;
};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif
