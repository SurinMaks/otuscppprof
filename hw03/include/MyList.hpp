#ifndef HW03_MYLIST_HPP_
#define HW03_MYLIST_HPP_

#include "IMyContainer.hpp"
#include <iostream>
#include <memory>
namespace hw03{
    template<typename T>
    class MyList : public hw03::IMyContainer<T> {
    public:
            MyList() = default;

            ~MyList() {};
            /// @brief Вставка элемента в конец списка
            /// @param value Значение элемента
            void push_back(const T& value) override {
                std::unique_ptr<struct MyNode> new_node = std::make_unique<struct MyNode>(value);
                new_node->m_next = nullptr;
                if(!m_head){ //проверка на пустой список
                    m_head = std::move(new_node);
                }
                else{
                    MyNode* current = m_head.get();
                    while (current->m_next) //когда список не пустой перемещаемся в конец
                    {
                        current = current->m_next.get();
                    }
                    current->m_next = std::move(new_node);
                }
                incrementSize();
            };

            /// @brief Вставка элемента в указанную позицию
            /// @param value Значение элемента
            /// @param position Номер позиции(с нуля)
            void insertIntoPosition(const T& value, const unsigned int position) override {
                if(position > m_size){
                    std::cout << "Position exceeds list size\n";
                    return;
                }
                if(position == 0){
                    insertIntoBegin(value);
                    return;
                }
                if(position == m_size){
                    insertIntoEnd(value);
                    return;
                }
                std::unique_ptr<struct MyNode> new_node = std::make_unique<struct MyNode>(value);
                MyNode* current = m_head.get();
                for (unsigned int i = 0; i < position-1; ++i){
                    current = current->m_next.get();
                }
                new_node->m_next = std::move(current->m_next);
                current->m_next = std::move(new_node);
                incrementSize();
            };

            /// @brief Вставка в конец списка. Вызовится метод push_back
            /// @param value Значение элемента
            inline void insertIntoEnd(const T& value) override{
                push_back(value);

            };

            /// @brief Вставка в начало списка
            /// @param value Значение элемента
            void insertIntoBegin(const T& value) override{
                std::unique_ptr<struct MyNode> new_Node = std::make_unique<struct MyNode>(value);
                new_Node->m_next = std::move(m_head);
                m_head = std::move(new_Node);
                incrementSize();
            };

            /// @brief Удаление элемента в указанной позиции
            /// @param position Индекс позиции (с нуля)
            void eraseInPosition(const unsigned int position) override {
                if (position > m_size){
                    std::cout << "Index out of range list. From position " << position << '\n';
                    return;
                }
                if(position == 0){
                    eraseInBegin();
                    return;
                }
                if(position == m_size){
                    eraseInEnd();
                    return;
                }
                MyNode* prev_node = m_head.get();
                for (unsigned int i = 0; i < position-1; ++i){
                    prev_node= prev_node->m_next.get();
                }
                auto to_delete = std::move(prev_node->m_next);
                prev_node->m_next = std::move(to_delete->m_next);
                decrementSize();
            };

            /// @brief Удаление последнего элемента в списке
            void eraseInEnd() override {
                if(checkTheEmptyList()){
                    return;
                }
                if(!m_head->m_next){
                    m_head = nullptr;
                    decrementSize();
                    return;
                }
                MyNode* current = m_head.get();
                while (current->m_next->m_next)//находим предпоследний элемент
                {
                    current = current->m_next.get();
                }
                current->m_next = nullptr;
                decrementSize();
            };

            /// @brief Удаление элемента из начала списка
            void eraseInBegin() override{
                if(checkTheEmptyList()){
                    return;
                }
                auto old_head = std::move(m_head);
                m_head = std::move(old_head->m_next);
                decrementSize();
            };

            /// @brief Текущий размер списка
            /// @return Размер списка
            unsigned int size() const noexcept override {
                return m_size;
            };

            /// @brief Печать списка
            void printList() const noexcept override{
                if(!m_head){
                    std::cout << "List is empty\n";
                }
                else{
                    auto current = m_head.get();
                    while (current)
                    {
                        std::cout << current->m_value << ' ';
                        current = current->m_next.get();
                    }
                    std::cout << '\n';
                }
            };

            T operator[](unsigned int index) const override {
                if(index > m_size){
                    throw std::out_of_range("Position exceeds list size");
                }
                auto current = m_head.get();
                for (unsigned int i = 0; i < index; ++i){
                    current = current->m_next.get();
                }
                return current->m_value;
            };
    private:
            struct MyNode
            {
                MyNode(const T& value){
                    m_value = value;
                    m_next = nullptr;
                }
                MyNode(){}
                T m_value;
                std::unique_ptr<struct MyNode> m_next = nullptr;
            };

            bool checkTheEmptyList(){
                if(!m_head){
                    std::cout << "List is empty\n";
                    return true;
                }
                else{
                    return false;
                }
            };
            /// @brief Увеличение размера списка
            void incrementSize(){
                ++m_size;
            };

            /// @brief Уменьшение размера списка
            void decrementSize(){
                --m_size;
            };

            std::unique_ptr<struct MyNode> m_head = nullptr;
            unsigned int m_size = 0;
    };

}//namespace hw03


#endif
