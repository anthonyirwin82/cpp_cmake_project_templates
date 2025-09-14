CMAKE_MINIMUM_REQUIRED(VERSION 3.30)

# Make the project name the name of the project directory
cmake_path(GET CMAKE_CURRENT_LIST_DIR FILENAME ProjectName)   
string(REPLACE " " "_" ProjectName ${ProjectName})

set(CPP_VERSION 23)
set(CMAKE_CXX_STANDARD ${CPP_VERSION})
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

project(${ProjectName} LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # Provides clangd lsp with compile_commands.json file for it to work better for code editing
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Recursively scan for module, source and header files.
file(GLOB_RECURSE MODULE_FILES CONFIGURE_DEPENDS src/*.cppm)
file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS src/*.cpp src/*.cc)
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS src/*.h src/*.hh)

add_executable(${CMAKE_PROJECT_NAME})
target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_${CPP_VERSION} INTERFACE cxx_std_${CPP_VERSION})

# Add source and header files.
target_sources(${CMAKE_PROJECT_NAME} PRIVATE ${SOURCE_FILES} ${HEADER_FILES})

# Add module interface sources in a proper file set
target_sources(${CMAKE_PROJECT_NAME} PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES ${MODULE_FILES})

