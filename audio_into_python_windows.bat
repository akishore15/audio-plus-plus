@echo off
setlocal enabledelayedexpansion

:: Define the Python script location
set PYTHON_SCRIPT=process_audio.py

:: Scan drives and process MP3 files
for %%d in (A B C D E F G H I J K L M N O P Q R S T U V W X Y Z) do (
    if exist %%d:\ (
        echo Scanning drive %%d:\
        for /r %%f in (%%d:\*.mp3) do (
            echo Processing %%f
            python %PYTHON_SCRIPT% "%%f"
        )
    )
)

echo All files processed.
pause
