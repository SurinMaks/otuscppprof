#ifndef HW03_MY_ALLOCATOR_MY_LIST_HPP_
#define HW03_MY_ALLOCATOR_MY_LIST_HPP_

#include <memory>
#include <cstddef>
#include <cstdlib>

namespace hw03 {

    template <typename T, std::size_t PoolSize = 10>
    class MyAllocatorMyList {
    public:
        using value_type = T;

        template <typename U>
        struct rebind {
            using other = MyAllocatorMyList<U, PoolSize>;
        };

        MyAllocatorMyList() noexcept {
            m_pool = static_cast<T*>(::operator new(PoolSize * sizeof(T)));
            for (std::size_t i = 0; i < PoolSize - 1; ++i) {
                *reinterpret_cast<T**>(m_pool + i) = m_pool + i + 1;
            }
            *reinterpret_cast<T**>(m_pool + PoolSize - 1) = nullptr;
            m_free_list = m_pool;
        }

        ~MyAllocatorMyList() {
            ::operator delete(m_pool);
        }

        T* allocate(std::size_t n) {
            if (n != 1 || !m_free_list) {
                throw std::bad_alloc();
            }

            T* result = m_free_list;
            m_free_list = *reinterpret_cast<T**>(m_free_list);
            return result;
        }

        void deallocate(T* p, std::size_t n) noexcept {
            if (n != 1 || !p) return;

            *reinterpret_cast<T**>(p) = m_free_list;
            m_free_list = p;
        }

        template <typename U, typename... Args>
        void construct(U* p, Args&&... args) {
            new (p) U(std::forward<Args>(args)...);
        }

        template <typename U>
        void destroy(U* p) {
            p->~U();
        }

    private:
        T* m_pool = nullptr;
        T* m_free_list = nullptr;
    };

} // namespace hw03

#endif