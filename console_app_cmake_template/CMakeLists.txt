CMAKE_MINIMUM_REQUIRED(VERSION 3.30)
set(CPP_VERSION 23)

# Make the project name the name of the project directory
cmake_path(GET CMAKE_CURRENT_LIST_DIR FILENAME ProjectName)   
string(REPLACE " " "_" ProjectName ${ProjectName})

project(${ProjectName} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD ${CPP_VERSION})
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # Provides clangd lsp with compile_commands.json file for it to work better for code editing
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp src/*.cc)
file(GLOB_RECURSE HEADER_FILES src/*.h src/*.hh)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})
target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_${CPP_VERSION})

