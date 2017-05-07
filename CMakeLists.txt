cmake_minimum_required(VERSION 3.7)
project(CompOrgProject)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.c
        main.h
        MEM.c MEM.h WB.c WB.h IF.c IF.h ID.h ID.c EX.h EX.c Load_Program.c Load_Program.h clock_cycle.c clock_cycle.h Shadow_to_Pipeline.c Shadow_to_Pipeline.h Hazard.c Hazard.h)

add_executable(CompOrgProject ${SOURCE_FILES})