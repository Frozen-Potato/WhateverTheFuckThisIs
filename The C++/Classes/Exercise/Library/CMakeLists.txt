cmake_minimum_required(VERSION 4.1.1)
project(library_app LANGUAGES CXX)

# Require C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Warnings
if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra)
endif()

# Include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/includes
    ${CMAKE_SOURCE_DIR}/includes/Interface
    ${CMAKE_SOURCE_DIR}/ultis
)

# Collect all source files
file(GLOB SRC_FILES
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/ultis/*.cpp"
)

# Executable target
add_executable(${PROJECT_NAME}
    ${SRC_FILES}
    main.cpp
)
