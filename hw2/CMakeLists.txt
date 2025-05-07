cmake_minimum_required(VERSION 3.10.0)

set(PROJ_NAME ip_filter)

project(${PROJ_NAME} VERSION 0.1.0 LANGUAGES CXX)

option(BOOST_TEST "Whether to build Boost test" ON)
option(RPATH "Set RPATH" ON)

if(${RPATH})
    set(CMAKE_INSTALL_RPATH "$ORIGIN/../lib")
    set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
    set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
endif()

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

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

install(TARGETS ${PROJ_NAME}
    DESTINATION /opt/hw2/bin
)

install(TARGETS ip viewdata
    LIBRARY DESTINATION /opt/hw2/lib
)

# Скрипты для управления симлинком
set(POSTINST_SCRIPT "${CMAKE_CURRENT_BINARY_DIR}/postinst")
set(PRERM_SCRIPT "${CMAKE_CURRENT_BINARY_DIR}/prerm")

# Скрипт postinst (создает симлинк)
file(WRITE ${POSTINST_SCRIPT} "#!/bin/sh\n"
    "ln -sf /opt/hw2/bin/${PROJ_NAME} /usr/bin/${PROJ_NAME}\n"
    "exit 0\n"
)

# Скрипт prerm (удаляет симлинк)
file(WRITE ${PRERM_SCRIPT} "#!/bin/sh\n"
    "if [ \"\$1\" = \"remove\" ]; then\n"
    "    rm -f /usr/bin/${PROJ_NAME}\n"
    "fi\n"
    "exit 0\n"
)

# Права на выполнение
install(CODE "execute_process(COMMAND chmod +x ${POSTINST_SCRIPT} ${PRERM_SCRIPT})")

# Добавляем скрипты в пакет
set(CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA
    "${POSTINST_SCRIPT};${PRERM_SCRIPT}"
)

set(CPACK_GENERATOR "DEB")
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_CONTACT "Maxim Surin surin.maks@yandex.ru")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Maxim Surin")
set(CPACK_PACKAGE_DESCRIPTION "IP_FILTER")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "")

install(DIRECTORY DESTINATION /opt/hw2/lib)
install(DIRECTORY DESTINATION /opt/hw2/bin)

include(CPack)

if(BOOST_TEST)
    enable_testing()
    add_subdirectory(tests)
endif()