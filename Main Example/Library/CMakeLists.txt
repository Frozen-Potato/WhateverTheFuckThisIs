cmake_minimum_required(VERSION 3.20)
project(library_app LANGUAGES CXX)

# Require C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Add warnings
if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# --- Include directories ---
include_directories(
    ${CMAKE_SOURCE_DIR}/includes
    ${CMAKE_SOURCE_DIR}/includes/Interface
    ${CMAKE_SOURCE_DIR}/includes/db
    ${CMAKE_SOURCE_DIR}/ultis
)

# --- Source files ---
file(GLOB SRC_FILES
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/ultis/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/db/*.cpp"
)

add_executable(${PROJECT_NAME}
    ${SRC_FILES}
    main.cpp
)

# --- Threads ---
find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)

# --- PostgreSQL (libpqxx) ---
find_package(PkgConfig REQUIRED)
pkg_check_modules(PQXX REQUIRED libpqxx)

include_directories(${PQXX_INCLUDE_DIRS})
link_directories(${PQXX_LIBRARY_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${PQXX_LIBRARIES})

# --- Platform-specific options ---
if (WIN32)
    add_definitions(-DWIN32_LEAN_AND_MEAN)
endif()

# --- Output ---
message(STATUS "Building Library Management System with PostgreSQL & Threads")
message(STATUS "Include dirs: ${CMAKE_SOURCE_DIR}/includes")
