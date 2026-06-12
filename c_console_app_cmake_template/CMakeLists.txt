cmake_minimum_required(VERSION 3.30)

# Make the project name the name of the project directory
cmake_path(GET CMAKE_CURRENT_LIST_DIR FILENAME ProjectName)
string(REPLACE " " "_" ProjectName ${ProjectName})

set(C_VERSION 23)
set(CMAKE_C_STANDARD ${C_VERSION})
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/src FILES ${SOURCE_FILES} ${HEADER_FILES})

project(${ProjectName} LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Recursively scan for C source and header files
file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS src/*.c)
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS src/*.h)

add_executable(${CMAKE_PROJECT_NAME})

# Add source and header files
target_sources(${CMAKE_PROJECT_NAME} PRIVATE ${SOURCE_FILES} ${HEADER_FILES})
