echo off
echo duilib.lib build begin

if /I "%1" == "noclean" (

	echo build noclean release
	@msdev duilib.dsp /MAKE "duilib - Win32 Release" /REBUILD /NORECURSE /OUT ..\..\..\..\10-common\version\CompileInfo\duilib_r.txt
) else (

	echo build clean release
	@msdev duilib.dsp /MAKE "duilib - Win32 Release" /REBUILD /NORECURSE /OUT ..\..\..\..\10-common\version\CompileInfo\duilib_r.txt
)

echo duilib.lib build over
echo on