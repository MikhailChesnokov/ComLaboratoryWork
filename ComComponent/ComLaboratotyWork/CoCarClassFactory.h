#pragma once
#include <windows.h>

class CoCarClassFactory :
	IClassFactory
{
public:
	CoCarClassFactory();
	virtual ~CoCarClassFactory();
	//CoCarClassFactory(const CoCarClassFactory& factory) = delete;
	//CoCarClassFactory(const CoCarClassFactory&& factory) = delete;
	//CoCarClassFactory operator=(const CoCarClassFactory& factory) = delete;
	//CoCarClassFactory operator=(const CoCarClassFactory&& factory) = delete;

	// IUnknown
	STDMETHODIMP QueryInterface(const IID& riid, void** ppvObject) override;
	STDMETHODIMP_(DWORD) AddRef() override;
	STDMETHODIMP_(DWORD) Release() override;

	// ICF
	STDMETHODIMP LockServer(BOOL fLock) override;
	STDMETHODIMP CreateInstance(IUnknown* pUnkOuter, const IID& riid, void** ppvObject) override;
private:
	DWORD m_refCount;
};
