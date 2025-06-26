cmake_minimum_required(VERSION 3.16)
project(queue)

include_directories( 
    "include"
    "/home/user/boost_lib/include"
)

# sources list
set(
    CMAKE_CURRENT_PROJECT_SOURCES_LIST
)

# project base sources
list(
    APPEND
    CMAKE_CURRENT_PROJECT_SOURCES_LIST
    source/main.cpp
    source/queue_lifo.cpp
    source/queue_element.cpp
)

add_executable(
    queue
    ${CMAKE_CURRENT_PROJECT_SOURCES_LIST}
)

target_link_libraries(
    ${PROJECT_NAME}
    /home/user/boost_lib/lib/libboost_filesystem.a
)

set_target_properties( 
    queue
    PROPERTIES
    PREFIX "_app_"
    OUTPUT_NAME "queue"
    SUFFIX ".exec"
)