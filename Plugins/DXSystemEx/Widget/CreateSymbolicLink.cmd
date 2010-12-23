@echo off
del /Q "SystemEx\SDPlugins\DXSystemEx.dll"
mklink "SystemEx\SDPlugins\DXSystemEx.dll" "..\..\..\Builds\Debug\DXSystemEx.dll"