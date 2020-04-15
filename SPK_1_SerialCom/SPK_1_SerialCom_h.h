

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Thu Dec 05 20:01:48 2019
 */
/* Compiler settings for SPK_1_SerialCom.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __SPK_1_SerialCom_h_h__
#define __SPK_1_SerialCom_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISPK_1_SerialCom_FWD_DEFINED__
#define __ISPK_1_SerialCom_FWD_DEFINED__
typedef interface ISPK_1_SerialCom ISPK_1_SerialCom;

#endif 	/* __ISPK_1_SerialCom_FWD_DEFINED__ */


#ifndef __SPK_1_SerialCom_FWD_DEFINED__
#define __SPK_1_SerialCom_FWD_DEFINED__

#ifdef __cplusplus
typedef class SPK_1_SerialCom SPK_1_SerialCom;
#else
typedef struct SPK_1_SerialCom SPK_1_SerialCom;
#endif /* __cplusplus */

#endif 	/* __SPK_1_SerialCom_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __SPK_1_SerialCom_LIBRARY_DEFINED__
#define __SPK_1_SerialCom_LIBRARY_DEFINED__

/* library SPK_1_SerialCom */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_SPK_1_SerialCom;

#ifndef __ISPK_1_SerialCom_DISPINTERFACE_DEFINED__
#define __ISPK_1_SerialCom_DISPINTERFACE_DEFINED__

/* dispinterface ISPK_1_SerialCom */
/* [uuid] */ 


EXTERN_C const IID DIID_ISPK_1_SerialCom;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("8C40C9C0-1E15-4B1A-B158-61F9D3C2F369")
    ISPK_1_SerialCom : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ISPK_1_SerialComVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISPK_1_SerialCom * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISPK_1_SerialCom * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISPK_1_SerialCom * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISPK_1_SerialCom * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISPK_1_SerialCom * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISPK_1_SerialCom * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISPK_1_SerialCom * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } ISPK_1_SerialComVtbl;

    interface ISPK_1_SerialCom
    {
        CONST_VTBL struct ISPK_1_SerialComVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISPK_1_SerialCom_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISPK_1_SerialCom_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISPK_1_SerialCom_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISPK_1_SerialCom_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISPK_1_SerialCom_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISPK_1_SerialCom_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISPK_1_SerialCom_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ISPK_1_SerialCom_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SPK_1_SerialCom;

#ifdef __cplusplus

class DECLSPEC_UUID("220D4446-60C3-4481-881A-06C32B40CF0B")
SPK_1_SerialCom;
#endif
#endif /* __SPK_1_SerialCom_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


