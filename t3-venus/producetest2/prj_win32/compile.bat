echo off
echo producetest2.exe build begin

if exist "./producetest2.dep" (
	del "./producetest2.dep"
)

if "%1" == "noclean" (
    echo build noclean release	
	@msdev producetest2.dsp /MAKE "producetest2 - Win32 Release" /REBUILD /NORECURSE /OUT  ..\..\..\10-common\version\CompileInfo\producetest2_R.txt
) else (

    echo build clean release
	@msdev producetest2.dsp /MAKE "producetest2 - Win32 Release" /REBUILD /NORECURSE /OUT  ..\..\..\10-common\version\CompileInfo\producetest2_R.txt

)

echo producetest2.exe build over

if exist "..\..\..\10-common\version\release\win32\producetest2\producetest2.exp" (
	del "..\..\..\10-common\version\release\win32\producetest2\producetest2.exp"
	)
if exist "..\..\..\10-common\version\release\win32\producetest2\producetest2.lib" (
	del "..\..\..\10-common\version\release\win32\producetest2\producetest2.lib"
	)

if not exist "..\..\..\10-common\version\release\win32\producetest2\skin\" (
md ..\..\..\10-common\version\release\win32\producetest2\skin\
)
copy /Y skin  ..\..\..\10-common\version\release\win32\producetest2\skin\

if not exist "..\..\..\10-common\version\release\win32\producetest2\skin\skinres\" (
md ..\..\..\10-common\version\release\win32\producetest2\skin\skinres\
)
copy /Y skin\skinres  ..\..\..\10-common\version\release\win32\producetest2\skin\skinres\

if not exist "..\..\..\10-common\version\release\win32\producetest2\skin\brdpic\" (
md ..\..\..\10-common\version\release\win32\producetest2\skin\brdpic\
)
copy /Y skin\brdpic  ..\..\..\10-common\version\release\win32\producetest2\skin\brdpic\

if not exist "..\..\..\10-common\version\release\win32\producetest2\tftp\release\" (
md ..\..\..\10-common\version\release\win32\producetest2\tftp\release\
)
copy /Y tftp\release  ..\..\..\10-common\version\release\win32\producetest2\tftp\release
copy /Y system.xml  ..\..\..\10-common\version\release\win32\producetest2\



echo build producetest2.exe over
echo on
