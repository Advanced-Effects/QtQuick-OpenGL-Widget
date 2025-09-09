# QtQuick-OpenGL-Widget
Display an OpenGL context within a QML / QtQuick application.

## Required dependencies

- Qt6 (`Qt6Core`, `Qt6Gui`, `Qt6Quick2` and QML)
- OpenGL (`glfw3`)

## How to use

**1. Download the code.**
- Download the repo and add it to your project.
- Or add the project as a git submodule (`git submodule init` and `git submodule add quickglwidget https://github.com/Advanced-Effects/QtQuick-OpenGL-Widget`)
- **RECOMMENDED:** Download it automatically and hassle-free using CMake `ExternalProject` utility.

**2. Link with your project's main executable and libraries.**
- If you downloaded the project or used git submodules, add this to your main CMakeLists.txt:
```cmake

add_subdirectory(path/to/QtQuick-OpenGL-Widget)

# Your project's target
add_executable(<ReplaceWithYourProjectName> main.cpp)
# Or
add_library(<ReplaceWithYourLibraryName> header.h)

# Link this project with your project
target_link_libraries(<ReplaceWithYourProjectName> PRIVATE QtQuickOpenGLWidget)
target_link_libraries(<ReplaceWithYourLibraryName> PRIVATE QtQuickOpenGLWidget)
```

- If you used `ExternalProject`:

```cmake
# Includes the 'ExternalProject' functions
include(ExternalProject)

ExternalProject_Add(GLWidget # put whatever name you want here
        GIT_URL https://github.com/Advanced-Effects/QtQuick-OpenGL-Widget)

target_link_libraries(<ReplaceWithYourProjectName> PRIVATE GLWidget)
```

**3. How to use in your code**

```cpp
// Somewhere in your application
// (Before the QML engine is loaded, perhaps at main.cpp)
#include <OpenGLWidget.h>
```

```qml
import QtQuick 2.15

import OpenGLWidget 1.0

OpenGLWidget {
        id: root
}
```
