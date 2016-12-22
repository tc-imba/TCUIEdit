cmake_minimum_required(VERSION 3.6)
project(core)

include(base/CMakeLists.txt)

include(package/CMakeLists.txt)

set(SOURCE_FILES
        UIProject.cpp
        ${SOURCE_FILES_PACKAGE}
        UIMap.cpp
        ${SOURCE_FILES_BASE}
        UIException.cpp
        UIFileInput.cpp
        )

add_library(core ${SOURCE_FILES})

target_link_libraries(core Qt5::Widgets)
