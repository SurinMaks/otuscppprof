#include <iostream>
#include <map>
#include "MyList.hpp"
#include <memory>
#include "MyAllocatorMap.hpp"
#include "MyAllocatorMyList.hpp"
#include "UniversalAllocator.hpp"

namespace usefull{
    int factorial(int n)
    {
        int res = 1;
        int i;
        for (i = 2; i <= n; i++)
            res *= i;
        return res;
    }
}

int main(int, char**){
    std::cout << "Hello, from hw03.\n";

    size_t MAX_VALUE{10};

    // - создание экземпляра std::map<int, int>
    std::map<int, int> std_map;

    // - заполнение 10 элементами, где ключ - это число от 0 до 9, а значение - факториал ключа
    for(size_t i = 0; i < MAX_VALUE; ++i){
        std_map.emplace(i, usefull::factorial(i));
    }

    // - создание экземпляра std::map<int, int> с новым аллокатором, ограниченным 10 элементами
    std::map<int, int, std::less<int>, hw03::MyAllocatorMap<std::pair<const int, int>, 10>> myMap;
    std::map<int, int, std::less<int>, hw03::UniversalAllocator<std::pair<const int, int>, 10>> myMapU;

    // - заполнение 10 элементами, где ключ - это число от 0 до 9, а значение - факториал ключа
    for(size_t i = 0; i < MAX_VALUE; ++i){
        myMap.emplace(i, usefull::factorial(i));
    }

    for(size_t i = 0; i < MAX_VALUE; ++i){
        myMapU.emplace(i, usefull::factorial(i));
    }
    // - вывод на экран всех значений (ключ и значение разделены пробелом) хранящихся в контейнере
    for(const auto& [key, value] : std_map){
        std::cout << key << ' ' << value << '\n';
    }

    for(const auto& [key, value] : myMap){
        std::cout << key << ' ' << value << '\n';
    }

    for(const auto& [key, value] : myMapU){
        std::cout << key << ' ' << value << '\n';
    }

    // - создание экземпляра своего контейнера для хранения значений типа int
    hw03::MyList<int> mylist;

    // - заполнение 10 элементами от 0 до 9
    for (int i = 0; i < MAX_VALUE; ++i) {
        mylist.push_back(i);
    }

    // - создание экземпляра своего контейнера для хранения значений типа int с новым аллокатором, ограниченным 10 элементами
    hw03::MyList<int, hw03::MyAllocatorMyList<int, 10>> mylist_alloc;
    hw03::MyList<int, hw03::UniversalAllocator<int, 10>> mylistU;

    // - заполнение 10 элементами от 0 до 9
    for (int i = 0; i < MAX_VALUE; ++i) {
        mylist_alloc.push_back(i);
    }

    for (int i = 0; i < MAX_VALUE; ++i) {
        mylistU.push_back(i);
    }

    // - вывод на экран всех значений, хранящихся в контейнере
    for(const auto& el : mylist){
        std::cout << el << ' ';
    }
    std::cout << '\n';

    for(const auto& el : mylist_alloc){
        std::cout << el << ' ';
    }
    std::cout << '\n';

    for(const auto& el : mylistU){
        std::cout << el << ' ';
    }

    // //Пример для vector
    // std::cout << "\nПример для vector\n";
    // std::vector<int, hw03::MyAllocatorMap<int, 10>> myVector;
    // myVector.reserve(MAX_VALUE);
    // for (size_t i = 0; i < MAX_VALUE; ++i) {
    //     myVector.push_back(i);
    // }

    // for (const auto& el : myVector) {
    //     std::cout << el << ' ';
    // }
}
