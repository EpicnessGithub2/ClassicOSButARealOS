/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         classicOS WDM Streaming ActiveMovie Proxy
 * FILE:            dll/directx/ksproxy/classfactory.cpp
 * PURPOSE:         IClassFactory interface
 *
 * PROGRAMMERS:     Johannes Anderwald (johannes.anderwald@reactos.org)
 */
#include "precomp.h"

class CClassFactory : public IClassFactory
{
public:
    STDMETHODIMP QueryInterface( REFIID InterfaceId, PVOID* Interface);

    STDMETHODIMP_(ULONG) AddRef()
    {
        InterlockedIncrement(&m_Ref);
        return m_Ref;
    }
    STDMETHODIMP_(ULONG) Release()
    {
        InterlockedDecrement(&m_Ref);

        if (!m_Ref)
        {
            delete this;
            return 0;
        }
        return m_Ref;
    }

    HRESULT WINAPI CreateInstance(LPUNKNOWN pUnkOuter, REFIID riid, LPVOID *ppvObject);
    HRESULT WINAPI LockServer(BOOL fLock);

    CClassFactory(LPFNCREATEINSTANCE lpfnCI, PLONG pcRefDll, IID *riidInst) : m_Ref(1), m_lpfnCI(lpfnCI), m_IID(riidInst)
    {};

    virtual ~CClassFactory(){};

protected:
    LONG m_Ref;
    LPFNCREATEINSTANCE m_lpfnCI;
    IID * m_IID;
};

HRESULT
WINAPI
CClassFactory::QueryInterface(
    REFIID riid,
    LPVOID *ppvObj)
{
    *ppvObj = NULL;
    if(IsEqualIID(riid, IID_IUnknown) || IsEqualIID(riid, IID_IClassFactory))
    {
        *ppvObj = PVOID(this);
        InterlockedIncrement(&m_Ref);
        return S_OK;
    }
    return E_NOINTERFACE;
}

HRESULT
WINAPI
CClassFactory::CreateInstance(
    LPUNKNOWN pUnkOuter,
    REFIID riid,
    LPVOID *ppvObject)
{
    WCHAR Buffer[MAX_PATH];
    LPOLESTR lpstr;

    *ppvObject = NULL;

    StringFromCLSID(riid, &lpstr);

    swprintf(Buffer, L"riid %s", lpstr);
    OutputDebugStringW(Buffer);


    if ( m_IID == NULL || IsEqualCLSID(riid, *m_IID) || IsEqualCLSID(riid, IID_IUnknown))
    {
        return m_lpfnCI(pUnkOuter, riid, ppvObject);
    }

    return E_NOINTERFACE;
}

HRESULT
WINAPI
CClassFactory::LockServer(
    BOOL fLock)
{
    return E_NOTIMPL;
}

IClassFactory *
CClassFactory_fnConstructor(
    LPFNCREATEINSTANCE lpfnCI,
    PLONG pcRefDll,
    IID * riidInst)
{
    CClassFactory* factory = new CClassFactory(lpfnCI, pcRefDll, riidInst);

    if (!factory)
        return NULL;

    if (pcRefDll)
        InterlockedIncrement(pcRefDll);

    return (LPCLASSFACTORY)factory;
}
