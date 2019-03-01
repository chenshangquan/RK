@echo off
cd duilib
call compile.bat %1
cd ..

cd prj_win32
call compile.bat %1
cd ..

rem call setup.bat %1
@echo on
