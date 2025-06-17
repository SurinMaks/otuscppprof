#ifndef HW03_MY_ALLOCATOR_MAP_HPP_
#define HW03_MY_ALLOCATOR_MAP_HPP_

#include <iostream>
#include <map>
#include <memory>
#include <vector>
#include <cstdlib>

namespace hw03
{
    template<typename T, std::size_t MAX_ELEMENT>
    class MyAllocatorMap
    {
        public:
            using value_type = T;
            using pointer = T*;
            using const_pointer = const T*;
            using reference = T&;
            using const_reference = const T&;
            using size_type = std::size_t;
            using difference_type = std::ptrdiff_t;

            template <typename U>
            struct rebind{
                using other = MyAllocatorMap<U, MAX_ELEMENT>;
            };

            MyAllocatorMap() : memory(nullptr), allocated(0){
                memory = static_cast<pointer>(::operator new (MAX_ELEMENT * sizeof(T)));
            }

            ~MyAllocatorMap(){
                ::operator delete(memory);
            }

            template<typename U>
            MyAllocatorMap(const MyAllocatorMap<U, MAX_ELEMENT>&) : memory(nullptr), allocated(0){
                memory = static_cast<pointer>(::operator new (MAX_ELEMENT * sizeof(T)));
            }

            pointer allocate(size_type n){
                if (allocated + n > MAX_ELEMENT){
                    throw std::bad_alloc();
                }
                pointer result = memory + allocated;
                allocated += n;
                return result;
            }

            void deallocate(pointer p, size_type n) {
                // Освобождение отдельных элементов не требуется
            }

            template <typename U, typename... Args>
            void construct(U* p, Args&&... args) {
                new (p) U(std::forward<Args>(args)...);
            }

            template <typename U>
            void destroy(U* p) {
                p->~U();
            }

            size_type max_size() const noexcept {
                return MAX_ELEMENT;
            }

        private:
            pointer memory;
            size_type allocated;
    };

    // Операторы сравнения для аллокатора
    template <typename T1, typename T2, std::size_t N>
    bool operator==(const MyAllocatorMap<T1, N>&, const MyAllocatorMap<T2, N>&) {
        return true;
    }

    template <typename T1, typename T2, std::size_t N>
    bool operator!=(const MyAllocatorMap<T1, N>& lhs, const MyAllocatorMap<T2, N>& rhs) {
        return !(lhs == rhs);
    }
} // namespace hw03



#endif