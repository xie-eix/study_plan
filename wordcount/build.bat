@echo off
cd /d "%~dp0"

call "D:\Program Files\Microsoft Visual Studio\Professional\Common7\Tools\VsDevCmd.bat" -arch=x64 >nul
if errorlevel 1 (
    echo [error] VsDevCmd init failed
    exit /b 1
)

echo [build] wordcount.exe
cl /nologo /utf-8 /EHsc /W4 /std:c++17 /Iinclude src\main.cpp src\word_counter.cpp /Fe:wordcount.exe
if errorlevel 1 exit /b 1

echo [build] test.exe
cl /nologo /utf-8 /EHsc /W4 /std:c++17 /Iinclude test\test.cpp src\word_counter.cpp /Fe:test.exe
if errorlevel 1 exit /b 1

echo [build] done
exit /b 0
