////*****************************************************************************
////
////	Class:		OkdShader
////
////	Created:	2013-08-26
////
////*****************************************************************************
//
//#ifndef __OrkidEngine_OkdShader_h__
//#define __OrkidEngine_OkdShader_h__
//
//#include	"Root.h"
//
//#include	ORKID_ENGINE_H(Resources/OkdAbstractResource)
//#include	ORKID_ENGINE_H(Resources/OkdResourcePtr)
//#include	ORKID_CORE_H(String/OkdString)
//
//enum OrkidShaderType
//{
//	OrkidVertexShader,
//	OrkidFragmentShader,
//	OrkidGeometryShader,
//
//	OrkidShaderUnknown	= 0xFFFFFFFF
//};
//
////class OkdShader;
////typedef OkdResourcePtr<OkdShader, OrkidShader> OkdShaderPtr;
//
//class OkdShader: public OkdAbstractResource
//{
//	//template<class T> friend class OkdResourceRef;
//	//friend class OkdShaderPtr::OkdResourceRef<OkdShader>;
//	//template<class T, OkdResourceType resourceType> friend class OkdResourceHandler;
//	friend class OkdResourceHandler<OkdShader, OrkidShader>;
//	friend class OkdShaderPtr;
//
//public:
//	//virtual void			compile() = 0;
//
//	inline OrkidShaderType	getShaderType() const;
//
//	virtual void			read( OkdFileStream* pStream );
//	virtual void			write( OkdFileStream* pStream );
//
//private:
//							OkdShader();
//	virtual					~OkdShader();
//
//	OrkidShaderType			_eShaderType;
//	OkdString				_strShaderCode;
//};
//
////*****************************************************************************
////	Inline functions declarations
////*****************************************************************************
//
//#endif
