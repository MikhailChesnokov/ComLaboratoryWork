#include "iid.cpp"
#include "iid.h"
#include "interfaces.h"

#include <iostream>

int main()
{
	CoInitialize(nullptr);

	IClassFactory *pCF = nullptr;
	ICreateCar *pICreateCar = nullptr;
	IStats *pStats = nullptr;
	IEngine *pEngine = nullptr;

	HRESULT hr = CoGetClassObject(CLSID_CoCar, CLSCTX_INPROC_SERVER, nullptr, IID_IClassFactory, reinterpret_cast<void**>(&pCF));

	if (hr == REGDB_E_CLASSNOTREG)
	{
		std::cout << "Error: the class is not registered." << std::endl;
		return -1;
	}

	hr = pCF->CreateInstance(nullptr, IID_ICreateCar, reinterpret_cast<void**>(&pICreateCar));

	pCF->Release();

	if (SUCCEEDED(hr))
	{
		pICreateCar->SetMaxSpeed(30);
		const BSTR carName = SysAllocString(L"Shazzam!");
		pICreateCar->SetCarName(carName);
		SysFreeString(carName);

		hr = pICreateCar->QueryInterface(IID_IStats, reinterpret_cast<void**>(&pStats));
		pICreateCar->Release();
	}

	if (SUCCEEDED(hr))
	{
		pStats->DisplayStats();
		hr = pStats->QueryInterface(IID_IEngine, reinterpret_cast<void**>(&pEngine));
	}

	if (SUCCEEDED(hr))
	{
		int curSp = 0;
		int maxSp = 0;
		pEngine->GetMaxSpeed(&maxSp);

		do
		{
			pEngine->SpeedUp();
			pEngine->GetCurSpeed(&curSp);
			std::cout << "Speed is: " << curSp << std::endl;
		} while (curSp <= maxSp);

		char buff[80];
		BSTR bstr;
		pStats->GetCarName(&bstr);
		WideCharToMultiByte(CP_ACP, NULL, bstr, -1, buff, 80, nullptr, nullptr);
		std::cout << buff << " has blown up! Lead Foot!" << std::endl << std::endl;
		SysFreeString(bstr);

		if (pEngine)
		{
			pEngine->Release();
		}
		if (pStats)
		{
			pStats->Release();
		}
	}
	CoUninitialize();
    return 0;
}