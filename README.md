# WinUI Starter

Project showcasing WinUI 3 to get things started

## Development
- To compile via CLI get 'Build Tools for Visual Studio' from https://visualstudio.microsoft.com/downloads/  
- Under installation, enable 'C++ WinUI app development build tools', 'MSVC build tools for x64/x86' and 'Windows 11 SDK'
- This'll install 'x64 Native Tools Command Promp for VS' which you can start from the start menu

## Build
### Install Dependencies
<sub>x64 Native Tools Command Promp for VS</sub>
```cmd
msbuild src/HelloWinUI.vcxproj /restore /p:Configuration=Debug /p:Platform=x64
```

### Clean previous build and rebuild 
<sub>x64 Native Tools Command Promp for VS</sub>
```cmd
msbuild src/HelloWinUI.vcxproj /t:Rebuild /p:Configuration=Debug /p:Platform=x64
```

### Incremental Build
<sub>x64 Native Tools Command Promp for VS</sub>
```cmd
msbuild src/HelloWinUI.vcxproj /p:Configuration=Debug /p:Platform=x64
```

## Run
```cmd
./bin/HelloWinUI.exe
```
