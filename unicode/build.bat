@echo off
IF NOT EXIST ucd.all.flat.xml powershell -command "Expand-Archive -Force '%~dp0ucd.all.flat.zip' '%~dp0'"
IF NOT EXIST soulng_ucd.bin make_soulng_ucd
