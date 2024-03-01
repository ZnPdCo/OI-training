@echo off
set hideform=False
set "message=Enter your msg:"
set "title=Push2Github"
set "note=Updated By ZnPdCo"
if /i "%hideform%"=="True" (
if "%1"=="h" goto begin
mshta vbscript:createobject^("wscript.shell"^).run^("%~nx0 h",0^)^(window.close^)&&exit
)
:begin
set "vbs=%Temp%\GotUserInputedDataProgram.vbs"
set "data=%Temp%\UserInputedData.tmp"
if exist "%vbs%" del /s /q /f "%vbs%">nul
::delete file
echo On Error Resume Next>>"%vbs%"
echo Dim fso,wri,data,file>>"%vbs%"
echo Set fso=Wscript.CreateObject^("Scripting.FileSystemObject"^)>>"%vbs%"
echo file="%data%">>"%vbs%"
echo if fso.FileExists^(file^) Then fso.DeleteFile^(file^)>>"%vbs%"
echo Set wri=fso.CreateTextFile^(file,True^)>>"%vbs%"
echo data=InputBox^("%message%","%title%","%note%"^)>>"%vbs%"
echo wri.Write data>>"%vbs%"
echo wri.Close>>"%vbs%"
echo Set fso=Nothing>>"%vbs%"
echo Set op=Nothing>>"%vbs%"
echo fso.DeleteFile^(Wscript.ScriptFullName^)>>"%vbs%"
echo Wscript.Quit>>"%vbs%"
call "%vbs%"
for /f "delims=" %%i in (%data%) do set "content=%%i"
if exist "%vbs%" del /s /q /f "%data%">nul
if exist "%vbs%" del /s /q /f "%vbs%">nul

if %content%=="" (exit)

set msg=%date% %time%: %content%
git add .
git commit -m "%msg%"
git push
exit
