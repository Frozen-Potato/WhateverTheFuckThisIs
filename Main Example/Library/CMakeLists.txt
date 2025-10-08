cmake_minimum_required(VERSION 3.16)
project(LibrarySystem CXX)


#  General settings

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Allow verbose output during linking (useful for debugging)
set(CMAKE_VERBOSE_MAKEFILE ON)


#  Include directories

include_directories(
    ${PROJECT_SOURCE_DIR}/includes
    ${PROJECT_SOURCE_DIR}/includes/Interface
    ${PROJECT_SOURCE_DIR}/includes/db
    ${PROJECT_SOURCE_DIR}/ultis
    /usr/local/include           # for libpqxx and mongocxx
    /usr/include/postgresql
)


#  Source files

file(GLOB_RECURSE SOURCES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/ultis/*.cpp
    ${PROJECT_SOURCE_DIR}/src/db/*.cpp
    ${PROJECT_SOURCE_DIR}/main.cpp
)

add_executable(library_app ${SOURCES})


# Link directories (priority to /usr/local/lib)

link_directories(
    /usr/local/lib
    /usr/lib/x86_64-linux-gnu
)


# PostgreSQL and libpqxx

find_package(PostgreSQL REQUIRED)

# Prefer manually built libpqxx
if (EXISTS "/usr/local/lib/libpqxx.so")
    message(STATUS "Using custom libpqxx from /usr/local/lib")
    set(PQXX_LIB "/usr/local/lib/libpqxx.so")
else()
    message(WARNING "Falling back to system libpqxx")
    set(PQXX_LIB "pqxx")
endif()


# MongoDB (libmongocxx and libbsoncxx)

# If you installed with /usr/local
find_package(PkgConfig REQUIRED)
pkg_check_modules(MONGOCXX REQUIRED libmongocxx)
pkg_check_modules(BSONCXX REQUIRED libbsoncxx)

include_directories(${MONGOCXX_INCLUDE_DIRS} ${BSONCXX_INCLUDE_DIRS})
link_directories(${MONGOCXX_LIBRARY_DIRS} ${BSONCXX_LIBRARY_DIRS})


# Link all dependencies

target_link_libraries(library_app
    PRIVATE
        ${PQXX_LIB}
        pq
        ${MONGOCXX_LIBRARIES}
        ${BSONCXX_LIBRARIES}
)


#  Platform-specific tweaks

if (WIN32)
    message(STATUS "Building for Windows (MSYS2 detected)")
    add_definitions(-DWIN32_LEAN_AND_MEAN)
    target_link_libraries(library_app PRIVATE ws2_32)
elseif(UNIX)
    message(STATUS "Building for Linux / WSL environment")
endif()


# Installation (optional)

install(TARGETS library_app RUNTIME DESTINATION bin)
