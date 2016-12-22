cmake_minimum_required(VERSION 3.6)
project(core)

set(SOURCE_FILES_BASE
        base/UIBase.cpp
        base/UIBase_Category.cpp
        base/UIBase_Type.cpp
        base/UIBase_TypeDefault.cpp
        base/UIBase_Param.cpp
        base/UIBase_Event.cpp
        base/UIBase_Condition.cpp
        )

set(SOURCE_FILES_PACKAGE
        package/UIPackage.cpp
        package/UIPackage_WEString.cpp
        package/UIPackage_Category.cpp
        package/UIPackage_Base.cpp
        package/UIPackage_Type.cpp
        package/UIPackage_TypeDefault.cpp
        package/UIPackage_Param.cpp
        package/UIPackage_Event.cpp
        package/UIPackage_Condition.cpp
        )

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
