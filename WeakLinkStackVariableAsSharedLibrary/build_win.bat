@echo off
setlocal

if "%1" == "clean" (
	call :DoClean
	EXIT /B %ERRORLEVEL%
)

REM compile all source files
cl.exe /EHsc /std:c++17 /W4 /O2 /c main.cpp
cl.exe /EHsc /std:c++17 /W4 /O2 /c Lib1.cpp
cl.exe /EHsc /std:c++17 /W4 /O2 /c Lib2.cpp
REM link to create shared library
link.exe /DLL /OUT:Lib1.dll Lib1.obj
link.exe /DLL /OUT:Lib2.dll Lib2.obj
REM The order of linking with object files here are important in which definition compiler will use
cl.exe /EHsc /std:c++17 /W4 /O2 /Fe:main.exe Lib1.obj Lib2.obj main.obj 

EXIT /B %ERRORLEVEL%

REM Delete all artifacts
:DoClean
del /Q main.obj main.exe Lib1.obj Lib2.obj Lib1.dll Lib2.dll
EXIT /B 0
