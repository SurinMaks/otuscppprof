cmake_minimum_required(VERSION 3.10.0)
set(PATCH_VERSION "2" CACHE STRING "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/include/version_hw01.hpp.in ${CMAKE_CURRENT_BINARY_DIR}/version_hw01.hpp)

project(helloworld_cli VERSION ${PROJECT_VERSION} LANGUAGES C CXX)

add_executable(helloworld_cli main.cpp src/func.cpp)

target_include_directories(helloworld_cli PRIVATE ${CMAKE_SOURCE_DIR}/include ${CMAKE_CURRENT_BINARY_DIR})

# Установка исполняемого файла
install(TARGETS helloworld_cli
        RUNTIME DESTINATION bin)

# Настройка создания deb-пакета
set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Maxim Surin surin.maks@yandex.ru")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_DESCRIPTION "Simple Hello World CLI application")

include(CPack)