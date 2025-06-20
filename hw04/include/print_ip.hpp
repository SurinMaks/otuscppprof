#ifndef PRINT_IP_HPP_
#define PRINT_IP_HPP_

#include <iostream>
#include <type_traits>
#include <vector>
#include <list>
#include <string>
#include <tuple>
#include <climits>

namespace hw04 {
    // Вспомогательные структуры
    template<typename>
    struct is_std_vector : std::false_type {};

    template<typename T>
    struct is_std_vector<std::vector<T>> : std::true_type {};

    template<typename>
    struct is_std_list : std::false_type {};

    template<typename T>
    struct is_std_list<std::list<T>> : std::true_type {};

    template<typename T>
    struct is_container {
        static const bool value = is_std_vector<T>::value || is_std_list<T>::value;
    };

    template<typename...>
    struct are_all_same : std::true_type {};

    template<typename T1, typename T2, typename... Ts>
    struct are_all_same<T1, T2, Ts...> :
        std::conditional_t<std::is_same_v<T1, T2>, are_all_same<T1, Ts...>, std::false_type> {};

    // Основная шаблонная функция
    template<typename T,
             typename std::enable_if_t<std::is_integral_v<T>, int> = 0>
    void print_ip(T value) {
        const size_t size = sizeof(T);
        for (size_t i = size; i > 0; --i) {
            unsigned char byte = (value >> ((i - 1) * CHAR_BIT)) & 0xFF;
            std::cout << static_cast<unsigned>(byte);
            if (i != 1) std::cout << ".";
        }
        std::cout << std::endl;
    }

    //Для строк
    template<typename T,
             typename std::enable_if_t<std::is_same_v<T, std::string>, int> = 0>
    void print_ip(const T& value) {
        std::cout << value << std::endl;
    }

    //Для контейнеров
    template<typename T,
             typename std::enable_if_t<is_container<T>::value, int> = 0>
    void print_ip(const T& container) {
        auto it = container.begin();
        if (it != container.end()) {
            std::cout << *it;
            ++it;
        }
        for (; it != container.end(); ++it) {
            std::cout << "." << *it;
        }
        std::cout << std::endl;
    }

    //Для tuple
    template<typename... Args,
             typename std::enable_if_t<are_all_same<Args...>::value, int> = 0>
    void print_ip(const std::tuple<Args...>& tuple) {
        std::apply([](const auto& first, const auto&... rest) {
            std::cout << first;
            ((std::cout << "." << rest), ...);
            std::cout << std::endl;
        }, tuple);
    }
} //namespace hw04

#endif