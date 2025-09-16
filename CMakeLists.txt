cmake_minimum_required(VERSION 3.20)

project(QtQuickOpenGLWidget
        LANGUAGES C CXX
        VERSION 1.0)

# Tell CMake where to find buildscripts
# So if we `include(SomeScript)`, it will look for in `<project folder>/buildscripts/SomeScript.cmake`

set(CMAKE_MODULE_PATH
        ${PROJECT_SOURCE_DIR}/buildscripts)

# Requirements: Qt and OpenGL

include(FindQt6)
include(FindGLFW)

# Add our code

add_library(${CMAKE_PROJECT_NAME} STATIC
        src/OpenGLWidget.h
        src/OpenGLWidget.cpp
)

# Link the library with dependencies

set(LIBRARY_DEPENDENCIES
        Qt6Core
        Qt6Gui
        Qt6Quick
        Qt6QuickControls2
        glfw3)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${LIBRARY_DEPENDENCIES})
