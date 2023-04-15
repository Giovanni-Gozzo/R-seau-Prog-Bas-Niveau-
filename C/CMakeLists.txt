cmake_minimum_required(VERSION 3.23)
project(c C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(TD1)
include_directories(TD2)

add_executable(c
        TD1/fgets.c
        TD1/palindrome.c
        TD1/pointeur.c
        TD1/simple.c
        TD1/structure.c
        TD1/tailleTab.c
        TD2/Minmax.c
        TD2/tabDynamique.c
        TD2/Matrices.c
        TD3/copy.c
        TD3/lireligne.c
        TD3/mygetc.c
        TD3/readfile.c
        )
