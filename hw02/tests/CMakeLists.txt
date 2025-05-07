cmake_minimum_required(VERSION 3.26.0)
set(PROJ_NAME test_ip_filter)

# Поиск Boost и подключение модуля для тестов
find_package(Boost 1.71.0 CONFIG REQUIRED COMPONENTS unit_test_framework)

# Для test_ip.cpp
add_executable(test_ip test_ip.cpp)
target_link_libraries(test_ip PRIVATE ip viewdata func Boost::unit_test_framework)
add_test(NAME IPTest COMMAND test_ip)

# # Для test_viewdata.cpp
# add_executable(test_viewdata test_viewdata.cpp)
# target_link_libraries(test_viewdata PRIVATE ip viewdata func Boost::unit_test_framework)
# add_test(NAME ViewDataTest COMMAND test_viewdata)