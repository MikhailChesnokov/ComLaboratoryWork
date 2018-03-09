#include <windows.h>
#include "CoCarClassFactory.h"
#include "iid.h"

ULONG g_lockCount = 0;
ULONG g_objCount = 0;

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, void **ppv)
{
	CoCarClassFactory *pCFact = nullptr;

	if (rclsid != CLSID_CoCar)
	{
		return CLASS_E_CLASSNOTAVAILABLE;
	}

	pCFact = new CoCarClassFactory;

	const HRESULT hr = pCFact->QueryInterface(riid, ppv);

	if (FAILED(hr))
	{
		delete pCFact;
	}

	return hr;
}

STDAPI DllCanUnloadNow()
{
	if (g_lockCount == 0 && g_objCount == 0)
	{
		return S_OK;
	}

	return S_FALSE;
}