cmake_minimum_required(VERSION 3.16)

project(ExpenseCracker C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_COMPILER clang)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)

link_directories(${GTK4_LIBRARY_DIRS})

set(SOURCES
    src/main.c
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE
    inc
    ${GTK4_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    ${GTK4_LIBRARIES}
)

target_compile_options(${PROJECT_NAME} PRIVATE
    -Wall
    -Wextra
    -Wshadow
    ${GTK4_CFLAGS_OTHER}
)
