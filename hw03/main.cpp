#include <iostream>
#include <map>
#include "MyList.hpp"

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
    std::cout << "Hello, from hw03!\n";

    size_t MAX_VALUE{10};

    // - создание экземпляра std::map<int, int>
    std::map<int, int> std_map;

    // - заполнение 10 элементами, где ключ - это число от 0 до 9, а значение - факториал ключа
    for(size_t i = 0; i < MAX_VALUE; ++i){
        std_map.emplace(i, usefull::factorial(i));
    }

    // - создание экземпляра std::map<int, int> с новым аллокатором, ограниченным 10 элементами
    // - заполнение 10 элементами, где ключ - это число от 0 до 9, а значение - факториал ключа
    // - вывод на экран всех значений (ключ и значение разделены пробелом) хранящихся в контейнере
    for(const auto& [key, value] : std_map){
        std::cout << key << ' ' << value << '\n';
    }

    // - создание экземпляра своего контейнера для хранения значений типа int
    hw03::MyList<int> mylist;

    // - заполнение 10 элементами от 0 до 9
    for(size_t i = 0; i < MAX_VALUE; ++i){
        mylist.push_back(i);
    }
    // - создание экземпляра своего контейнера для хранения значений типа int с новым аллокатором, ограниченным 10 элементами
    // - заполнение 10 элементами от 0 до 9
    // - вывод на экран всех значений, хранящихся в контейнере
    mylist.printList();
}
