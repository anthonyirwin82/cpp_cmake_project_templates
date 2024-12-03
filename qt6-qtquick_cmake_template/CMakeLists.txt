cmake_minimum_required(VERSION 3.30)
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

find_package(Qt6 COMPONENTS Quick Gui Qml REQUIRED)
qt_standard_project_setup()

qt6_add_resources(qml_QRC src/resources.qrc)
qt6_add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES} ${qml_QRC})

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE Qt6::Gui Qt6::Quick Qt6::Qml)

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
