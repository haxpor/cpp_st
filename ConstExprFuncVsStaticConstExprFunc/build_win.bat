@echo off
setlocal

if "%1" == "clean" (
    call :DoClean
    echo "Remove all artifacts"
    EXIT /B %ERRORLEVEL%
)

REM build all stuff
cl.exe /std:c++17 /EHsc /FAcs /FaStaticConstExprFunction.asm /c StaticConstExprFunction.cpp
cl.exe /std:c++17 /EHsc /FAcs /FaConstExprFunction.asm /c ConstExprFunction.cpp

if %ERRORLEVEL% GEQ 1 (
    EXIT /B %ERRORLEVEL%
)

EXIT /B %ERRORLEVEL%

REM Delete all artifact files from build
:DoClean
del /Q StaticConstExprFunction.asm ConstExprFunction.asm StaticConstExprFunction.obj ConstExprFunction.obj
EXIT /B 0
