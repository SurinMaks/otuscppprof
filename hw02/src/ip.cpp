#include <iostream>
#include <sstream>
#include <limits>
#include "ip.hpp"

void hw2::IP::ReadData(std::istream& input){
    char dot{'.'};
    unsigned int o1{0}, o2{0},o3{0},o4{0};
    unsigned int max_value{255};
    input >> o1 >> dot
            >> o2 >> dot
            >> o3 >> dot
            >> o4;

    if(o1 > max_value || o2 > max_value || o3 > max_value || o4 > max_value){
        throw std::out_of_range("Octet value out of range");
    }

    input.ignore(std::numeric_limits<std::streamsize>::max(), '\t');

    ip_addr_.m_oct1 = static_cast<uint8_t>(o1);
    ip_addr_.m_oct2 = static_cast<uint8_t>(o2);
    ip_addr_.m_oct3 = static_cast<uint8_t>(o3);
    ip_addr_.m_oct4 = static_cast<uint8_t>(o4);

}

std::string hw2::IP::getIP() const {
    std::ostringstream oss;
    oss << static_cast<unsigned int>(ip_addr_.m_oct1) << '.'
        << static_cast<unsigned int>(ip_addr_.m_oct2) << '.'
        << static_cast<unsigned int>(ip_addr_.m_oct3) << '.'
        << static_cast<unsigned int>(ip_addr_.m_oct4);
    return oss.str();
}

uint8_t hw2::IP::getOct(uint8_t value) const {
    switch (value)
    {
    case '1':
        return ip_addr_.m_oct1;
        break;
    case '2':
        return ip_addr_.m_oct2;
        break;
    case '3':
        return ip_addr_.m_oct3;
        break;
    case '4':
        return ip_addr_.m_oct4;
        break;
    default:
        throw std::out_of_range("Octet number out of range");
        break;
    }
    return{};
}

bool hw2::IP::operator<(const IP& other){
    return std::tie(other.ip_addr_.m_oct1, other.ip_addr_.m_oct2, other.ip_addr_.m_oct3, other.ip_addr_.m_oct4)
        < std::tie(ip_addr_.m_oct1,ip_addr_.m_oct2,ip_addr_.m_oct3,ip_addr_.m_oct4);
}