cmake_minimum_required(VERSION 3.26.0)
set(PROJ_NAME test_ip_filter)

# Поиск Boost и подключение модуля для тестов
find_package(Boost 1.71.0 CONFIG REQUIRED COMPONENTS unit_test_framework)

# Создание исполняемого файла для тестов
add_executable(${PROJ_NAME} test_ip.cpp)
target_link_libraries(${PROJ_NAME} PRIVATE ip viewdata func Boost::unit_test_framework)

# Добавляем тест в CTest
add_test(NAME ${PROJ_NAME} COMMAND IPTest)