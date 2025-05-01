cmake_minimum_required(VERSION 3.26.0)
set(PATCH_VERSION "2" CACHE STRING "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJ_NAME "helloworld_cli")

if(NOT DEFINED PATCH_VERSION)
    set(PATCH_VERSION "0" CACHE STRING "Patch version")
endif()

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/include/version_hw01.hpp.in ${CMAKE_CURRENT_BINARY_DIR}/version_hw01.hpp)

project(${PROJ_NAME} VERSION ${PROJECT_VERSION} LANGUAGES CXX)

add_executable(${PROJ_NAME}  main.cpp src/func.cpp)

target_include_directories(${PROJ_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include ${CMAKE_CURRENT_BINARY_DIR})

# Установка исполняемого файла
install(TARGETS ${PROJ_NAME}
        RUNTIME DESTINATION bin)

# Настройка создания deb-пакета
set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Maxim Surin surin.maks@yandex.ru")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_DESCRIPTION "Simple Hello World CLI application")

include(CPack)