#include <iostream>
#include <sstream>
#include <algorithm>

#include "ip.hpp"
#include "viewdata.hpp"

int main(int, char**){
    
    hw2::IP ip;
    hw2::ViewData viewdata;
    std::vector<hw2::IP> ips;
    std::string line;
    while (std::getline(std::cin, line))
    {
        std::istringstream iss(line);
        try
        {
            ip.ReadData(iss);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return{};
        }
            ips.push_back(ip);
    }

    std::sort(ips.begin(), ips.end());

    viewdata.View1(ips);
    viewdata.View2(ips);
    viewdata.View3(ips);
    viewdata.View4(ips);
}
