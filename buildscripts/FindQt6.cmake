# What is needed to find Qt in the system library?

# 1. The tool we use to grab libraries from the system is called `pkg-config`
# (from package-configuration). CMake includes a script that lets you use it with functions
# (instead of using the CLI directly)

include(UsePkgConfig)

# 2. Qt is not a single library. It's a collection of .DLLs in the system
# located in a folder called the `MODULE_PREFIX_PATH`.
# (e.g.) Qt6Core, Qt6Gui, Qt6Quick...

# We could write out each library component: find_package(Qt6Core), Qt6Gui...
# But it's more flexible to write out the components and the qt version using variables.
# find_package(Qt${QT_VERSION}${QT_COMPONENT})

set(QT_VERSION 6)
set(QT_COMPONENTS
        Core
        Gui
        Quick2)

# Include each component
foreach(QT_COMPONENT ${QT_COMPONENTS})
        find_package(Qt${QT_VERSION}${QT_COMPONENT} REQUIRED) # Qt6Core, etc...
endforeach()
