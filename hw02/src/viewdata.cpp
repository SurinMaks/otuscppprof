#include "viewdata.hpp"
#include <iostream>

void hw2::ViewData::View1(const std::vector<hw2::IP>& data){
    for(auto& el : data){
        std::cout << el.getIP()<<'\n';
    }
}

void hw2::ViewData::View2(const std::vector<hw2::IP>& data){
    for(auto& el : data){
        if(el.getOct('1') == 1){
            std::cout << el.getIP()<<'\n';
        }
    }
}

void hw2::ViewData::View3(const std::vector<hw2::IP>& data){
    for(auto& el : data){
        if(el.getOct('1') == 46 && el.getOct('2') == 70){
            std::cout << el.getIP()<<'\n';
        }
    }
}

void hw2::ViewData::View4(const std::vector<hw2::IP>& data){
    for(auto& el : data){
        if(el.getOct('1') == 46
            || el.getOct('2') == 46
            || el.getOct('3') == 46
            || el.getOct('4') == 46){
            std::cout << el.getIP()<<'\n';
        }
    }
}