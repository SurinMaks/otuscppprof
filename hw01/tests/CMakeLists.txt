cmake_minimum_required(VERSION 3.26.0)

# Поиск Boost и подключение модуля для тестов
find_package(Boost 1.71.0 REQUIRED COMPONENTS unit_test_framework)

# Создание исполняемого файла для тестов
add_executable(test_version test_version.cpp)

# Подключение библиотеки func и зависимостей
target_link_libraries(test_version PRIVATE func Boost::unit_test_framework)