cmake_minimum_required(VERSION 3.20)

project(hw06_lib_matrix VERSION 0.1.0 LANGUAGES CXX)

foreach(LIB_NAME Matrix ProxyMatrix)
    add_library(${LIB_NAME} STATIC ${LIB_NAME}.cpp)
    target_include_directories(${LIB_NAME} PUBLIC ${INCLUDE_DIR})
endforeach()
