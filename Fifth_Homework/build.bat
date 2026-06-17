@echo off
cd /d C:\Users\wangy\Cpp_Homework\Fifth_Homework

set PATH=C:\msys64\ucrt64\bin;%PATH%

g++ -std=c++11 MyString.cpp main.cpp -o mystring.exe
if errorlevel 1 (
    echo Build FAILED.
    exit /b 1
)
echo Build OK -^> mystring.exe