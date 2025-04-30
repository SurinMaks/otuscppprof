cmake_minimum_required(VERSION 3.10.0)
project(helloworld_cli VERSION 0.1.0 LANGUAGES C CXX)

add_executable(helloworld_cli main.cpp)

# Установка исполняемого файла
install(TARGETS helloworld_cli
        RUNTIME DESTINATION bin)

# Настройка создания deb-пакета
set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Maxim Surin surin.maks@yandex.ru")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_DESCRIPTION "Simple Hello World CLI application")
# set(CPACK_DEBIAN_PACKAGE_DEPENDS "")  # Зависимости

include(CPack)