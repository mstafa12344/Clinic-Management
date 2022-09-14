cmake_minimum_required(VERSION 3.22)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled main.c logain/logain.c logain/logain.h STD_Types.h admin/admin.c admin/admin.h user_mode/user_mode.c user_mode/user_mode.h)
