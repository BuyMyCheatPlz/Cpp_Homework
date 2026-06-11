@echo off
cd /d c:\Users\wangy\Cpp_Homework\Eigen_Project

rem 确保 g++ 能加载到 cc1plus 所需的 DLL（MSYS2 UCRT64 工具链）
set PATH=C:\msys64\ucrt64\bin;%PATH%

rem 编译三个源文件，-I C:\Eigen 指定 Eigen 头文件路径
g++ -std=c++11 -I C:\Eigen main.cpp matrix_ops.cpp eigen_verify.cpp -o matrix.exe
if errorlevel 1 (
    echo Build FAILED.
    exit /b 1
)
echo Build OK -^> matrix.exe
