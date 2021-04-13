:: Single Linked List compile file
@echo OFF

:: Clear all compiled files
if "%~1"=="clear" (
    if exist .\object_files\ (
        rmdir /s /q .\object_files
    )
    if exist .\SingleLinkedListDemo.exe (
        del .\SingleLinkedListDemo.exe
    )
    echo Clear all Completed
    GOTO :END
)

:: Compile the cpp files
echo Start compile cpp files...
mkdir temp_compile
set /a modified=0
if exist .\object_files\ (
    echo object_files dir already created
    GOTO :Node_Cpp
) else (
    mkdir object_files
    GOTO :Compile_node
)

:: Compile the "node.cpp"
:Node_Cpp
if exist .\object_files\node.o (
    GOTO :Has_node_o
) else (
    GOTO :Compile_node
)

:Has_node_o
copy .\node.cpp .\temp_compile
copy .\object_files\node.o .\temp_compile
cd .\temp_compile
for /f %%i in ('dir /b /o:d node.o node.cpp') do set latest_file=%%i
cd ..
if "%latest_file%"=="node.cpp" (
    GOTO :Compile_node
) else (
    echo node.o already compiled
    GOTO :Single_linked_list_Cpp
)

:Compile_node
echo Compiling node.cpp...
g++ -c ./node.cpp -o ./object_files/node.o -std=c++11
set /a modified=1
echo Compiling node.cpp Completed

:: Compile the "single_linked_list.cpp"
:Single_linked_list_Cpp
if exist .\object_files\single_linked_list.o (
    GOTO :Has_single_linked_list_o
) else (
    GOTO :Compile_single_linked_list
)

:Has_single_linked_list_o
copy .\single_linked_list.cpp .\temp_compile
copy .\object_files\single_linked_list.o .\temp_compile
cd .\temp_compile
for /f %%i in ('dir /b /o:d single_linked_list.o single_linked_list.cpp') do set latest_file=%%i
cd ..
if "%latest_file%"=="single_linked_list.cpp" (
    GOTO :Compile_single_linked_list
) else (
    echo single_linked_list.o already compiled
    GOTO :Main_Cpp
)

:Compile_single_linked_list
echo Compiling single_linked_list.cpp...
g++ -c ./single_linked_list.cpp -o ./object_files/single_linked_list.o -std=c++11
set /a modified=1
echo Compiling single_linked_list.cpp Completed

:: Compile the "main.cpp"
:Main_Cpp
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
g++ ./object_files/*.o -o SingleLinkedListDemo
echo Completed the linking objects

:End_Compilation
echo Completed the compilation
echo Single Linked List compilation successfull
rmdir /s /q .\temp_compile

:END