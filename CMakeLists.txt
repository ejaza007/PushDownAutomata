cmake_minimum_required(VERSION 3.26)
project(cs203_lab2 C)

set(CMAKE_C_STANDARD 11)

add_executable(pda main.c stack.c list.c pda.c)

add_executable(test_list list.c test_list.c)

add_executable(test_stack stack.c test_stack.c)

add_executable(test_pda pda.c test_pda.c)




