cmake_minimum_required(VERSION 4.3)
project(Organizer C)

set(CMAKE_C_STANDARD 23)

add_executable(Organizer src/main.c
        src/directory.c
        include/directory.h
        src/fileUtils.c
        include/fileUtils.h
        src/systemOperations.c
        include/systemOperations.h)
