cmake_minimum_required(VERSION 3.6)
project(property_browser)

set(SOURCE_FILES
        UIPropertyBrowser.cpp
        UIPropertyBrowserItem.cpp
        )

add_library(property_browser ${SOURCE_FILES})

target_link_libraries(property_browser Qt5::Widgets)
