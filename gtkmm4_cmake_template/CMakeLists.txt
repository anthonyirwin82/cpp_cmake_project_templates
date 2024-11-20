CMAKE_MINIMUM_REQUIRED(VERSION 3.20)
set(CPP_VERSION 23)

# Make the project name the name of the project directory
cmake_path(GET CMAKE_CURRENT_LIST_DIR FILENAME ProjectName)   
string(REPLACE " " "_" ProjectName ${ProjectName})

project(${ProjectName} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD ${CPP_VERSION})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(PkgConfig)
pkg_check_modules(GTKMM4 REQUIRED gtkmm-4.0)

include_directories(${GTKMM4_INCLUDE_DIRS})
link_directories(${GTKMM4_LIBRARY_DIRS})
add_definitions(${GTKMM4_CFLAGS_OTHER})

add_executable(${CMAKE_PROJECT_NAME} src/main.cpp src/mainwindow.cpp)
target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_${CPP_VERSION})
target_link_libraries(${CMAKE_PROJECT_NAME} ${GTKMM4_LIBRARIES})

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)