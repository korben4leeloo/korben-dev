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
//#include	ORKID_ENGINE_H(Resources/OkdResourcePtr)
#include	ORKID_CORE_H(String/OkdString)

enum OrkidShaderType
{
	OrkidVertexShader,
	OrkidFragmentShader,
	OrkidGeometryShader
};

class OkdAbstractShader: public OkdAbstractResource
{
public:
							ORKID_RESOURCE( OrkidShader )

	virtual void			compile() = 0;

	//inline void				setShadertType( const OrkidShaderType eShaderType );
	inline OrkidShaderType	getShadertType() const;

	virtual void			read( OkdFileStream* pStream );
	virtual void			write( OkdFileStream* pStream );

protected:
							OkdAbstractShader( const OrkidShaderType eShaderType );
	virtual					~OkdAbstractShader();

	OrkidShaderType			_eShaderType;
	OkdString				_strShaderCode;
};

//class OkdShaderPtr: public OkdResourcePtr<OkdAbstractShader>
//{
//public:
//	/*OkdShaderPtr(const OkdString &		strShaderName, 
//				 const OrkidShaderType	eShaderType)
//	{
//		bind( strShaderName );
//		_pResource->_eShaderType = eShaderType;
//	}*/
//
//	void bind( const OkdString& strResourceName, const OrkidShaderType	eShaderType )
//	{
//		bind( strResourceName );
//		_pResource->setShadertType( eShaderType );
//	}
//
//private:
//	void bind( const OkdString& strResourceName )
//	{
//		OkdResourcePtr::bind( strResourceName );
//	}
//};

//*****************************************************************************
//	Inline functions declarations
//*****************************************************************************

////-----------------------------------------------------------------------------
//// Name:		setShadertType
////
//// Created:		2013-08-26
////-----------------------------------------------------------------------------
//void	OkdAbstractShader::setShadertType(const OrkidShaderType	eShaderType)
//{
//	_eShaderType = eShaderType;
//}

#endif
