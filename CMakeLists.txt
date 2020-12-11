cmake_minimum_required(VERSION 3.0.0)
project(Trabalho3 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Trabalho3 main.c fornecido.c queue.c stack.c grafos.c utilizadas.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
