cmake_minimum_required(VERSION 3.6)
project(core)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_PREFIX_PATH "D:\\Qt\\Qt5.7.0\\5.7\\mingw53_32")

find_package(Qt5Widgets REQUIRED)

set(SOURCE_FILES_BASE
        base/UIBase.cpp
        base/UIBase_Category.cpp
        base/UIBase_Type.cpp base/UIBase_Type.h)

set(SOURCE_FILES_PACKAGE
        package/UIPackage.cpp
        package/UIPackage_Category.cpp
        package/UIPackage_Base.cpp
        package/UIPackage_Type.cpp package/UIPackage_Type.h)

set(SOURCE_FILES
        UIProject.cpp
        ${SOURCE_FILES_PACKAGE}
        UIMap.cpp
        ${SOURCE_FILES_BASE}
        UIException.cpp
        )

add_library(core ${SOURCE_FILES})

target_link_libraries(core Qt5::Widgets)
