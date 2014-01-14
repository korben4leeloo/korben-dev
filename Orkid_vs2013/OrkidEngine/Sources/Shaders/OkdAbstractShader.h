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
#include	ORKID_CORE_H(String/OkdString)

//enum OrkidShaderType
//{
//	OrkidVertexShader,
//	OrkidFragmentShader,
//	OrkidGeometryShader
//};

enum OrkidShaderType
{
	OrkidShaderTypeVertex,
	OrkidShaderTypeFragment,
	OrkidShaderTypeGeometry
};

class OkdAbstractShader: public OkdAbstractResource
{
public:
							//ORKID_RESOURCE( OrkidShader )

	virtual void			compile() = 0;

	inline OrkidShaderType	getShadertType() const;

	virtual void			read( OkdFileStream* pStream );
	virtual void			write( OkdFileStream* pStream );

protected:
							OkdAbstractShader( const OrkidShaderType eShaderType );
	virtual					~OkdAbstractShader();

	OrkidShaderType			_eShaderType;
	OkdString				_strShaderCode;
};

template<OkdResourceType ResourceType>
class OkdShader: public OkdAbstractShader
{
	friend class OkdResourceManager;

public:
			ORKID_RESOURCE( ResourceType )

protected:
			OkdShader( const OrkidShaderType eShaderType );
	virtual	~OkdShader();
};

typedef OkdShader<OrkidVertexShader>	OkdAbstractVertexShader;
typedef OkdShader<OrkidFragmentShader>	OkdAbstractFragmentShader;
typedef OkdShader<OrkidGeometryShader>	OkdAbstractGeometryShader;

typedef OkdResourcePtr<OkdAbstractVertexShader> OkdVertexShaderPtr;

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

#endif
