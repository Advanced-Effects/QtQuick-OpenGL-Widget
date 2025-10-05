cmake_minimum_required(VERSION 3.20)

project(QtQuickOpenGLWidget
        LANGUAGES C CXX
        VERSION 1.0)

# Tell CMake where to find buildscripts
# So if we `include(SomeScript)`, it will look for in `<project folder>/buildscripts/SomeScript.cmake`

set(CMAKE_MODULE_PATH
        ${PROJECT_SOURCE_DIR}/buildscripts)

# Requirements: Qt and OpenGL

# Find Qt6
find_package(Qt6 REQUIRED COMPONENTS Core Gui Quick QuickWidgets QuickControls2)
qt_standard_project_setup()

# Find GLFW
include(FindGLFW)

# Add our code

qt_add_library(${CMAKE_PROJECT_NAME} STATIC
        src/OpenGLWidget.h
        src/OpenGLWidget.cpp
)

# Link the library with dependencies

set(LIBRARY_DEPENDENCIES
        Qt6::Core
        Qt6::Gui
        Qt6::Quick
        Qt6::QuickWidgets
        Qt6::QuickControls2
        glfw3)

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC ${LIBRARY_DEPENDENCIES})
