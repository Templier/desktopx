@echo off
del /Q "SystemEx\SDPlugins\DXSystemEx.dll"
del /Q "SystemEx\SDPlugins\DXSystemEx.pdb"
mklink "SystemEx\SDPlugins\DXSystemEx.dll" "..\..\..\Builds\Debug\DXSystemEx.dll"
mklink "SystemEx\SDPlugins\DXSystemEx.pdb" "..\..\..\Builds\Debug\DXSystemEx.pdb"
