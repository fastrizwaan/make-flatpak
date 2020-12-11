/*** Autogenerated by WIDL 5.0.3 from wsdbase.idl - Do not edit ***/

#ifdef _WIN32
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif
#include <rpc.h>
#include <rpcndr.h>
#endif

#ifndef COM_NO_WINDOWS_H
#include <windows.h>
#include <ole2.h>
#endif

#ifndef __wsdbase_h__
#define __wsdbase_h__

/* Forward declarations */

#ifndef __IWSDAddress_FWD_DEFINED__
#define __IWSDAddress_FWD_DEFINED__
typedef interface IWSDAddress IWSDAddress;
#ifdef __cplusplus
interface IWSDAddress;
#endif /* __cplusplus */
#endif

#ifndef __IWSDTransportAddress_FWD_DEFINED__
#define __IWSDTransportAddress_FWD_DEFINED__
typedef interface IWSDTransportAddress IWSDTransportAddress;
#ifdef __cplusplus
interface IWSDTransportAddress;
#endif /* __cplusplus */
#endif

#ifndef __IWSDUdpAddress_FWD_DEFINED__
#define __IWSDUdpAddress_FWD_DEFINED__
typedef interface IWSDUdpAddress IWSDUdpAddress;
#ifdef __cplusplus
interface IWSDUdpAddress;
#endif /* __cplusplus */
#endif

#ifndef __IWSDMessageParameters_FWD_DEFINED__
#define __IWSDMessageParameters_FWD_DEFINED__
typedef interface IWSDMessageParameters IWSDMessageParameters;
#ifdef __cplusplus
interface IWSDMessageParameters;
#endif /* __cplusplus */
#endif

#ifndef __IWSDUdpMessageParameters_FWD_DEFINED__
#define __IWSDUdpMessageParameters_FWD_DEFINED__
typedef interface IWSDUdpMessageParameters IWSDUdpMessageParameters;
#ifdef __cplusplus
interface IWSDUdpMessageParameters;
#endif /* __cplusplus */
#endif

/* Headers for imported files */

#include <objidl.h>

#ifdef __cplusplus
extern "C" {
#endif

#define WSDAPI_ADDRESSFAMILY_IPV4 1
#define WSDAPI_ADDRESSFAMILY_IPV6 2
#ifndef __IWSDAddress_FWD_DEFINED__
#define __IWSDAddress_FWD_DEFINED__
typedef interface IWSDAddress IWSDAddress;
#ifdef __cplusplus
interface IWSDAddress;
#endif /* __cplusplus */
#endif

#ifndef __IWSDUdpAddress_FWD_DEFINED__
#define __IWSDUdpAddress_FWD_DEFINED__
typedef interface IWSDUdpAddress IWSDUdpAddress;
#ifdef __cplusplus
interface IWSDUdpAddress;
#endif /* __cplusplus */
#endif

#ifndef __IWSDMessageParameters_FWD_DEFINED__
#define __IWSDMessageParameters_FWD_DEFINED__
typedef interface IWSDMessageParameters IWSDMessageParameters;
#ifdef __cplusplus
interface IWSDMessageParameters;
#endif /* __cplusplus */
#endif

HRESULT WINAPI WSDCreateUdpAddress(IWSDUdpAddress **ppAddress);
#if 1
#ifndef __CSADDR_DEFINED__
typedef struct SOCKADDR_STORAGE SOCKADDR_STORAGE;
#endif
#else
typedef void SOCKADDR_STORAGE;
#endif
/*****************************************************************************
 * IWSDAddress interface
 */
#ifndef __IWSDAddress_INTERFACE_DEFINED__
#define __IWSDAddress_INTERFACE_DEFINED__

DEFINE_GUID(IID_IWSDAddress, 0xb9574c6c, 0x12a6, 0x4f74, 0x93,0xa1, 0x33,0x18,0xff,0x60,0x57,0x59);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("b9574c6c-12a6-4f74-93a1-3318ff605759")
IWSDAddress : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE Serialize(
        LPWSTR pszBuffer,
        DWORD cchLength,
        BOOL fSafe) = 0;

    virtual HRESULT STDMETHODCALLTYPE Deserialize(
        LPCWSTR pszBuffer) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IWSDAddress, 0xb9574c6c, 0x12a6, 0x4f74, 0x93,0xa1, 0x33,0x18,0xff,0x60,0x57,0x59)
#endif
#else
typedef struct IWSDAddressVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IWSDAddress *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IWSDAddress *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IWSDAddress *This);

    /*** IWSDAddress methods ***/
    HRESULT (STDMETHODCALLTYPE *Serialize)(
        IWSDAddress *This,
        LPWSTR pszBuffer,
        DWORD cchLength,
        BOOL fSafe);

    HRESULT (STDMETHODCALLTYPE *Deserialize)(
        IWSDAddress *This,
        LPCWSTR pszBuffer);

    END_INTERFACE
} IWSDAddressVtbl;

interface IWSDAddress {
    CONST_VTBL IWSDAddressVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IWSDAddress_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWSDAddress_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWSDAddress_Release(This) (This)->lpVtbl->Release(This)
/*** IWSDAddress methods ***/
#define IWSDAddress_Serialize(This,pszBuffer,cchLength,fSafe) (This)->lpVtbl->Serialize(This,pszBuffer,cchLength,fSafe)
#define IWSDAddress_Deserialize(This,pszBuffer) (This)->lpVtbl->Deserialize(This,pszBuffer)
#else
/*** IUnknown methods ***/
static FORCEINLINE HRESULT IWSDAddress_QueryInterface(IWSDAddress* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static FORCEINLINE ULONG IWSDAddress_AddRef(IWSDAddress* This) {
    return This->lpVtbl->AddRef(This);
}
static FORCEINLINE ULONG IWSDAddress_Release(IWSDAddress* This) {
    return This->lpVtbl->Release(This);
}
/*** IWSDAddress methods ***/
static FORCEINLINE HRESULT IWSDAddress_Serialize(IWSDAddress* This,LPWSTR pszBuffer,DWORD cchLength,BOOL fSafe) {
    return This->lpVtbl->Serialize(This,pszBuffer,cchLength,fSafe);
}
static FORCEINLINE HRESULT IWSDAddress_Deserialize(IWSDAddress* This,LPCWSTR pszBuffer) {
    return This->lpVtbl->Deserialize(This,pszBuffer);
}
#endif
#endif

#endif


#endif  /* __IWSDAddress_INTERFACE_DEFINED__ */

/*****************************************************************************
 * IWSDTransportAddress interface
 */
#ifndef __IWSDTransportAddress_INTERFACE_DEFINED__
#define __IWSDTransportAddress_INTERFACE_DEFINED__

DEFINE_GUID(IID_IWSDTransportAddress, 0x70d23498, 0x4ee6, 0x4340, 0xa3,0xdf, 0xd8,0x45,0xd2,0x23,0x54,0x67);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("70d23498-4ee6-4340-a3df-d845d2235467")
IWSDTransportAddress : public IWSDAddress
{
    virtual HRESULT STDMETHODCALLTYPE GetPort(
        WORD *pwPort) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetPort(
        WORD wPort) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetTransportAddress(
        LPCWSTR *ppszAddress) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetTransportAddressEx(
        BOOL fSafe,
        LPCWSTR *ppszAddress) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetTransportAddress(
        LPCWSTR pszAddress) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IWSDTransportAddress, 0x70d23498, 0x4ee6, 0x4340, 0xa3,0xdf, 0xd8,0x45,0xd2,0x23,0x54,0x67)
#endif
#else
typedef struct IWSDTransportAddressVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IWSDTransportAddress *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IWSDTransportAddress *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IWSDTransportAddress *This);

    /*** IWSDAddress methods ***/
    HRESULT (STDMETHODCALLTYPE *Serialize)(
        IWSDTransportAddress *This,
        LPWSTR pszBuffer,
        DWORD cchLength,
        BOOL fSafe);

    HRESULT (STDMETHODCALLTYPE *Deserialize)(
        IWSDTransportAddress *This,
        LPCWSTR pszBuffer);

    /*** IWSDTransportAddress methods ***/
    HRESULT (STDMETHODCALLTYPE *GetPort)(
        IWSDTransportAddress *This,
        WORD *pwPort);

    HRESULT (STDMETHODCALLTYPE *SetPort)(
        IWSDTransportAddress *This,
        WORD wPort);

    HRESULT (STDMETHODCALLTYPE *GetTransportAddress)(
        IWSDTransportAddress *This,
        LPCWSTR *ppszAddress);

    HRESULT (STDMETHODCALLTYPE *GetTransportAddressEx)(
        IWSDTransportAddress *This,
        BOOL fSafe,
        LPCWSTR *ppszAddress);

    HRESULT (STDMETHODCALLTYPE *SetTransportAddress)(
        IWSDTransportAddress *This,
        LPCWSTR pszAddress);

    END_INTERFACE
} IWSDTransportAddressVtbl;

interface IWSDTransportAddress {
    CONST_VTBL IWSDTransportAddressVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IWSDTransportAddress_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWSDTransportAddress_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWSDTransportAddress_Release(This) (This)->lpVtbl->Release(This)
/*** IWSDAddress methods ***/
#define IWSDTransportAddress_Serialize(This,pszBuffer,cchLength,fSafe) (This)->lpVtbl->Serialize(This,pszBuffer,cchLength,fSafe)
#define IWSDTransportAddress_Deserialize(This,pszBuffer) (This)->lpVtbl->Deserialize(This,pszBuffer)
/*** IWSDTransportAddress methods ***/
#define IWSDTransportAddress_GetPort(This,pwPort) (This)->lpVtbl->GetPort(This,pwPort)
#define IWSDTransportAddress_SetPort(This,wPort) (This)->lpVtbl->SetPort(This,wPort)
#define IWSDTransportAddress_GetTransportAddress(This,ppszAddress) (This)->lpVtbl->GetTransportAddress(This,ppszAddress)
#define IWSDTransportAddress_GetTransportAddressEx(This,fSafe,ppszAddress) (This)->lpVtbl->GetTransportAddressEx(This,fSafe,ppszAddress)
#define IWSDTransportAddress_SetTransportAddress(This,pszAddress) (This)->lpVtbl->SetTransportAddress(This,pszAddress)
#else
/*** IUnknown methods ***/
static FORCEINLINE HRESULT IWSDTransportAddress_QueryInterface(IWSDTransportAddress* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static FORCEINLINE ULONG IWSDTransportAddress_AddRef(IWSDTransportAddress* This) {
    return This->lpVtbl->AddRef(This);
}
static FORCEINLINE ULONG IWSDTransportAddress_Release(IWSDTransportAddress* This) {
    return This->lpVtbl->Release(This);
}
/*** IWSDAddress methods ***/
static FORCEINLINE HRESULT IWSDTransportAddress_Serialize(IWSDTransportAddress* This,LPWSTR pszBuffer,DWORD cchLength,BOOL fSafe) {
    return This->lpVtbl->Serialize(This,pszBuffer,cchLength,fSafe);
}
static FORCEINLINE HRESULT IWSDTransportAddress_Deserialize(IWSDTransportAddress* This,LPCWSTR pszBuffer) {
    return This->lpVtbl->Deserialize(This,pszBuffer);
}
/*** IWSDTransportAddress methods ***/
static FORCEINLINE HRESULT IWSDTransportAddress_GetPort(IWSDTransportAddress* This,WORD *pwPort) {
    return This->lpVtbl->GetPort(This,pwPort);
}
static FORCEINLINE HRESULT IWSDTransportAddress_SetPort(IWSDTransportAddress* This,WORD wPort) {
    return This->lpVtbl->SetPort(This,wPort);
}
static FORCEINLINE HRESULT IWSDTransportAddress_GetTransportAddress(IWSDTransportAddress* This,LPCWSTR *ppszAddress) {
    return This->lpVtbl->GetTransportAddress(This,ppszAddress);
}
static FORCEINLINE HRESULT IWSDTransportAddress_GetTransportAddressEx(IWSDTransportAddress* This,BOOL fSafe,LPCWSTR *ppszAddress) {
    return This->lpVtbl->GetTransportAddressEx(This,fSafe,ppszAddress);
}
static FORCEINLINE HRESULT IWSDTransportAddress_SetTransportAddress(IWSDTransportAddress* This,LPCWSTR pszAddress) {
    return This->lpVtbl->SetTransportAddress(This,pszAddress);
}
#endif
#endif

#endif


#endif  /* __IWSDTransportAddress_INTERFACE_DEFINED__ */

typedef enum _WSDUdpMessageType {
    ONE_WAY = 0,
    TWO_WAY = 1
} WSDUdpMessageType;
/*****************************************************************************
 * IWSDUdpAddress interface
 */
#ifndef __IWSDUdpAddress_INTERFACE_DEFINED__
#define __IWSDUdpAddress_INTERFACE_DEFINED__

DEFINE_GUID(IID_IWSDUdpAddress, 0x74d6124a, 0xa441, 0x4f78, 0xa1,0xeb, 0x97,0xa8,0xd1,0x99,0x68,0x93);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("74d6124a-a441-4f78-a1eb-97a8d1996893")
IWSDUdpAddress : public IWSDTransportAddress
{
    virtual HRESULT STDMETHODCALLTYPE SetSockaddr(
        const SOCKADDR_STORAGE *pSockAddr) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetSockaddr(
        SOCKADDR_STORAGE *pSockAddr) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetExclusive(
        BOOL fExclusive) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetExclusive(
        ) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetMessageType(
        WSDUdpMessageType messageType) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetMessageType(
        WSDUdpMessageType *pMessageType) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetTTL(
        DWORD dwTTL) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetTTL(
        DWORD *pdwTTL) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetAlias(
        const GUID *pAlias) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetAlias(
        GUID *pAlias) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IWSDUdpAddress, 0x74d6124a, 0xa441, 0x4f78, 0xa1,0xeb, 0x97,0xa8,0xd1,0x99,0x68,0x93)
#endif
#else
typedef struct IWSDUdpAddressVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IWSDUdpAddress *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IWSDUdpAddress *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IWSDUdpAddress *This);

    /*** IWSDAddress methods ***/
    HRESULT (STDMETHODCALLTYPE *Serialize)(
        IWSDUdpAddress *This,
        LPWSTR pszBuffer,
        DWORD cchLength,
        BOOL fSafe);

    HRESULT (STDMETHODCALLTYPE *Deserialize)(
        IWSDUdpAddress *This,
        LPCWSTR pszBuffer);

    /*** IWSDTransportAddress methods ***/
    HRESULT (STDMETHODCALLTYPE *GetPort)(
        IWSDUdpAddress *This,
        WORD *pwPort);

    HRESULT (STDMETHODCALLTYPE *SetPort)(
        IWSDUdpAddress *This,
        WORD wPort);

    HRESULT (STDMETHODCALLTYPE *GetTransportAddress)(
        IWSDUdpAddress *This,
        LPCWSTR *ppszAddress);

    HRESULT (STDMETHODCALLTYPE *GetTransportAddressEx)(
        IWSDUdpAddress *This,
        BOOL fSafe,
        LPCWSTR *ppszAddress);

    HRESULT (STDMETHODCALLTYPE *SetTransportAddress)(
        IWSDUdpAddress *This,
        LPCWSTR pszAddress);

    /*** IWSDUdpAddress methods ***/
    HRESULT (STDMETHODCALLTYPE *SetSockaddr)(
        IWSDUdpAddress *This,
        const SOCKADDR_STORAGE *pSockAddr);

    HRESULT (STDMETHODCALLTYPE *GetSockaddr)(
        IWSDUdpAddress *This,
        SOCKADDR_STORAGE *pSockAddr);

    HRESULT (STDMETHODCALLTYPE *SetExclusive)(
        IWSDUdpAddress *This,
        BOOL fExclusive);

    HRESULT (STDMETHODCALLTYPE *GetExclusive)(
        IWSDUdpAddress *This);

    HRESULT (STDMETHODCALLTYPE *SetMessageType)(
        IWSDUdpAddress *This,
        WSDUdpMessageType messageType);

    HRESULT (STDMETHODCALLTYPE *GetMessageType)(
        IWSDUdpAddress *This,
        WSDUdpMessageType *pMessageType);

    HRESULT (STDMETHODCALLTYPE *SetTTL)(
        IWSDUdpAddress *This,
        DWORD dwTTL);

    HRESULT (STDMETHODCALLTYPE *GetTTL)(
        IWSDUdpAddress *This,
        DWORD *pdwTTL);

    HRESULT (STDMETHODCALLTYPE *SetAlias)(
        IWSDUdpAddress *This,
        const GUID *pAlias);

    HRESULT (STDMETHODCALLTYPE *GetAlias)(
        IWSDUdpAddress *This,
        GUID *pAlias);

    END_INTERFACE
} IWSDUdpAddressVtbl;

interface IWSDUdpAddress {
    CONST_VTBL IWSDUdpAddressVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IWSDUdpAddress_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWSDUdpAddress_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWSDUdpAddress_Release(This) (This)->lpVtbl->Release(This)
/*** IWSDAddress methods ***/
#define IWSDUdpAddress_Serialize(This,pszBuffer,cchLength,fSafe) (This)->lpVtbl->Serialize(This,pszBuffer,cchLength,fSafe)
#define IWSDUdpAddress_Deserialize(This,pszBuffer) (This)->lpVtbl->Deserialize(This,pszBuffer)
/*** IWSDTransportAddress methods ***/
#define IWSDUdpAddress_GetPort(This,pwPort) (This)->lpVtbl->GetPort(This,pwPort)
#define IWSDUdpAddress_SetPort(This,wPort) (This)->lpVtbl->SetPort(This,wPort)
#define IWSDUdpAddress_GetTransportAddress(This,ppszAddress) (This)->lpVtbl->GetTransportAddress(This,ppszAddress)
#define IWSDUdpAddress_GetTransportAddressEx(This,fSafe,ppszAddress) (This)->lpVtbl->GetTransportAddressEx(This,fSafe,ppszAddress)
#define IWSDUdpAddress_SetTransportAddress(This,pszAddress) (This)->lpVtbl->SetTransportAddress(This,pszAddress)
/*** IWSDUdpAddress methods ***/
#define IWSDUdpAddress_SetSockaddr(This,pSockAddr) (This)->lpVtbl->SetSockaddr(This,pSockAddr)
#define IWSDUdpAddress_GetSockaddr(This,pSockAddr) (This)->lpVtbl->GetSockaddr(This,pSockAddr)
#define IWSDUdpAddress_SetExclusive(This,fExclusive) (This)->lpVtbl->SetExclusive(This,fExclusive)
#define IWSDUdpAddress_GetExclusive(This) (This)->lpVtbl->GetExclusive(This)
#define IWSDUdpAddress_SetMessageType(This,messageType) (This)->lpVtbl->SetMessageType(This,messageType)
#define IWSDUdpAddress_GetMessageType(This,pMessageType) (This)->lpVtbl->GetMessageType(This,pMessageType)
#define IWSDUdpAddress_SetTTL(This,dwTTL) (This)->lpVtbl->SetTTL(This,dwTTL)
#define IWSDUdpAddress_GetTTL(This,pdwTTL) (This)->lpVtbl->GetTTL(This,pdwTTL)
#define IWSDUdpAddress_SetAlias(This,pAlias) (This)->lpVtbl->SetAlias(This,pAlias)
#define IWSDUdpAddress_GetAlias(This,pAlias) (This)->lpVtbl->GetAlias(This,pAlias)
#else
/*** IUnknown methods ***/
static FORCEINLINE HRESULT IWSDUdpAddress_QueryInterface(IWSDUdpAddress* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static FORCEINLINE ULONG IWSDUdpAddress_AddRef(IWSDUdpAddress* This) {
    return This->lpVtbl->AddRef(This);
}
static FORCEINLINE ULONG IWSDUdpAddress_Release(IWSDUdpAddress* This) {
    return This->lpVtbl->Release(This);
}
/*** IWSDAddress methods ***/
static FORCEINLINE HRESULT IWSDUdpAddress_Serialize(IWSDUdpAddress* This,LPWSTR pszBuffer,DWORD cchLength,BOOL fSafe) {
    return This->lpVtbl->Serialize(This,pszBuffer,cchLength,fSafe);
}
static FORCEINLINE HRESULT IWSDUdpAddress_Deserialize(IWSDUdpAddress* This,LPCWSTR pszBuffer) {
    return This->lpVtbl->Deserialize(This,pszBuffer);
}
/*** IWSDTransportAddress methods ***/
static FORCEINLINE HRESULT IWSDUdpAddress_GetPort(IWSDUdpAddress* This,WORD *pwPort) {
    return This->lpVtbl->GetPort(This,pwPort);
}
static FORCEINLINE HRESULT IWSDUdpAddress_SetPort(IWSDUdpAddress* This,WORD wPort) {
    return This->lpVtbl->SetPort(This,wPort);
}
static FORCEINLINE HRESULT IWSDUdpAddress_GetTransportAddress(IWSDUdpAddress* This,LPCWSTR *ppszAddress) {
    return This->lpVtbl->GetTransportAddress(This,ppszAddress);
}
static FORCEINLINE HRESULT IWSDUdpAddress_GetTransportAddressEx(IWSDUdpAddress* This,BOOL fSafe,LPCWSTR *ppszAddress) {
    return This->lpVtbl->GetTransportAddressEx(This,fSafe,ppszAddress);
}
static FORCEINLINE HRESULT IWSDUdpAddress_SetTransportAddress(IWSDUdpAddress* This,LPCWSTR pszAddress) {
    return This->lpVtbl->SetTransportAddress(This,pszAddress);
}
/*** IWSDUdpAddress methods ***/
static FORCEINLINE HRESULT IWSDUdpAddress_SetSockaddr(IWSDUdpAddress* This,const SOCKADDR_STORAGE *pSockAddr) {
    return This->lpVtbl->SetSockaddr(This,pSockAddr);
}
static FORCEINLINE HRESULT IWSDUdpAddress_GetSockaddr(IWSDUdpAddress* This,SOCKADDR_STORAGE *pSockAddr) {
    return This->lpVtbl->GetSockaddr(This,pSockAddr);
}
static FORCEINLINE HRESULT IWSDUdpAddress_SetExclusive(IWSDUdpAddress* This,BOOL fExclusive) {
    return This->lpVtbl->SetExclusive(This,fExclusive);
}
static FORCEINLINE HRESULT IWSDUdpAddress_GetExclusive(IWSDUdpAddress* This) {
    return This->lpVtbl->GetExclusive(This);
}
static FORCEINLINE HRESULT IWSDUdpAddress_SetMessageType(IWSDUdpAddress* This,WSDUdpMessageType messageType) {
    return This->lpVtbl->SetMessageType(This,messageType);
}
static FORCEINLINE HRESULT IWSDUdpAddress_GetMessageType(IWSDUdpAddress* This,WSDUdpMessageType *pMessageType) {
    return This->lpVtbl->GetMessageType(This,pMessageType);
}
static FORCEINLINE HRESULT IWSDUdpAddress_SetTTL(IWSDUdpAddress* This,DWORD dwTTL) {
    return This->lpVtbl->SetTTL(This,dwTTL);
}
static FORCEINLINE HRESULT IWSDUdpAddress_GetTTL(IWSDUdpAddress* This,DWORD *pdwTTL) {
    return This->lpVtbl->GetTTL(This,pdwTTL);
}
static FORCEINLINE HRESULT IWSDUdpAddress_SetAlias(IWSDUdpAddress* This,const GUID *pAlias) {
    return This->lpVtbl->SetAlias(This,pAlias);
}
static FORCEINLINE HRESULT IWSDUdpAddress_GetAlias(IWSDUdpAddress* This,GUID *pAlias) {
    return This->lpVtbl->GetAlias(This,pAlias);
}
#endif
#endif

#endif


#endif  /* __IWSDUdpAddress_INTERFACE_DEFINED__ */

/*****************************************************************************
 * IWSDMessageParameters interface
 */
#ifndef __IWSDMessageParameters_INTERFACE_DEFINED__
#define __IWSDMessageParameters_INTERFACE_DEFINED__

DEFINE_GUID(IID_IWSDMessageParameters, 0x1fafe8a2, 0xe6fc, 0x4b80, 0xb6,0xcf, 0xb7,0xd4,0x5c,0x41,0x6d,0x7c);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("1fafe8a2-e6fc-4b80-b6cf-b7d45c416d7c")
IWSDMessageParameters : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE GetLocalAddress(
        IWSDAddress **ppAddress) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetLocalAddress(
        IWSDAddress *pAddress) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetRemoteAddress(
        IWSDAddress **ppAddress) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetRemoteAddress(
        IWSDAddress *pAddress) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetLowerParameters(
        IWSDMessageParameters **ppTxParams) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IWSDMessageParameters, 0x1fafe8a2, 0xe6fc, 0x4b80, 0xb6,0xcf, 0xb7,0xd4,0x5c,0x41,0x6d,0x7c)
#endif
#else
typedef struct IWSDMessageParametersVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IWSDMessageParameters *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IWSDMessageParameters *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IWSDMessageParameters *This);

    /*** IWSDMessageParameters methods ***/
    HRESULT (STDMETHODCALLTYPE *GetLocalAddress)(
        IWSDMessageParameters *This,
        IWSDAddress **ppAddress);

    HRESULT (STDMETHODCALLTYPE *SetLocalAddress)(
        IWSDMessageParameters *This,
        IWSDAddress *pAddress);

    HRESULT (STDMETHODCALLTYPE *GetRemoteAddress)(
        IWSDMessageParameters *This,
        IWSDAddress **ppAddress);

    HRESULT (STDMETHODCALLTYPE *SetRemoteAddress)(
        IWSDMessageParameters *This,
        IWSDAddress *pAddress);

    HRESULT (STDMETHODCALLTYPE *GetLowerParameters)(
        IWSDMessageParameters *This,
        IWSDMessageParameters **ppTxParams);

    END_INTERFACE
} IWSDMessageParametersVtbl;

interface IWSDMessageParameters {
    CONST_VTBL IWSDMessageParametersVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IWSDMessageParameters_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWSDMessageParameters_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWSDMessageParameters_Release(This) (This)->lpVtbl->Release(This)
/*** IWSDMessageParameters methods ***/
#define IWSDMessageParameters_GetLocalAddress(This,ppAddress) (This)->lpVtbl->GetLocalAddress(This,ppAddress)
#define IWSDMessageParameters_SetLocalAddress(This,pAddress) (This)->lpVtbl->SetLocalAddress(This,pAddress)
#define IWSDMessageParameters_GetRemoteAddress(This,ppAddress) (This)->lpVtbl->GetRemoteAddress(This,ppAddress)
#define IWSDMessageParameters_SetRemoteAddress(This,pAddress) (This)->lpVtbl->SetRemoteAddress(This,pAddress)
#define IWSDMessageParameters_GetLowerParameters(This,ppTxParams) (This)->lpVtbl->GetLowerParameters(This,ppTxParams)
#else
/*** IUnknown methods ***/
static FORCEINLINE HRESULT IWSDMessageParameters_QueryInterface(IWSDMessageParameters* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static FORCEINLINE ULONG IWSDMessageParameters_AddRef(IWSDMessageParameters* This) {
    return This->lpVtbl->AddRef(This);
}
static FORCEINLINE ULONG IWSDMessageParameters_Release(IWSDMessageParameters* This) {
    return This->lpVtbl->Release(This);
}
/*** IWSDMessageParameters methods ***/
static FORCEINLINE HRESULT IWSDMessageParameters_GetLocalAddress(IWSDMessageParameters* This,IWSDAddress **ppAddress) {
    return This->lpVtbl->GetLocalAddress(This,ppAddress);
}
static FORCEINLINE HRESULT IWSDMessageParameters_SetLocalAddress(IWSDMessageParameters* This,IWSDAddress *pAddress) {
    return This->lpVtbl->SetLocalAddress(This,pAddress);
}
static FORCEINLINE HRESULT IWSDMessageParameters_GetRemoteAddress(IWSDMessageParameters* This,IWSDAddress **ppAddress) {
    return This->lpVtbl->GetRemoteAddress(This,ppAddress);
}
static FORCEINLINE HRESULT IWSDMessageParameters_SetRemoteAddress(IWSDMessageParameters* This,IWSDAddress *pAddress) {
    return This->lpVtbl->SetRemoteAddress(This,pAddress);
}
static FORCEINLINE HRESULT IWSDMessageParameters_GetLowerParameters(IWSDMessageParameters* This,IWSDMessageParameters **ppTxParams) {
    return This->lpVtbl->GetLowerParameters(This,ppTxParams);
}
#endif
#endif

#endif


#endif  /* __IWSDMessageParameters_INTERFACE_DEFINED__ */

HRESULT WINAPI WSDCreateUdpMessageParameters(IWSDUdpMessageParameters **ppTxParams);
typedef struct _WSDUdpRetransmitParams {
    ULONG ulSendDelay;
    ULONG ulRepeat;
    ULONG ulRepeatMinDelay;
    ULONG ulRepeatMaxDelay;
    ULONG ulRepeatUpperDelay;
} WSDUdpRetransmitParams;
/*****************************************************************************
 * IWSDUdpMessageParameters interface
 */
#ifndef __IWSDUdpMessageParameters_INTERFACE_DEFINED__
#define __IWSDUdpMessageParameters_INTERFACE_DEFINED__

DEFINE_GUID(IID_IWSDUdpMessageParameters, 0x9934149f, 0x8f0c, 0x447b, 0xaa,0x0b, 0x73,0x12,0x4b,0x0c,0xa7,0xf0);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("9934149f-8f0c-447b-aa0b-73124b0ca7f0")
IWSDUdpMessageParameters : public IWSDMessageParameters
{
    virtual HRESULT STDMETHODCALLTYPE SetRetransmitParams(
        const WSDUdpRetransmitParams *pParams) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetRetransmitParams(
        WSDUdpRetransmitParams *pParams) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IWSDUdpMessageParameters, 0x9934149f, 0x8f0c, 0x447b, 0xaa,0x0b, 0x73,0x12,0x4b,0x0c,0xa7,0xf0)
#endif
#else
typedef struct IWSDUdpMessageParametersVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IWSDUdpMessageParameters *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IWSDUdpMessageParameters *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IWSDUdpMessageParameters *This);

    /*** IWSDMessageParameters methods ***/
    HRESULT (STDMETHODCALLTYPE *GetLocalAddress)(
        IWSDUdpMessageParameters *This,
        IWSDAddress **ppAddress);

    HRESULT (STDMETHODCALLTYPE *SetLocalAddress)(
        IWSDUdpMessageParameters *This,
        IWSDAddress *pAddress);

    HRESULT (STDMETHODCALLTYPE *GetRemoteAddress)(
        IWSDUdpMessageParameters *This,
        IWSDAddress **ppAddress);

    HRESULT (STDMETHODCALLTYPE *SetRemoteAddress)(
        IWSDUdpMessageParameters *This,
        IWSDAddress *pAddress);

    HRESULT (STDMETHODCALLTYPE *GetLowerParameters)(
        IWSDUdpMessageParameters *This,
        IWSDMessageParameters **ppTxParams);

    /*** IWSDUdpMessageParameters methods ***/
    HRESULT (STDMETHODCALLTYPE *SetRetransmitParams)(
        IWSDUdpMessageParameters *This,
        const WSDUdpRetransmitParams *pParams);

    HRESULT (STDMETHODCALLTYPE *GetRetransmitParams)(
        IWSDUdpMessageParameters *This,
        WSDUdpRetransmitParams *pParams);

    END_INTERFACE
} IWSDUdpMessageParametersVtbl;

interface IWSDUdpMessageParameters {
    CONST_VTBL IWSDUdpMessageParametersVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IWSDUdpMessageParameters_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWSDUdpMessageParameters_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWSDUdpMessageParameters_Release(This) (This)->lpVtbl->Release(This)
/*** IWSDMessageParameters methods ***/
#define IWSDUdpMessageParameters_GetLocalAddress(This,ppAddress) (This)->lpVtbl->GetLocalAddress(This,ppAddress)
#define IWSDUdpMessageParameters_SetLocalAddress(This,pAddress) (This)->lpVtbl->SetLocalAddress(This,pAddress)
#define IWSDUdpMessageParameters_GetRemoteAddress(This,ppAddress) (This)->lpVtbl->GetRemoteAddress(This,ppAddress)
#define IWSDUdpMessageParameters_SetRemoteAddress(This,pAddress) (This)->lpVtbl->SetRemoteAddress(This,pAddress)
#define IWSDUdpMessageParameters_GetLowerParameters(This,ppTxParams) (This)->lpVtbl->GetLowerParameters(This,ppTxParams)
/*** IWSDUdpMessageParameters methods ***/
#define IWSDUdpMessageParameters_SetRetransmitParams(This,pParams) (This)->lpVtbl->SetRetransmitParams(This,pParams)
#define IWSDUdpMessageParameters_GetRetransmitParams(This,pParams) (This)->lpVtbl->GetRetransmitParams(This,pParams)
#else
/*** IUnknown methods ***/
static FORCEINLINE HRESULT IWSDUdpMessageParameters_QueryInterface(IWSDUdpMessageParameters* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static FORCEINLINE ULONG IWSDUdpMessageParameters_AddRef(IWSDUdpMessageParameters* This) {
    return This->lpVtbl->AddRef(This);
}
static FORCEINLINE ULONG IWSDUdpMessageParameters_Release(IWSDUdpMessageParameters* This) {
    return This->lpVtbl->Release(This);
}
/*** IWSDMessageParameters methods ***/
static FORCEINLINE HRESULT IWSDUdpMessageParameters_GetLocalAddress(IWSDUdpMessageParameters* This,IWSDAddress **ppAddress) {
    return This->lpVtbl->GetLocalAddress(This,ppAddress);
}
static FORCEINLINE HRESULT IWSDUdpMessageParameters_SetLocalAddress(IWSDUdpMessageParameters* This,IWSDAddress *pAddress) {
    return This->lpVtbl->SetLocalAddress(This,pAddress);
}
static FORCEINLINE HRESULT IWSDUdpMessageParameters_GetRemoteAddress(IWSDUdpMessageParameters* This,IWSDAddress **ppAddress) {
    return This->lpVtbl->GetRemoteAddress(This,ppAddress);
}
static FORCEINLINE HRESULT IWSDUdpMessageParameters_SetRemoteAddress(IWSDUdpMessageParameters* This,IWSDAddress *pAddress) {
    return This->lpVtbl->SetRemoteAddress(This,pAddress);
}
static FORCEINLINE HRESULT IWSDUdpMessageParameters_GetLowerParameters(IWSDUdpMessageParameters* This,IWSDMessageParameters **ppTxParams) {
    return This->lpVtbl->GetLowerParameters(This,ppTxParams);
}
/*** IWSDUdpMessageParameters methods ***/
static FORCEINLINE HRESULT IWSDUdpMessageParameters_SetRetransmitParams(IWSDUdpMessageParameters* This,const WSDUdpRetransmitParams *pParams) {
    return This->lpVtbl->SetRetransmitParams(This,pParams);
}
static FORCEINLINE HRESULT IWSDUdpMessageParameters_GetRetransmitParams(IWSDUdpMessageParameters* This,WSDUdpRetransmitParams *pParams) {
    return This->lpVtbl->GetRetransmitParams(This,pParams);
}
#endif
#endif

#endif


#endif  /* __IWSDUdpMessageParameters_INTERFACE_DEFINED__ */

/* Begin additional prototypes for all interfaces */


/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __wsdbase_h__ */
