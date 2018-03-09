#ifndef _INTERFACES

#define _INTERFACES

#pragma once
#include <windows.h>

DECLARE_INTERFACE_(IStats, IUnknown)
{
	STDMETHOD(DisplayStats) () PURE;
	STDMETHOD(GetCarName) (BSTR* carName) PURE;
};

DECLARE_INTERFACE_(IEngine, IUnknown)
{
	STDMETHOD(SpeedUp) () PURE;
	STDMETHOD(GetMaxSpeed) (int* maxSpeed) PURE;
	STDMETHOD(GetCurSpeed) (int* curSpeed) PURE;
};

DECLARE_INTERFACE_(ICreateCar, IUnknown)
{
	STDMETHOD(SetCarName) (BSTR carName) PURE;
	STDMETHOD(SetMaxSpeed) (int maxSpeed) PURE;
};

#endif