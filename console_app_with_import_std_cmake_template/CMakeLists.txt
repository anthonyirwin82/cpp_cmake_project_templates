CMAKE_MINIMUM_REQUIRED(VERSION 4.0)

# Make the project name the name of the project directory
cmake_path(GET CMAKE_CURRENT_LIST_DIR FILENAME ProjectName)   
string(REPLACE " " "_" ProjectName ${ProjectName})

set(CPP_VERSION 23)
set(CMAKE_CXX_STANDARD ${CPP_VERSION})
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD 
  # This specific value changes as experimental support evolves. See
  # `Help/dev/experimental.rst` in the CMake source corresponding to
  # your CMake build for the exact value to use.
  "d0edc3af-4c50-42ea-a356-e2862fe7a444")

set(CMAKE_CXX_MODULE_STD ON)

project(${ProjectName} LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # Provides clangd lsp with compile_commands.json file for it to work better for code editing
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Recursively scan for module, source and header files.
file(GLOB_RECURSE MODULE_FILES CONFIGURE_DEPENDS src/*.cppm src/*.cpm src/*.ixx)
file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS src/*.cpp src/*.cc)
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS src/*.h src/*.hh)

add_executable(${CMAKE_PROJECT_NAME})

# Add source and header files.
target_sources(${CMAKE_PROJECT_NAME} PRIVATE ${SOURCE_FILES} ${HEADER_FILES})

# Add module interface sources in a proper file set
target_sources(${CMAKE_PROJECT_NAME} PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES ${MODULE_FILES})

target_compile_options(${PROJECT_NAME} PRIVATE
    -Wall
    -Wextra
    -fdiagnostics-color=always
)
