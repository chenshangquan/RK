#include "StdAfx.h"
#include "InterfaceDef.h"

template<> IWindowManager* Singleton<IWindowManager>::ms_pSingleton  = 0;
template<> IMsgManager* Singleton<IMsgManager>::ms_pSingleton  = 0;
template<> IUserDataMngr* Singleton<IUserDataMngr>::ms_pSingleton  = 0;
template<> IControlFactory* Singleton<IControlFactory>::ms_pSingleton  = 0;
template<> IDocManager* Singleton<IDocManager>::ms_pSingleton  = 0;
template<> ILogicManager* Singleton<ILogicManager>::ms_pSingleton  = 0;
template<> ILogger* Singleton<ILogger>::ms_pSingleton  = 0;
template<> IDeviceFactory* Singleton<IDeviceFactory>::ms_pSingleton  = 0;
template<> IBoardFactory* Singleton<IBoardFactory>::ms_pSingleton  = 0;
template<> ITestCaseFactory* Singleton<ITestCaseFactory>::ms_pSingleton  = 0;
template<> IMsgQueFactory* Singleton<IMsgQueFactory>::ms_pSingleton  = 0;
template<> IMacroMngr* Singleton<IMacroMngr>::ms_pSingleton  = 0;
template<> IOspAppManager* Singleton<IOspAppManager>::ms_pSingleton  = 0;
template<> IOspSessionMngr* Singleton<IOspSessionMngr>::ms_pSingleton  = 0;
template<> ILoadInfoMngr* Singleton<ILoadInfoMngr>::ms_pSingleton  = 0;
