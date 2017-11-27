cmake_minimum_required(VERSION 3.8)
project(bbfillit)

set(CMAKE_CXX_STANDARD 11)
target_link_libraries (bbfillit libft)
set(SOURCE_FILES

        fillit.h
        main.c
        save_tetramino.c
        get_solution.c
        printout.c
        validate_file.c)

add_executable(bbfillit ${SOURCE_FILES})