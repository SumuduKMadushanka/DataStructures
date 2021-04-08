:: Cyclic Array compile file
@echo OFF

:: Compile the cpp files
echo Start compile cpp files...
mkdir temp_compile
set /a modified=0
if exist .\object_files\ (
    echo object_files dir already created
) else (
    mkdir object_files
    GOTO :Compile_cyclic_array
)
GOTO :Cyclic_Array

:: Compile the "cyclic_array.cpp"
:Cyclic_Array
if exist .\object_files\cyclic_array.o (
    GOTO :Has_cyclic_array_o
) else (
    GOTO :Compile_cyclic_array
)

:Has_cyclic_array_o
copy .\cyclic_array.cpp .\temp_compile
copy .\object_files\cyclic_array.o .\temp_compile
cd .\temp_compile
for /f %%i in ('dir /b /o:d cyclic_array.o cyclic_array.cpp') do set latest_file=%%i
cd ..
if "%latest_file%"=="cyclic_array.cpp" (
    GOTO :Compile_cyclic_array
) else (
    echo cyclic_array.o already compiled
    GOTO :Main
)

:Compile_cyclic_array
echo Compiling cyclic_array.cpp...
g++ -c ./cyclic_array.cpp -o ./object_files/cyclic_array.o -std=c++11
set /a modified=1
echo Compiling cyclic_array.cpp Completed

:: Compile the "main.cpp"
:Main
if exist .\object_files\main.o (
    GOTO :Has_main_o
) else (
    GOTO :Compile_main
)

:Has_main_o
copy .\main.cpp .\temp_compile
copy .\object_files\main.o .\temp_compile
cd .\temp_compile
for /f %%i in ('dir /b /o:d main.o main.cpp') do set latest_file=%%i
cd ..
if "%latest_file%"=="main.cpp" (
    GOTO :Compile_main
) else (
    echo main.o already compiled
    GOTO :Link_Obj_Files
)

:Compile_main
echo Compiling main.cpp...
g++ -c ./main.cpp -o ./object_files/main.o -std=c++11
set /a modified=1
echo Compiling main.cpp Completed

:: Link the object files
:Link_Obj_Files
if %modified%==1 (
    GOTO :Linking_Obj
) else (
    echo Nothing was modified
    GOTO :End_Compilation
)
:Linking_Obj
echo Linking the object files...
g++ ./object_files/*.o -o CyclicArrayDemo
echo Completed the linking objects

:End_Compilation
echo Completed the compilation
echo Cyclic Array compilation successfull
rmdir /s /q .\temp_compile