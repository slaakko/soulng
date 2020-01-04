@echo off
scmpg -v ../parser/XmlParser.spg
xcopy /Y /D ..\parser\XmlParser.cm ..\merge
cpp2cm -v ../system.xml.xml
