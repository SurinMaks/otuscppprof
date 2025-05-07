cmake_minimum_required(VERSION 3.20)

set(PROJ_NAME lib_ip_filter)

project(${PROJ_NAME} VERSION 0.1.0 LANGUAGES CXX)


add_library(ip SHARED ip.cpp)
target_include_directories(ip
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

add_library(viewdata SHARED viewdata.cpp)
target_include_directories(viewdata
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

target_link_libraries(viewdata PRIVATE ip)