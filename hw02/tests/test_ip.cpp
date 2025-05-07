#define BOOST_TEST_MODULE HW2TestIP
#include <boost/test/unit_test.hpp>
#include <sstream>
#include <iostream>
#include "../include/ip.hpp"

BOOST_AUTO_TEST_SUITE(IPTest)

    BOOST_AUTO_TEST_CASE(test_getIP) {
        hw2::IP ip1;
        std::istringstream iss1("192.168.1.1");
        ip1.ReadData(iss1);

        BOOST_CHECK_EQUAL(ip1.getIP(), "192.168.1.1");
    }

    BOOST_AUTO_TEST_CASE(test_Sort) {
        hw2::IP ip1, ip2;
        std::vector<hw2::IP> ips;
        std::istringstream iss1("192.168.1.1\t1.1.1.1");
        std::istringstream iss2("192.168.1.2\t2.2.2.2");
        ip1.ReadData(iss1);
        ip2.ReadData(iss2);
        ips.push_back(ip1);
        ips.push_back(ip2);
        std::sort(ips.begin(), ips.end());
        BOOST_TEST(ips[0].getIP() == "192.168.1.2");
        BOOST_TEST(ips[1].getIP() == "192.168.1.1");
    }

BOOST_AUTO_TEST_SUITE_END()