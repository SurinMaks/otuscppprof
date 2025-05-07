cmake_minimum_required(VERSION 3.10.0)

set(PROJ_NAME ip_filter)

project(${PROJ_NAME} VERSION 0.1.0 LANGUAGES C CXX)

option(BOOST_TEST "Whether to build Boost test" ON)

find_package(Boost CONFIG REQUIRED COMPONENTS unit_test_framework)

add_subdirectory(src)

target_include_directories(ip
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include

    viewdata
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(${PROJ_NAME} main.cpp)
target_link_libraries(${PROJ_NAME} PRIVATE ip viewdata)

install(
    TARGETS ${PROJ_NAME} ip viewdata
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

set(CPACK_GENERATOR "DEB")
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_CONTACT "Maxim Surin surin.maks@yandex.ru")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Maxim Surin")
set(CPACK_PACKAGE_DESCRIPTION "IP_FILTER")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "")

include(CPack)

if(BOOST_TEST)
    enable_testing()
    add_subdirectory(tests)
endif()