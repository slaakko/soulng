# Makefile for soulng projects

# Run with nmake from Visual Studio 2019 x64 Native Tools Command Prompt

all: makedirs soulng_all install unicode
	echo make succeeded.

makedirs:
	makedirs.bat
	
soulng_all:
	MSBuild -m -verbosity:minimal ..\soulng_all.sln -p:Configuration="Debug"
	MSBuild -m -verbosity:minimal ..\soulng_all.sln -p:Configuration="Release"

install:
	cd ..\inst && inst.bat

unicode:
	cd ..\unicode && build.bat
