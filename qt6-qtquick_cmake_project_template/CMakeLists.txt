cmake_minimum_required(VERSION 3.20)
set(CPP_VERSION 23)

# Make the project name the name of the project directory
cmake_path(GET CMAKE_CURRENT_LIST_DIR FILENAME ProjectName)   
string(REPLACE " " "_" ProjectName ${ProjectName})

project(${ProjectName} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD ${CPP_VERSION})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(Qt6 COMPONENTS Quick Gui Qml REQUIRED)
qt_standard_project_setup()

qt6_add_resources(qml_QRC src/resources.qrc)
qt6_add_executable(${CMAKE_PROJECT_NAME} src/main.cpp ${qml_QRC})

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE Qt6::Gui Qt6::Quick Qt6::Qml)

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)