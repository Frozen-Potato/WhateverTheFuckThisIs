cmake_minimum_required(VERSION 3.16)
project(LibrarySystem CXX)

# General Settings

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_VERBOSE_MAKEFILE ON)

# Include Directories

include_directories(
    ${PROJECT_SOURCE_DIR}/includes
    ${PROJECT_SOURCE_DIR}/includes/Interface
    ${PROJECT_SOURCE_DIR}/includes/db
    ${PROJECT_SOURCE_DIR}/includes/external/cpp-httplib
    ${PROJECT_SOURCE_DIR}/ultis
    /usr/local/include            # for libpqxx & mongocxx
    /usr/include/postgresql
)

# Source Files

file(GLOB_RECURSE SOURCES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/ultis/*.cpp
    ${PROJECT_SOURCE_DIR}/src/db/*.cpp
    ${PROJECT_SOURCE_DIR}/main.cpp
)

# Exclude REST server (it has its own main)
list(REMOVE_ITEM SOURCES "${PROJECT_SOURCE_DIR}/src/server/RestServer.cpp")

add_executable(library_app ${SOURCES})

# Library Search Paths

link_directories(
    /usr/local/lib
    /usr/lib/x86_64-linux-gnu
)

# PostgreSQL + libpqxx

find_package(PostgreSQL REQUIRED)

if (EXISTS "/usr/local/lib/libpqxx.so")
    message(STATUS "Using custom libpqxx from /usr/local/lib")
    set(PQXX_LIB /usr/local/lib/libpqxx.so)
else()
    message(WARNING "Falling back to system libpqxx")
    set(PQXX_LIB pqxx)
endif()

# MongoDB (libmongocxx / libbsoncxx)

find_package(PkgConfig REQUIRED)
pkg_check_modules(MONGOCXX REQUIRED libmongocxx)
pkg_check_modules(BSONCXX REQUIRED libbsoncxx)

include_directories(${MONGOCXX_INCLUDE_DIRS} ${BSONCXX_INCLUDE_DIRS})
link_directories(${MONGOCXX_LIBRARY_DIRS} ${BSONCXX_LIBRARY_DIRS})

# Link Core Executable

target_link_libraries(library_app
    PRIVATE
        ${PQXX_LIB}
        pq
        ${MONGOCXX_LIBRARIES}
        ${BSONCXX_LIBRARIES}
)

# Platform Specifics

if (WIN32)
    message(STATUS "Building for Windows (MSYS2 detected)")
    add_definitions(-DWIN32_LEAN_AND_MEAN)
    target_link_libraries(library_app PRIVATE ws2_32)
elseif(UNIX)
    message(STATUS "Building for Linux / WSL environment")
endif()


# Optional Install Rule

install(TARGETS library_app RUNTIME DESTINATION bin)

# REST API Server (cpp-httplib)

find_package(nlohmann_json REQUIRED)

list(REMOVE_ITEM SOURCES "${PROJECT_SOURCE_DIR}/main.cpp")

add_executable(library_server
    src/server/RestServer.cpp
    ${SOURCES}
)

# Add cpp-httplib header include
target_include_directories(library_server PRIVATE
    ${CMAKE_SOURCE_DIR}/includes
    ${CMAKE_SOURCE_DIR}/includes/external/cpp-httplib
)

# Link with same backend libs
target_link_libraries(library_server
    PRIVATE
        ${PQXX_LIB}
        pq
        ${MONGOCXX_LIBRARIES}
        ${BSONCXX_LIBRARIES}
        nlohmann_json::nlohmann_json
)


# Final Messages

message(STATUS "Configuration complete")
