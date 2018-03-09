#include "CoCar.h"
#include "iid.h"
#include <cstdio>

#define MAX_SPEED 500
#define MAX_NAME_LENGTH 50

extern DWORD g_objCount;

CoCar::CoCar(): m_refCount(0), m_maxSpeed(0), m_curSpeed(0)
{
	m_carName = SysAllocString(L"Default Car Name");

	++g_objCount;
}

CoCar::~CoCar()
{
	--g_objCount;

	if (m_carName)
	{
		SysFreeString(m_carName);
	}

	MessageBoxA(nullptr, "CoCar is dead", "Destructor", MB_OK | MB_SETFOREGROUND);
}


#pragma region IUnknown

HRESULT CoCar::QueryInterface(const IID& riid, void** ppvObject)
{
	if (riid == IID_IUnknown)
	{
		*ppvObject = static_cast<IUnknown*>(static_cast<IEngine*>(this));
		MessageBoxA(nullptr, "Handled out IUnknown", "QI", MB_OK | MB_SETFOREGROUND);
	}
	else if (riid == IID_IEngine)
	{
		*ppvObject = static_cast<IEngine*>(this);
		MessageBoxA(nullptr, "Handled out IEngine", "QI", MB_OK | MB_SETFOREGROUND);
	}
	else if (riid == IID_IStats)
	{
		*ppvObject = static_cast<IStats*>(this);
		MessageBoxA(nullptr, "Handled out IStats", "QI", MB_OK | MB_SETFOREGROUND);
	}
	else if (riid == IID_ICreateCar)
	{
		*ppvObject = static_cast<ICreateCar*>(this);
		MessageBoxA(nullptr, "Handled out ICreateCar", "QI", MB_OK | MB_SETFOREGROUND);
	}
	else
	{
		*ppvObject = nullptr;
		MessageBoxA(nullptr, "Error: no such interface.", "QI", MB_OK | MB_SETFOREGROUND);
		return E_NOINTERFACE;
	}

	static_cast<IUnknown*>(*ppvObject)->AddRef();

	return S_OK;
}

DWORD CoCar::AddRef()
{
	return ++m_refCount;
}

DWORD CoCar::Release()
{
	if (--m_refCount == 0)
	{
		delete this;
		return 0;
	}

	return m_refCount;
}

#pragma endregion 


#pragma region IEngine

HRESULT CoCar::SpeedUp()
{
	m_curSpeed += 10;
	return S_OK;
}

HRESULT CoCar::GetMaxSpeed(int* maxSpeed)
{
	*maxSpeed = m_maxSpeed;
	return S_OK;
}

HRESULT CoCar::GetCurSpeed(int* curSpeed)
{
	*curSpeed = m_curSpeed;
	return S_OK;
}

#pragma endregion 


#pragma region IStats

HRESULT CoCar::DisplayStats()
{
	char buff[MAX_NAME_LENGTH];

	WideCharToMultiByte(CP_ACP, NULL, m_carName, -1, buff, MAX_NAME_LENGTH, nullptr, nullptr);

	MessageBoxA(nullptr, buff, "Car Name", MB_OK | MB_SETFOREGROUND);

	memset(buff, 0, sizeof buff);

	sprintf_s(buff, "%d", m_maxSpeed);

	MessageBoxA(nullptr, buff, "Max Speed", MB_OK | MB_SETFOREGROUND);

	return S_OK;
}

HRESULT CoCar::GetCarName(BSTR* carName)
{
	*carName = SysAllocString(m_carName);
	return S_OK;
}

#pragma endregion


#pragma region ICreateCar

HRESULT CoCar::SetCarName(BSTR carName)
{
	SysReAllocString(&m_carName, carName);
	return S_OK;
}

HRESULT CoCar::SetMaxSpeed(int maxSpeed)
{
	if (maxSpeed < MAX_SPEED)
	{
		m_maxSpeed = maxSpeed;
	}

	return S_OK;
}

#pragma endregion 