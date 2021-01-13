@echo off
setlocal

if "%1" == "clean" (
	call :DoClean
	EXIT /B %ERRORLEVEL%
)

cl.exe /EHsc /Od /LD MyLib.cpp
REM Also generate assembly output
cl.exe /EHsc /Od /FAcs /Famain.asm main.cpp

EXIT /B %ERRORLEVEL%

REM Delete all artifacts
:DoClean
del /Q main.asm main.cod main.obj MyLib.obj MyLib.dll main.exe
EXIT /B 0
