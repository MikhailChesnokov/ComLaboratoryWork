#include "CoCarClassFactory.h"
#include "CoCar.h"

extern DWORD g_lockCount;
extern DWORD g_objCount;

CoCarClassFactory::CoCarClassFactory(): m_refCount(0)
{
	g_objCount++;
}

CoCarClassFactory::~CoCarClassFactory()
{
	g_objCount--;
}

HRESULT CoCarClassFactory::QueryInterface(const IID& riid, void** ppvObject)
{
	if (riid == IID_IUnknown)
	{
		*ppvObject = static_cast<IUnknown*>(this);
	}
	else if (riid == IID_IClassFactory)
	{
		*ppvObject = static_cast<IClassFactory*>(this);
	}
	else
	{
		*ppvObject = nullptr;
		return E_NOINTERFACE;
	}

	static_cast<IUnknown*>(*ppvObject)->AddRef();

	return S_OK;
}

DWORD CoCarClassFactory::AddRef()
{
	return ++m_refCount;
}

DWORD CoCarClassFactory::Release()
{
	if (--m_refCount == 0)
	{
		delete this;
		return 0;
	}

	return m_refCount;
}

HRESULT CoCarClassFactory::LockServer(BOOL fLock)
{
	if (fLock)
	{
		++g_lockCount;
	}
	else
	{
		--g_lockCount;
	}

	return S_OK;
}

HRESULT CoCarClassFactory::CreateInstance(IUnknown* pUnkOuter, const IID& riid, void** ppvObject)
{
	if (pUnkOuter != nullptr)
	{
		return CLASS_E_NOAGGREGATION;
	}

	CoCar* pCarObj = new CoCar;

	const HRESULT hr = pCarObj->QueryInterface(riid, ppvObject);

	if (FAILED(hr))
	{
		delete pCarObj;
	}

	return hr;
}