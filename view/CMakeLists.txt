cmake_minimum_required(VERSION 3.6)
project(view)

set(SOURCE_FILES
        UITreeViewItem.cpp
        )

add_library(view ${SOURCE_FILES})

target_link_libraries(view Qt5::Widgets)
