@ECHO OFF

cd ..

set BASEDIR=%~dp0
set OUTPUT="pathetic-engine.exe"
PUSHD %BASEDIR%

RMDIR /Q /S build

conan install . --output-folder=build --build=missing
cd build
cmake .. -G "Visual Studio 17 2022" -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake
cmake --build . --config Release
Release\%OUTPUT%