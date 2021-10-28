call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"
msbuild -verbosity:minimal -t:Rebuild -p:Configuration="Debug" "C:\work\soulng\setup\soulng\program\setup.vcxproj" > "C:\work\soulng\setup\soulng\compile\debug_stdout.txt" 2> "C:\work\soulng\setup\soulng\compile\debug_stderr.txt"
