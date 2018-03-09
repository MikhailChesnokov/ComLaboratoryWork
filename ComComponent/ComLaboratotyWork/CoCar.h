#pragma once
#include "interfaces.h"

class CoCar :
	public IEngine,
	public ICreateCar,
	public IStats
{
public:
	CoCar();
	virtual ~CoCar();
	//CoCar(const CoCar& coCar) = delete;
	//CoCar(const CoCar&& coCar) = delete;
	//CoCar operator=(const CoCar& cocar) = delete;
	//CoCar operator=(const CoCar&& cocar) = delete;

	// IUnknown
	STDMETHODIMP QueryInterface(const IID& riid, void** ppvObject) override;
	STDMETHODIMP_(DWORD)AddRef() override;
	STDMETHODIMP_(DWORD)Release() override;

	// IEngine
	STDMETHODIMP SpeedUp() override;
	STDMETHODIMP GetMaxSpeed(int* maxSpeed) override;
	STDMETHODIMP GetCurSpeed(int* curSpeed) override;

	// IStats
	STDMETHODIMP DisplayStats() override;
	STDMETHODIMP GetCarName(BSTR* carName) override;

	// ICreateCar
	STDMETHODIMP SetCarName(BSTR carName) override;
	STDMETHODIMP SetMaxSpeed(int maxSpeed) override;
private:
	ULONG m_refCount;
	BSTR m_carName;
	INT m_maxSpeed;
	INT m_curSpeed;
};