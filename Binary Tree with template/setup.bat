:: Binary Tree with Template compile file
@echo OFF

if "%~1"=="clear" (
    if exist .\object_files\ (
        rmdir /s /q .\object_files
    )
    if exist .\BinaryTreeTemplateDemo.exe (
        del .\BinaryTreeTemplateDemo.exe
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
    GOTO :Node_template_Cpp
) else (
    mkdir object_files
    GOTO :Compile_node_template
)

:: Compile the "node_template.cpp"
:Node_template_Cpp
if exist .\object_files\node_template.o (
    GOTO :Has_node_template_o
) else (
    GOTO :Compile_node_template
)

:Has_node_template_o
copy .\node_template.cpp .\temp_compile
copy .\object_files\node_template.o .\temp_compile
cd .\temp_compile
for /f %%i in ('dir /b /o:d node_template.o node_template.cpp') do set latest_file=%%i
cd ..
if "%latest_file%"=="node_template.cpp" (
    GOTO :Compile_node_template
) else (
    echo node_template.o already compiled
    GOTO :Binary_Tree_template_Cpp
)

:Compile_node_template
echo Compiling node_template.cpp...
g++ -c ./node_template.cpp -o ./object_files/node_template.o -std=c++11
set /a modified=1
echo Compiling node_template.cpp Completed

:: Compile the "binary_tree_template.cpp"
:Binary_Tree_template_Cpp
if exist .\object_files\binary_tree_template.o (
    GOTO :Has_binary_tree_template_o
) else (
    GOTO :Compile_binary_tree_template
)

:Has_binary_tree_template_o
copy .\binary_tree_template.cpp .\temp_compile
copy .\object_files\binary_tree_template.o .\temp_compile
cd .\temp_compile
for /f %%i in ('dir /b /o:d binary_tree_template.o binary_tree_template.cpp') do set latest_file=%%i
cd ..
if "%latest_file%"=="binary_tree_template.cpp" (
    GOTO :Compile_binary_tree_template
) else (
    echo binary_tree_template.o already compiled
    GOTO :Main_Cpp
)

:Compile_binary_tree_template
echo Compiling binary_tree_template.cpp...
g++ -c ./binary_tree_template.cpp -o ./object_files/binary_tree_template.o -std=c++11
set /a modified=1
echo Compiling binary_tree_template.cpp Completed

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
g++ ./object_files/*.o -o BinaryTreeTemplateDemo
echo Completed the linking objects

:End_Compilation
echo Completed the compilation
echo Binary Tree with Template compilation successfull
rmdir /s /q .\temp_compile

:END