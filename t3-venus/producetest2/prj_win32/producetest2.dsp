# Microsoft Developer Studio Project File - Name="producetest2" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=producetest2 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "producetest2.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "producetest2.mak" CFG="producetest2 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "producetest2 - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "producetest2 - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "producetest2"
# PROP Scc_LocalPath "."
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "producetest2 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /Zd /O2 /I "..\duilib\include" /I "..\..\common\include\platform sdk\INCLUDE" /I "..\include" /I "..\..\..\10-common\include\system1" /I "..\..\..\10-common\include\protocol" /I "..\..\..\10-common\include\platform" /I "..\..\..\10-common\include\producttest" /I "..\..\..\10-common\include\mcu" /I "..\..\common\include" /I "..\..\..\10-common\include\tp" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "SOFT_CODEC" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 /nologo /subsystem:console /map /machine:I386 /nodefaultlib:"LIBCD" /nodefaultlib:"LIBCMT" /nodefaultlib:"LIBC.lib" /nodefaultlib:"nafxcw.lib" /nodefaultlib:"nafxcwd.lib" /nodefaultlib:"libcmtd.lib" /out:"..\..\..\10-common\version\release\win32\producetest2\producetest2.exe" /libpath:"..\..\..\10-common\lib\release\win32" /libpath:"..\..\common\include\platform sdk\LIB" /mapinfo:lines
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\duilib\include" /I "..\..\common\include\platform sdk\INCLUDE" /I "..\include" /I "..\..\..\10-common\include\system1" /I "..\..\..\10-common\include\protocol" /I "..\..\..\10-common\include\platform" /I "..\..\..\10-common\include\producttest" /I "..\..\..\10-common\include\mcu" /I "..\..\common\include" /I "..\..\..\10-common\include\tp" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "SOFT_CODEC" /D "_AFXDLL" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /map /debug /machine:I386 /nodefaultlib:"nafxcwd.lib" /nodefaultlib:"libcmtd.lib" /nodefaultlib:"LIBCD.lib" /nodefaultlib:"LIBCMT.lib" /nodefaultlib:"LIBC.lib" /nodefaultlib:"MSVCRT.lib" /pdbtype:sept /libpath:"..\..\..\10-common\lib\debug\win32" /libpath:"..\..\common\include\platform sdk\LIB"
# SUBTRACT LINK32 /pdb:none /force

!ENDIF 

# Begin Target

# Name "producetest2 - Win32 Release"
# Name "producetest2 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\main.cpp
# End Source File
# Begin Source File

SOURCE=.\resource.rc
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=..\source\System.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=..\include\System.h
# End Source File
# End Group
# Begin Group "公用类"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\ICommonOp.cpp
# End Source File
# Begin Source File

SOURCE=..\include\ICommonOp.h
# End Source File
# Begin Source File

SOURCE=..\source\InterfaceDef.cpp
# End Source File
# Begin Source File

SOURCE=..\include\InterfaceDef.h
# End Source File
# Begin Source File

SOURCE=..\source\WndObserver.cpp
# End Source File
# Begin Source File

SOURCE=..\include\WndObserver.h
# End Source File
# End Group
# Begin Group "工具类"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\DocManager.cpp
# End Source File
# Begin Source File

SOURCE=..\include\DocManager.h
# End Source File
# Begin Source File

SOURCE=..\source\Logger.cpp
# End Source File
# Begin Source File

SOURCE=..\include\Logger.h
# End Source File
# Begin Source File

SOURCE=..\source\MacroMngr.cpp
# End Source File
# Begin Source File

SOURCE=..\include\MacroMngr.h
# End Source File
# End Group
# Begin Group "结构体/宏/消息"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\include\msgdef.h
# End Source File
# Begin Source File

SOURCE=..\include\otherdef.h
# End Source File
# Begin Source File

SOURCE=..\include\structdef.h
# End Source File
# End Group
# Begin Group "界面逻辑"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\AbnormalLogic.cpp
# End Source File
# Begin Source File

SOURCE=..\include\AbnormalLogic.h
# End Source File
# Begin Source File

SOURCE=..\source\CaseCfgLogic.cpp
# End Source File
# Begin Source File

SOURCE=..\include\CaseCfgLogic.h
# End Source File
# Begin Source File

SOURCE=.\ChooseDlgLogic.cpp
# End Source File
# Begin Source File

SOURCE=..\include\ChooseDlgLogic.h
# End Source File
# Begin Source File

SOURCE=..\source\LoadLogic.cpp
# End Source File
# Begin Source File

SOURCE=..\include\LoadLogic.h
# End Source File
# Begin Source File

SOURCE=..\source\MainLogic.cpp
# End Source File
# Begin Source File

SOURCE=..\include\MainLogic.h
# End Source File
# Begin Source File

SOURCE=..\source\NormalLogic.cpp
# End Source File
# Begin Source File

SOURCE=..\include\NormalLogic.h
# End Source File
# Begin Source File

SOURCE=..\source\NotifyDlgLogic.cpp
# End Source File
# Begin Source File

SOURCE=..\include\NotifyDlgLogic.h
# End Source File
# Begin Source File

SOURCE=..\source\PlayerLogic.cpp
# End Source File
# Begin Source File

SOURCE=..\include\PlayerLogic.h
# End Source File
# Begin Source File

SOURCE=..\source\SuperTerminalLogic.cpp
# End Source File
# Begin Source File

SOURCE=..\include\SuperTerminalLogic.h
# End Source File
# Begin Source File

SOURCE=..\source\TestLogic.cpp
# End Source File
# Begin Source File

SOURCE=..\include\TestLogic.h
# End Source File
# End Group
# Begin Group "界面相关类"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\LogicManager.cpp
# End Source File
# Begin Source File

SOURCE=..\include\LogicManager.h
# End Source File
# Begin Source File

SOURCE=..\source\MsgManager.cpp
# End Source File
# Begin Source File

SOURCE=..\include\MsgManager.h
# End Source File
# Begin Source File

SOURCE=..\source\UserDataManager.cpp
# End Source File
# Begin Source File

SOURCE=..\include\UserDataManager.h
# End Source File
# Begin Source File

SOURCE=..\source\WindowManager.cpp
# End Source File
# Begin Source File

SOURCE=..\include\WindowManager.h
# End Source File
# End Group
# Begin Group "测试业务类"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\Board.cpp
# End Source File
# Begin Source File

SOURCE=..\include\Board.h
# End Source File
# Begin Source File

SOURCE=..\source\Device.cpp
# End Source File
# Begin Source File

SOURCE=..\include\Device.h
# End Source File
# Begin Source File

SOURCE=..\source\MsgQueMngr.cpp
# End Source File
# Begin Source File

SOURCE=..\include\MsgQueMngr.h
# End Source File
# Begin Source File

SOURCE=..\source\TestCase.cpp
# End Source File
# Begin Source File

SOURCE=..\include\TestCase.h
# End Source File
# Begin Source File

SOURCE=..\source\TestCaseContainer.cpp
# End Source File
# Begin Source File

SOURCE=..\include\TestCaseContainer.h
# End Source File
# End Group
# Begin Group "Factories"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\BoardFactory.cpp
# End Source File
# Begin Source File

SOURCE=..\include\BoardFactory.h
# End Source File
# Begin Source File

SOURCE=..\source\ControlFactory.cpp
# End Source File
# Begin Source File

SOURCE=..\include\ControlFactory.h
# End Source File
# Begin Source File

SOURCE=..\source\DeviceFactory.cpp
# End Source File
# Begin Source File

SOURCE=..\include\DeviceFactory.h
# End Source File
# Begin Source File

SOURCE=..\source\MsgQueFactory.cpp
# End Source File
# Begin Source File

SOURCE=..\include\MsgQueFactory.h
# End Source File
# Begin Source File

SOURCE=..\source\TestCaseFactory.cpp
# End Source File
# Begin Source File

SOURCE=..\include\TestCaseFactory.h
# End Source File
# End Group
# Begin Group "测试网络通信类"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\OspAppManager.cpp
# End Source File
# Begin Source File

SOURCE=..\include\OspAppManager.h
# End Source File
# Begin Source File

SOURCE=..\source\OspInstance.cpp
# End Source File
# Begin Source File

SOURCE=..\include\OspInstance.h
# End Source File
# Begin Source File

SOURCE=..\source\OspSession.cpp
# End Source File
# Begin Source File

SOURCE=..\include\OspSession.h
# End Source File
# Begin Source File

SOURCE=..\source\OspSessionMngr.cpp
# End Source File
# Begin Source File

SOURCE=..\include\OspSessionMngr.h
# End Source File
# End Group
# Begin Group "加载业务类"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\LoadInfoMngr.cpp
# End Source File
# Begin Source File

SOURCE=..\include\LoadInfoMngr.h
# End Source File
# Begin Source File

SOURCE=..\source\Udp.cpp
# End Source File
# Begin Source File

SOURCE=..\include\Udp.h
# End Source File
# Begin Source File

SOURCE=..\source\UdpSession.cpp
# End Source File
# Begin Source File

SOURCE=..\include\UdpSession.h
# End Source File
# End Group
# Begin Group "串口操作模块"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\CComm.cpp
# End Source File
# Begin Source File

SOURCE=..\include\CComm.h
# End Source File
# End Group
# Begin Group "Tftp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\Tftp.cpp
# End Source File
# Begin Source File

SOURCE=..\include\Tftp.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\source\msxml.tlh
# End Source File
# Begin Source File

SOURCE=..\source\msxml.tli
# End Source File
# Begin Source File

SOURCE=.\skin\SkinRes\producetest2.ico
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
