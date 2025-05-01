#define BOOST_TEST_MODULE VersionTest
#include <boost/test/unit_test.hpp>
#include "../include/func.hpp"

BOOST_AUTO_TEST_CASE(TestVersion) {
    BOOST_CHECK(version() >= 0); // Проверка, что версия не отрицательная
    // Если PATCH_VERSION определен, можно проверить конкретное значение
    // BOOST_CHECK_EQUAL(version(), 2); // Пример для PATCH_VERSION=2
}