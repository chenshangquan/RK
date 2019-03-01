# Microsoft Developer Studio Generated NMAKE File, Based on producetest2.dsp
!IF "$(CFG)" == ""
CFG=producetest2 - Win32 Debug
!MESSAGE No configuration specified. Defaulting to producetest2 - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "producetest2 - Win32 Release" && "$(CFG)" != "producetest2 - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
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
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "producetest2 - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release

ALL : "..\..\..\10-common\version\release\win32\producetest2\producetest2.exe"


CLEAN :
	-@erase "$(INTDIR)\AbnormalLogic.obj"
	-@erase "$(INTDIR)\Board.obj"
	-@erase "$(INTDIR)\BoardFactory.obj"
	-@erase "$(INTDIR)\CaseCfgLogic.obj"
	-@erase "$(INTDIR)\CComm.obj"
	-@erase "$(INTDIR)\ChooseDlgLogic.obj"
	-@erase "$(INTDIR)\ControlFactory.obj"
	-@erase "$(INTDIR)\Device.obj"
	-@erase "$(INTDIR)\DeviceFactory.obj"
	-@erase "$(INTDIR)\DocManager.obj"
	-@erase "$(INTDIR)\ICommonOp.obj"
	-@erase "$(INTDIR)\InterfaceDef.obj"
	-@erase "$(INTDIR)\LoadInfoMngr.obj"
	-@erase "$(INTDIR)\LoadLogic.obj"
	-@erase "$(INTDIR)\Logger.obj"
	-@erase "$(INTDIR)\LogicManager.obj"
	-@erase "$(INTDIR)\MacroMngr.obj"
	-@erase "$(INTDIR)\main.obj"
	-@erase "$(INTDIR)\MainLogic.obj"
	-@erase "$(INTDIR)\MsgManager.obj"
	-@erase "$(INTDIR)\MsgQueFactory.obj"
	-@erase "$(INTDIR)\MsgQueMngr.obj"
	-@erase "$(INTDIR)\NormalLogic.obj"
	-@erase "$(INTDIR)\NotifyDlgLogic.obj"
	-@erase "$(INTDIR)\OspAppManager.obj"
	-@erase "$(INTDIR)\OspInstance.obj"
	-@erase "$(INTDIR)\OspSession.obj"
	-@erase "$(INTDIR)\OspSessionMngr.obj"
	-@erase "$(INTDIR)\PlayerLogic.obj"
	-@erase "$(INTDIR)\producetest2.pch"
	-@erase "$(INTDIR)\resource.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\SuperTerminalLogic.obj"
	-@erase "$(INTDIR)\System.obj"
	-@erase "$(INTDIR)\TestCase.obj"
	-@erase "$(INTDIR)\TestCaseContainer.obj"
	-@erase "$(INTDIR)\TestCaseFactory.obj"
	-@erase "$(INTDIR)\TestLogic.obj"
	-@erase "$(INTDIR)\Tftp.obj"
	-@erase "$(INTDIR)\Udp.obj"
	-@erase "$(INTDIR)\UdpSession.obj"
	-@erase "$(INTDIR)\UserDataManager.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\WindowManager.obj"
	-@erase "$(INTDIR)\WndObserver.obj"
	-@erase "$(OUTDIR)\producetest2.map"
	-@erase "..\..\..\10-common\version\release\win32\producetest2\producetest2.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /Zd /O2 /I "..\duilib\include" /I "..\..\common\include\platform sdk\INCLUDE" /I "..\include" /I "..\..\..\10-common\include\system1" /I "..\..\..\10-common\include\protocol" /I "..\..\..\10-common\include\platform" /I "..\..\..\10-common\include\producttest" /I "..\..\..\10-common\include\mcu" /I "..\..\common\include" /I "..\..\..\10-common\include\tp" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "SOFT_CODEC" /D "_AFXDLL" /Fp"$(INTDIR)\producetest2.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\resource.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\producetest2.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\producetest2.pdb" /map:"$(INTDIR)\producetest2.map" /machine:I386 /nodefaultlib:"LIBCD" /nodefaultlib:"LIBCMT" /nodefaultlib:"LIBC.lib" /nodefaultlib:"nafxcw.lib" /nodefaultlib:"nafxcwd.lib" /nodefaultlib:"libcmtd.lib" /out:"..\..\..\10-common\version\release\win32\producetest2\producetest2.exe" /libpath:"..\..\..\10-common\lib\release\win32" /libpath:"..\..\common\include\platform sdk\LIB" /mapinfo:lines 
LINK32_OBJS= \
	"$(INTDIR)\main.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\System.obj" \
	"$(INTDIR)\ICommonOp.obj" \
	"$(INTDIR)\InterfaceDef.obj" \
	"$(INTDIR)\WndObserver.obj" \
	"$(INTDIR)\DocManager.obj" \
	"$(INTDIR)\Logger.obj" \
	"$(INTDIR)\MacroMngr.obj" \
	"$(INTDIR)\AbnormalLogic.obj" \
	"$(INTDIR)\CaseCfgLogic.obj" \
	"$(INTDIR)\ChooseDlgLogic.obj" \
	"$(INTDIR)\LoadLogic.obj" \
	"$(INTDIR)\MainLogic.obj" \
	"$(INTDIR)\NormalLogic.obj" \
	"$(INTDIR)\NotifyDlgLogic.obj" \
	"$(INTDIR)\PlayerLogic.obj" \
	"$(INTDIR)\SuperTerminalLogic.obj" \
	"$(INTDIR)\TestLogic.obj" \
	"$(INTDIR)\LogicManager.obj" \
	"$(INTDIR)\MsgManager.obj" \
	"$(INTDIR)\UserDataManager.obj" \
	"$(INTDIR)\WindowManager.obj" \
	"$(INTDIR)\Board.obj" \
	"$(INTDIR)\Device.obj" \
	"$(INTDIR)\MsgQueMngr.obj" \
	"$(INTDIR)\TestCase.obj" \
	"$(INTDIR)\TestCaseContainer.obj" \
	"$(INTDIR)\BoardFactory.obj" \
	"$(INTDIR)\ControlFactory.obj" \
	"$(INTDIR)\DeviceFactory.obj" \
	"$(INTDIR)\MsgQueFactory.obj" \
	"$(INTDIR)\TestCaseFactory.obj" \
	"$(INTDIR)\OspAppManager.obj" \
	"$(INTDIR)\OspInstance.obj" \
	"$(INTDIR)\OspSession.obj" \
	"$(INTDIR)\OspSessionMngr.obj" \
	"$(INTDIR)\LoadInfoMngr.obj" \
	"$(INTDIR)\Udp.obj" \
	"$(INTDIR)\UdpSession.obj" \
	"$(INTDIR)\CComm.obj" \
	"$(INTDIR)\Tftp.obj" \
	"$(INTDIR)\resource.res"

"..\..\..\10-common\version\release\win32\producetest2\producetest2.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\producetest2.exe" "$(OUTDIR)\producetest2.bsc"


CLEAN :
	-@erase "$(INTDIR)\AbnormalLogic.obj"
	-@erase "$(INTDIR)\AbnormalLogic.sbr"
	-@erase "$(INTDIR)\Board.obj"
	-@erase "$(INTDIR)\Board.sbr"
	-@erase "$(INTDIR)\BoardFactory.obj"
	-@erase "$(INTDIR)\BoardFactory.sbr"
	-@erase "$(INTDIR)\CaseCfgLogic.obj"
	-@erase "$(INTDIR)\CaseCfgLogic.sbr"
	-@erase "$(INTDIR)\CComm.obj"
	-@erase "$(INTDIR)\CComm.sbr"
	-@erase "$(INTDIR)\ChooseDlgLogic.obj"
	-@erase "$(INTDIR)\ChooseDlgLogic.sbr"
	-@erase "$(INTDIR)\ControlFactory.obj"
	-@erase "$(INTDIR)\ControlFactory.sbr"
	-@erase "$(INTDIR)\Device.obj"
	-@erase "$(INTDIR)\Device.sbr"
	-@erase "$(INTDIR)\DeviceFactory.obj"
	-@erase "$(INTDIR)\DeviceFactory.sbr"
	-@erase "$(INTDIR)\DocManager.obj"
	-@erase "$(INTDIR)\DocManager.sbr"
	-@erase "$(INTDIR)\ICommonOp.obj"
	-@erase "$(INTDIR)\ICommonOp.sbr"
	-@erase "$(INTDIR)\InterfaceDef.obj"
	-@erase "$(INTDIR)\InterfaceDef.sbr"
	-@erase "$(INTDIR)\LoadInfoMngr.obj"
	-@erase "$(INTDIR)\LoadInfoMngr.sbr"
	-@erase "$(INTDIR)\LoadLogic.obj"
	-@erase "$(INTDIR)\LoadLogic.sbr"
	-@erase "$(INTDIR)\Logger.obj"
	-@erase "$(INTDIR)\Logger.sbr"
	-@erase "$(INTDIR)\LogicManager.obj"
	-@erase "$(INTDIR)\LogicManager.sbr"
	-@erase "$(INTDIR)\MacroMngr.obj"
	-@erase "$(INTDIR)\MacroMngr.sbr"
	-@erase "$(INTDIR)\main.obj"
	-@erase "$(INTDIR)\main.sbr"
	-@erase "$(INTDIR)\MainLogic.obj"
	-@erase "$(INTDIR)\MainLogic.sbr"
	-@erase "$(INTDIR)\MsgManager.obj"
	-@erase "$(INTDIR)\MsgManager.sbr"
	-@erase "$(INTDIR)\MsgQueFactory.obj"
	-@erase "$(INTDIR)\MsgQueFactory.sbr"
	-@erase "$(INTDIR)\MsgQueMngr.obj"
	-@erase "$(INTDIR)\MsgQueMngr.sbr"
	-@erase "$(INTDIR)\NormalLogic.obj"
	-@erase "$(INTDIR)\NormalLogic.sbr"
	-@erase "$(INTDIR)\NotifyDlgLogic.obj"
	-@erase "$(INTDIR)\NotifyDlgLogic.sbr"
	-@erase "$(INTDIR)\OspAppManager.obj"
	-@erase "$(INTDIR)\OspAppManager.sbr"
	-@erase "$(INTDIR)\OspInstance.obj"
	-@erase "$(INTDIR)\OspInstance.sbr"
	-@erase "$(INTDIR)\OspSession.obj"
	-@erase "$(INTDIR)\OspSession.sbr"
	-@erase "$(INTDIR)\OspSessionMngr.obj"
	-@erase "$(INTDIR)\OspSessionMngr.sbr"
	-@erase "$(INTDIR)\PlayerLogic.obj"
	-@erase "$(INTDIR)\PlayerLogic.sbr"
	-@erase "$(INTDIR)\producetest2.pch"
	-@erase "$(INTDIR)\resource.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\SuperTerminalLogic.obj"
	-@erase "$(INTDIR)\SuperTerminalLogic.sbr"
	-@erase "$(INTDIR)\System.obj"
	-@erase "$(INTDIR)\System.sbr"
	-@erase "$(INTDIR)\TestCase.obj"
	-@erase "$(INTDIR)\TestCase.sbr"
	-@erase "$(INTDIR)\TestCaseContainer.obj"
	-@erase "$(INTDIR)\TestCaseContainer.sbr"
	-@erase "$(INTDIR)\TestCaseFactory.obj"
	-@erase "$(INTDIR)\TestCaseFactory.sbr"
	-@erase "$(INTDIR)\TestLogic.obj"
	-@erase "$(INTDIR)\TestLogic.sbr"
	-@erase "$(INTDIR)\Tftp.obj"
	-@erase "$(INTDIR)\Tftp.sbr"
	-@erase "$(INTDIR)\Udp.obj"
	-@erase "$(INTDIR)\Udp.sbr"
	-@erase "$(INTDIR)\UdpSession.obj"
	-@erase "$(INTDIR)\UdpSession.sbr"
	-@erase "$(INTDIR)\UserDataManager.obj"
	-@erase "$(INTDIR)\UserDataManager.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\WindowManager.obj"
	-@erase "$(INTDIR)\WindowManager.sbr"
	-@erase "$(INTDIR)\WndObserver.obj"
	-@erase "$(INTDIR)\WndObserver.sbr"
	-@erase "$(OUTDIR)\producetest2.bsc"
	-@erase "$(OUTDIR)\producetest2.exe"
	-@erase "$(OUTDIR)\producetest2.ilk"
	-@erase "$(OUTDIR)\producetest2.map"
	-@erase "$(OUTDIR)\producetest2.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\duilib\include" /I "..\..\common\include\platform sdk\INCLUDE" /I "..\include" /I "..\..\..\10-common\include\system1" /I "..\..\..\10-common\include\protocol" /I "..\..\..\10-common\include\platform" /I "..\..\..\10-common\include\producttest" /I "..\..\..\10-common\include\mcu" /I "..\..\common\include" /I "..\..\..\10-common\include\tp" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "SOFT_CODEC" /D "_AFXDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\producetest2.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\resource.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\producetest2.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\main.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\System.sbr" \
	"$(INTDIR)\ICommonOp.sbr" \
	"$(INTDIR)\InterfaceDef.sbr" \
	"$(INTDIR)\WndObserver.sbr" \
	"$(INTDIR)\DocManager.sbr" \
	"$(INTDIR)\Logger.sbr" \
	"$(INTDIR)\MacroMngr.sbr" \
	"$(INTDIR)\AbnormalLogic.sbr" \
	"$(INTDIR)\CaseCfgLogic.sbr" \
	"$(INTDIR)\ChooseDlgLogic.sbr" \
	"$(INTDIR)\LoadLogic.sbr" \
	"$(INTDIR)\MainLogic.sbr" \
	"$(INTDIR)\NormalLogic.sbr" \
	"$(INTDIR)\NotifyDlgLogic.sbr" \
	"$(INTDIR)\PlayerLogic.sbr" \
	"$(INTDIR)\SuperTerminalLogic.sbr" \
	"$(INTDIR)\TestLogic.sbr" \
	"$(INTDIR)\LogicManager.sbr" \
	"$(INTDIR)\MsgManager.sbr" \
	"$(INTDIR)\UserDataManager.sbr" \
	"$(INTDIR)\WindowManager.sbr" \
	"$(INTDIR)\Board.sbr" \
	"$(INTDIR)\Device.sbr" \
	"$(INTDIR)\MsgQueMngr.sbr" \
	"$(INTDIR)\TestCase.sbr" \
	"$(INTDIR)\TestCaseContainer.sbr" \
	"$(INTDIR)\BoardFactory.sbr" \
	"$(INTDIR)\ControlFactory.sbr" \
	"$(INTDIR)\DeviceFactory.sbr" \
	"$(INTDIR)\MsgQueFactory.sbr" \
	"$(INTDIR)\TestCaseFactory.sbr" \
	"$(INTDIR)\OspAppManager.sbr" \
	"$(INTDIR)\OspInstance.sbr" \
	"$(INTDIR)\OspSession.sbr" \
	"$(INTDIR)\OspSessionMngr.sbr" \
	"$(INTDIR)\LoadInfoMngr.sbr" \
	"$(INTDIR)\Udp.sbr" \
	"$(INTDIR)\UdpSession.sbr" \
	"$(INTDIR)\CComm.sbr" \
	"$(INTDIR)\Tftp.sbr"

"$(OUTDIR)\producetest2.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\producetest2.pdb" /map:"$(INTDIR)\producetest2.map" /debug /machine:I386 /nodefaultlib:"nafxcwd.lib" /nodefaultlib:"libcmtd.lib" /nodefaultlib:"LIBCD.lib" /nodefaultlib:"LIBCMT.lib" /nodefaultlib:"LIBC.lib" /nodefaultlib:"MSVCRT.lib" /out:"$(OUTDIR)\producetest2.exe" /pdbtype:sept /libpath:"..\..\..\10-common\lib\debug\win32" /libpath:"..\..\common\include\platform sdk\LIB" 
LINK32_OBJS= \
	"$(INTDIR)\main.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\System.obj" \
	"$(INTDIR)\ICommonOp.obj" \
	"$(INTDIR)\InterfaceDef.obj" \
	"$(INTDIR)\WndObserver.obj" \
	"$(INTDIR)\DocManager.obj" \
	"$(INTDIR)\Logger.obj" \
	"$(INTDIR)\MacroMngr.obj" \
	"$(INTDIR)\AbnormalLogic.obj" \
	"$(INTDIR)\CaseCfgLogic.obj" \
	"$(INTDIR)\ChooseDlgLogic.obj" \
	"$(INTDIR)\LoadLogic.obj" \
	"$(INTDIR)\MainLogic.obj" \
	"$(INTDIR)\NormalLogic.obj" \
	"$(INTDIR)\NotifyDlgLogic.obj" \
	"$(INTDIR)\PlayerLogic.obj" \
	"$(INTDIR)\SuperTerminalLogic.obj" \
	"$(INTDIR)\TestLogic.obj" \
	"$(INTDIR)\LogicManager.obj" \
	"$(INTDIR)\MsgManager.obj" \
	"$(INTDIR)\UserDataManager.obj" \
	"$(INTDIR)\WindowManager.obj" \
	"$(INTDIR)\Board.obj" \
	"$(INTDIR)\Device.obj" \
	"$(INTDIR)\MsgQueMngr.obj" \
	"$(INTDIR)\TestCase.obj" \
	"$(INTDIR)\TestCaseContainer.obj" \
	"$(INTDIR)\BoardFactory.obj" \
	"$(INTDIR)\ControlFactory.obj" \
	"$(INTDIR)\DeviceFactory.obj" \
	"$(INTDIR)\MsgQueFactory.obj" \
	"$(INTDIR)\TestCaseFactory.obj" \
	"$(INTDIR)\OspAppManager.obj" \
	"$(INTDIR)\OspInstance.obj" \
	"$(INTDIR)\OspSession.obj" \
	"$(INTDIR)\OspSessionMngr.obj" \
	"$(INTDIR)\LoadInfoMngr.obj" \
	"$(INTDIR)\Udp.obj" \
	"$(INTDIR)\UdpSession.obj" \
	"$(INTDIR)\CComm.obj" \
	"$(INTDIR)\Tftp.obj" \
	"$(INTDIR)\resource.res"

"$(OUTDIR)\producetest2.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("producetest2.dep")
!INCLUDE "producetest2.dep"
!ELSE 
!MESSAGE Warning: cannot find "producetest2.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "producetest2 - Win32 Release" || "$(CFG)" == "producetest2 - Win32 Debug"
SOURCE=.\main.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\main.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\main.obj"	"$(INTDIR)\main.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"


!ENDIF 

SOURCE=.\resource.rc

"$(INTDIR)\resource.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /Zd /O2 /I "..\duilib\include" /I "..\..\common\include\platform sdk\INCLUDE" /I "..\include" /I "..\..\..\10-common\include\system1" /I "..\..\..\10-common\include\protocol" /I "..\..\..\10-common\include\platform" /I "..\..\..\10-common\include\producttest" /I "..\..\..\10-common\include\mcu" /I "..\..\common\include" /I "..\..\..\10-common\include\tp" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "SOFT_CODEC" /D "_AFXDLL" /Fp"$(INTDIR)\producetest2.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\producetest2.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\duilib\include" /I "..\..\common\include\platform sdk\INCLUDE" /I "..\include" /I "..\..\..\10-common\include\system1" /I "..\..\..\10-common\include\protocol" /I "..\..\..\10-common\include\platform" /I "..\..\..\10-common\include\producttest" /I "..\..\..\10-common\include\mcu" /I "..\..\common\include" /I "..\..\..\10-common\include\tp" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "SOFT_CODEC" /D "_AFXDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\producetest2.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\producetest2.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=..\source\System.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\System.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\System.obj"	"$(INTDIR)\System.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\ICommonOp.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\ICommonOp.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\ICommonOp.obj"	"$(INTDIR)\ICommonOp.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\InterfaceDef.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\InterfaceDef.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\InterfaceDef.obj"	"$(INTDIR)\InterfaceDef.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\WndObserver.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\WndObserver.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\WndObserver.obj"	"$(INTDIR)\WndObserver.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\DocManager.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\DocManager.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\DocManager.obj"	"$(INTDIR)\DocManager.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\Logger.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\Logger.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\Logger.obj"	"$(INTDIR)\Logger.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\MacroMngr.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\MacroMngr.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\MacroMngr.obj"	"$(INTDIR)\MacroMngr.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\AbnormalLogic.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\AbnormalLogic.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\AbnormalLogic.obj"	"$(INTDIR)\AbnormalLogic.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\CaseCfgLogic.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\CaseCfgLogic.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\CaseCfgLogic.obj"	"$(INTDIR)\CaseCfgLogic.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\ChooseDlgLogic.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\ChooseDlgLogic.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\ChooseDlgLogic.obj"	"$(INTDIR)\ChooseDlgLogic.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"


!ENDIF 

SOURCE=..\source\LoadLogic.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\LoadLogic.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\LoadLogic.obj"	"$(INTDIR)\LoadLogic.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\MainLogic.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\MainLogic.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\MainLogic.obj"	"$(INTDIR)\MainLogic.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\NormalLogic.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\NormalLogic.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\NormalLogic.obj"	"$(INTDIR)\NormalLogic.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\NotifyDlgLogic.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\NotifyDlgLogic.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\NotifyDlgLogic.obj"	"$(INTDIR)\NotifyDlgLogic.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\PlayerLogic.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\PlayerLogic.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\PlayerLogic.obj"	"$(INTDIR)\PlayerLogic.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\SuperTerminalLogic.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\SuperTerminalLogic.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\SuperTerminalLogic.obj"	"$(INTDIR)\SuperTerminalLogic.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\TestLogic.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\TestLogic.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\TestLogic.obj"	"$(INTDIR)\TestLogic.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\LogicManager.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\LogicManager.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\LogicManager.obj"	"$(INTDIR)\LogicManager.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\MsgManager.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\MsgManager.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\MsgManager.obj"	"$(INTDIR)\MsgManager.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\UserDataManager.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\UserDataManager.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\UserDataManager.obj"	"$(INTDIR)\UserDataManager.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\WindowManager.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\WindowManager.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\WindowManager.obj"	"$(INTDIR)\WindowManager.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\Board.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\Board.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\Board.obj"	"$(INTDIR)\Board.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\Device.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\Device.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\Device.obj"	"$(INTDIR)\Device.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\MsgQueMngr.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\MsgQueMngr.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\MsgQueMngr.obj"	"$(INTDIR)\MsgQueMngr.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\TestCase.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\TestCase.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\TestCase.obj"	"$(INTDIR)\TestCase.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\TestCaseContainer.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\TestCaseContainer.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\TestCaseContainer.obj"	"$(INTDIR)\TestCaseContainer.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\BoardFactory.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\BoardFactory.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\BoardFactory.obj"	"$(INTDIR)\BoardFactory.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\ControlFactory.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\ControlFactory.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\ControlFactory.obj"	"$(INTDIR)\ControlFactory.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\DeviceFactory.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\DeviceFactory.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\DeviceFactory.obj"	"$(INTDIR)\DeviceFactory.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\MsgQueFactory.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\MsgQueFactory.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\MsgQueFactory.obj"	"$(INTDIR)\MsgQueFactory.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\TestCaseFactory.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\TestCaseFactory.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\TestCaseFactory.obj"	"$(INTDIR)\TestCaseFactory.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\OspAppManager.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\OspAppManager.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\OspAppManager.obj"	"$(INTDIR)\OspAppManager.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\OspInstance.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\OspInstance.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\OspInstance.obj"	"$(INTDIR)\OspInstance.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\OspSession.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\OspSession.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\OspSession.obj"	"$(INTDIR)\OspSession.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\OspSessionMngr.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\OspSessionMngr.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\OspSessionMngr.obj"	"$(INTDIR)\OspSessionMngr.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\LoadInfoMngr.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\LoadInfoMngr.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\LoadInfoMngr.obj"	"$(INTDIR)\LoadInfoMngr.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\Udp.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\Udp.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\Udp.obj"	"$(INTDIR)\Udp.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\UdpSession.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\UdpSession.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\UdpSession.obj"	"$(INTDIR)\UdpSession.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\CComm.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\CComm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\CComm.obj"	"$(INTDIR)\CComm.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\source\Tftp.cpp

!IF  "$(CFG)" == "producetest2 - Win32 Release"


"$(INTDIR)\Tftp.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "producetest2 - Win32 Debug"


"$(INTDIR)\Tftp.obj"	"$(INTDIR)\Tftp.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\producetest2.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 


!ENDIF 

