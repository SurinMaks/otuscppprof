#ifndef HW03_MYLIST_HPP_
#define HW03_MYLIST_HPP_

#include "IMyContainer.hpp"
#include "MyAllocatorMyList.hpp"
#include <memory>
#include <functional>

namespace hw03 {
    template<typename T, typename Allocator = std::allocator<T>>
    class MyList : public IMyContainer<T> {
    public:
        class MyIterator;

        MyIterator begin() { return MyIterator(m_head); }
        MyIterator end() { return MyIterator(nullptr); }

        MyList() = default;

        ~MyList() { clear(); }

        void push_back(const T& value) override {
            MyNode* new_node = create_node(value);

            if (!m_head) {
                m_head = new_node;
            } else {
                MyNode* current = m_head;
                while (current->next) {
                    current = current->next;
                }
                current->next = new_node;
            }
            ++m_size;
        }

    private:
        struct MyNode {
            T value;
            MyNode* next;

            MyNode(const T& val) : value(val), next(nullptr) {}
        };

        using NodeAllocator = typename std::allocator_traits<Allocator>::template rebind_alloc<MyNode>;
        NodeAllocator m_allocator;

        MyNode* create_node(const T& value) {
            MyNode* node = std::allocator_traits<NodeAllocator>::allocate(m_allocator, 1);
            std::allocator_traits<NodeAllocator>::construct(m_allocator, node, value);
            return node;
        }

        void clear() {
            while (m_head) {
                MyNode* to_delete = m_head;
                m_head = m_head->next;
                std::allocator_traits<NodeAllocator>::destroy(m_allocator, to_delete);
                std::allocator_traits<NodeAllocator>::deallocate(m_allocator, to_delete, 1);
            }
            m_size = 0;
        }

        MyNode* m_head = nullptr;
        size_t m_size = 0;

    public:
        class MyIterator {
            MyNode* m_current;
        public:
            using iterator_category = std::forward_iterator_tag;
            using value_type = T;
            using difference_type = std::ptrdiff_t;
            using pointer = T*;
            using reference = T&;

            explicit MyIterator(MyNode* node) : m_current(node) {}

            MyIterator& operator++() {
                if (m_current) m_current = m_current->next;
                return *this;
            }

            MyIterator operator++(int) {
                MyIterator temp = *this;
                ++(*this);
                return temp;
            }

            bool operator==(const MyIterator& other) const {
                return m_current == other.m_current;
            }

            bool operator!=(const MyIterator& other) const {
                return !(*this == other);
            }

            reference operator*() const { return m_current->value; }
            pointer operator->() const { return &(m_current->value); }
        };
    };
} // namespace hw03

#endif