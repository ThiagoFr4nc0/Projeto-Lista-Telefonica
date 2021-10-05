cmake_minimum_required(VERSION 3.20)
project(Projeto_Lista_Telefonica C)

set(CMAKE_C_STANDARD 99)

add_executable(Projeto_Lista_Telefonica main.c lista.h lista.c utilitarios.c utilitarios.h)
