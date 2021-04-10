:: Binary Tree compile file
@echo OFF

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
    GOTO :Binary_Tree_Cpp
)

:Compile_node
echo Compiling node.cpp...
g++ -c ./node.cpp -o ./object_files/node.o -std=c++11
set /a modified=1
echo Compiling node.cpp Completed

:: Compile the "binary_tree.cpp"
:Binary_Tree_Cpp
if exist .\object_files\binary_tree.o (
    GOTO :Has_binary_tree_o
) else (
    GOTO :Compile_binary_tree
)

:Has_binary_tree_o
copy .\binary_tree.cpp .\temp_compile
copy .\object_files\binary_tree.o .\temp_compile
cd .\temp_compile
for /f %%i in ('dir /b /o:d binary_tree.o binary_tree.cpp') do set latest_file=%%i
cd ..
if "%latest_file%"=="binary_tree.cpp" (
    GOTO :Compile_binary_tree
) else (
    echo binary_tree.o already compiled
    GOTO :Main_Cpp
)

:Compile_binary_tree
echo Compiling binary_tree.cpp...
g++ -c ./binary_tree.cpp -o ./object_files/binary_tree.o -std=c++11
set /a modified=1
echo Compiling binary_tree.cpp Completed

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
g++ ./object_files/*.o -o BinaryTreeDemo
echo Completed the linking objects

:End_Compilation
echo Completed the compilation
echo Binary Tree compilation successfull
rmdir /s /q .\temp_compile