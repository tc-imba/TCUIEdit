cmake_minimum_required(VERSION 3.6)
project(property_browser)

set(SOURCE_FILES
        Browser.cpp
        Model.cpp
        Item.cpp
        Category.cpp
        common.h)

add_library(property_browser ${SOURCE_FILES})

target_link_libraries(property_browser Qt5::Widgets)
