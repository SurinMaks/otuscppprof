#pragma once
#include "ProxyMatrix.hpp"
#include <unordered_map>
#include <algorithm>
#include <iostream>
namespace hw06{

    // /// @brief Предварителное объявление шаблона класса прокси для матрицы
    // /// @tparam T тип данные в матрице
    // /// @tparam DefaultValue значение по умолчанию
    // template<class T, T DefaultValue>
    // class ProxyMatrix;

    template<class T, T DefaultValue>
    class Matrix{
        public:
        /// @brief Конструктор
        Matrix() : default_value_(DefaultValue){
            data_.reserve(reserve_elements);
        };

        /// @brief Деструктор
        ~Matrix(){};

        /// @brief Перегрузка оператора []
        /// @param row строка
        /// @return Объект proxymatrix
        hw06::ProxyMatrix<T, DefaultValue> operator[](T row) {
            return ProxyMatrix<T, DefaultValue>(this, row);
        }

        /// @brief Константная перегрузка оператора []
        /// @param row строка
        /// @return Объект proxymatrix
        const ProxyMatrix<T, DefaultValue> operator[](T row) const {
            return ProxyMatrix<T, DefaultValue> (this, row);
        }

        /// @brief Метод возвращает количество непустых позиций
        /// @return число непустых элементов матрице
        size_t size() const {
            return data_.size();
        }

        /// @brief Метод возвращает установленное значение по умолчанию
        /// @return значение по умолчанию
        T getDefaultValue() const {
            return default_value_;
        }
        /// @brief Метод осуществляет добавление/замену элемента в матрицу
        /// @param row Позиция в строке
        /// @param col Позиция в столбцк
        /// @param value Значение элемента
        void insertElement(T row, T col, T value){
            if(value == default_value_){//удаляем позицию если вставляем значние по умолчанию
                eraseElement(row, col);
                return;
            }
            data_.emplace(std::make_pair(row, col), value);
        }

        /// @brief Удаление элемента
        /// @param row номер строки
        /// @param col номер столбца
        void eraseElement(T row, T col) {
            data_.erase(std::make_pair(row,col));
        };

        /// @brief Константный метод возвращает элемент в указанной позиции, либо значение по умолчанию при чтении из пустой ячейки
        /// @param row Номер строки
        /// @param col Номер столбца
        /// @return Элемент в позиции
        T getElement(T row, T col) const {
            auto it = data_.find(std::make_pair(row, col));
            return it != data_.end() ? it->second : default_value_;
        };

        /// @brief Метод возвращает элемент в указанной позиции, либо значение по умолчанию при чтении из пустой ячейки
        /// @param row Номер строки
        /// @param col Номер столбца
        /// @return Элемент в позиции
        T getElement(T row, T col) {
            auto it = data_.find(std::make_pair(row, col));
            return it != data_.end() ? it->second : default_value_;
        };

        private:
        /// @brief Хеш функция
        struct PairHash {
            std::size_t operator()(const std::pair<T, T>& p) const {
                auto h1 = std::hash<T>{}(p.first);
                auto h2 = std::hash<T>{}(p.second);
                return h1 ^ (h2 << 1);
            }
        };

        /// @brief Матрица элементов
        std::unordered_map<std::pair<T, T>, T, PairHash> data_;

        /// @brief Значение по умолчанию
        const T default_value_;

        /// @brief Количество резервируемых элементов в матрице
        size_t reserve_elements = 100;
    };

}