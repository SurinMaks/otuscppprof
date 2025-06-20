cmake_minimum_required(VERSION 3.10.0)
project(hw03 VERSION 0.1.0 LANGUAGES C CXX)

add_executable(hw03 main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(CPACK_GENERATOR "DEB")
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_CONTACT "Maxim Surin surin.maks@yandex.ru")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Maxim Surin")
set(CPACK_PACKAGE_DESCRIPTION "otus_cpp_hw03")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "")

include(CPack)
