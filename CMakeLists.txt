cmake_minimum_required(VERSION 3.7)
project(CompOrgProject)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Load_Program.h
        main.c
        main.h
        MEM.c MEM.h WB.c WB.h IF.c IF.h ID.h ID.c EX.h EX.c)

add_executable(CompOrgProject ${SOURCE_FILES})