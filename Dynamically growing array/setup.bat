:: Dynamically Growing Array compile file
@echo OFF

:: Compile the cpp files
echo Start compile cpp files...
if exist .\object_files\ (
    echo object_files dir already created
) else (
    mkdir object_files
)
mkdir tmp_c
set /a flag=0
GOTO :Dynamic_grow_array

:: Compile the "dynamic_array.cpp"
:Dynamic_grow_array
if exist .\object_files\dynamic_array.o (
    GOTO :Has_dynamic_array_o
) else (
    GOTO :Compile_dynamic_array
)

:Has_dynamic_array_o
copy .\dynamic_array.cpp .\tmp_c
copy .\object_files\dynamic_array.o .\tmp_c
cd .\tmp_c
for /f %%i in ('dir /b /o:d dynamic_array.o dynamic_array.cpp') do set latest_file=%%i
cd ..
if "%latest_file%"=="dynamic_array.cpp" (
    GOTO :Compile_dynamic_array
) else (
    echo dynamic_array.o already compiled
    GOTO :Link_Obj_Files
)

:Compile_dynamic_array
echo Compiling dynamic_array.cpp...
g++ -c ./dynamic_array.cpp -o ./object_files/dynamic_array.o -std=c++11
set /a flag=1
echo Compiling dynamic_array.cpp Completed

:: Link the object files
:Link_Obj_Files
if %flag%==1 (
    GOTO :Linking_Obj
) else (
    echo Nothing was modified
    GOTO :End_Compilation
)
:Linking_Obj
echo Linking the object files...
g++ ./object_files/*.o -o DynamicArrayDemo
echo Completed the linking objects

:End_Compilation
echo Completed the compilation
echo Dynamic Array compilation successfull
rmdir /s /q .\tmp_c