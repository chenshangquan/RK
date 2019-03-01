# Microsoft Developer Studio Project File - Name="duilib" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=duilib - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "duilib.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "duilib.mak" CFG="duilib - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "duilib - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "duilib - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "duilib"
# PROP Scc_LocalPath "."
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "duilib - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /W3 /Gm /GX /Zi /I ".\\" /I "..\include" /I "..\..\..\common\include\platform sdk\INCLUDE" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\..\..\..\10-common\lib\release\win32\duilib.lib"

!ELSEIF  "$(CFG)" == "duilib - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I ".\\" /I "..\include" /I "..\..\..\common\include\platform sdk\INCLUDE" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\..\..\..\10-common\lib\debug\win32\duilib.lib"

!ENDIF 

# Begin Target

# Name "duilib - Win32 Release"
# Name "duilib - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\source\AppWindow.cpp
# End Source File
# Begin Source File

SOURCE=..\source\stb_image.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc
# End Source File
# Begin Source File

SOURCE=..\source\UIActiveX.cpp
# End Source File
# Begin Source File

SOURCE=..\source\UIBase.cpp
# End Source File
# Begin Source File

SOURCE=..\source\UICombo.cpp
# End Source File
# Begin Source File

SOURCE=..\source\UICommonControls.cpp
# End Source File
# Begin Source File

SOURCE=..\source\UIContainer.cpp
# End Source File
# Begin Source File

SOURCE=..\source\UIControl.cpp
# End Source File
# Begin Source File

SOURCE=..\source\UIDelegate.cpp
# End Source File
# Begin Source File

SOURCE=..\source\UIDlgBuilder.cpp
# End Source File
# Begin Source File

SOURCE=..\source\UIlib.cpp
# End Source File
# Begin Source File

SOURCE=..\source\UIList.cpp
# End Source File
# Begin Source File

SOURCE=..\source\UIManager.cpp
# End Source File
# Begin Source File

SOURCE=..\source\UIMarkup.cpp
# End Source File
# Begin Source File

SOURCE=..\source\UIRender.cpp
# End Source File
# Begin Source File

SOURCE=..\source\UIRichEdit.cpp
# End Source File
# Begin Source File

SOURCE=..\source\XUnzip.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\include\AppWindow.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=..\include\UIActiveX.h
# End Source File
# Begin Source File

SOURCE=..\include\UIBase.h
# End Source File
# Begin Source File

SOURCE=..\include\UICombo.h
# End Source File
# Begin Source File

SOURCE=..\include\UICommonControls.h
# End Source File
# Begin Source File

SOURCE=..\include\UIContainer.h
# End Source File
# Begin Source File

SOURCE=..\include\UIControl.h
# End Source File
# Begin Source File

SOURCE=..\include\UIDelegate.h
# End Source File
# Begin Source File

SOURCE=..\include\UIDlgBuilder.h
# End Source File
# Begin Source File

SOURCE=..\include\UIlib.h
# End Source File
# Begin Source File

SOURCE=..\include\UIList.h
# End Source File
# Begin Source File

SOURCE=..\include\UIManager.h
# End Source File
# Begin Source File

SOURCE=..\include\UIMarkup.h
# End Source File
# Begin Source File

SOURCE=..\include\UIRender.h
# End Source File
# Begin Source File

SOURCE=..\include\UIRichEdit.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\Readme.txt
# End Source File
# End Target
# End Project
