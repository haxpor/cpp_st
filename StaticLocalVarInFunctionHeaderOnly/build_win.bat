@echo off
setlocal

if "%1" == "clean" (
	call :DoClean
	EXIT /B %ERRORLEVEL%
)

REM compile all source files
cl.exe /EHsc /std:c++17 /W4 /O2 /DANOTHER_API=dllexport /DANOTHER2_API=dllimport /c another.cpp
cl.exe /EHsc /std:c++17 /W4 /O2 /DANOTHER_API=dllimport /DANOTHER2_API=dllexport /c another2.cpp
cl.exe /EHsc /std:c++17 /W4 /O2 /DANOTHER_API=dllimport /DANOTHER2_API=dllimport /c main.cpp
REM link to create shared library
link.exe /DLL /OUT:another.dll another.obj
link.exe /DLL /OUT:another2.dll another2.obj
REM The order of linking with object files here are important in which definition compiler will use
cl.exe /EHsc /std:c++17 /W4 /O2 /Fe:main.exe main.obj /link another.lib another2.lib

EXIT /B %ERRORLEVEL%

REM Delete all artifacts
:DoClean
del /Q main.obj main.exe another.obj another2.obj another.dll another2.dll another.lib another2.lib
EXIT /B 0
