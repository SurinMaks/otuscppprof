#pragma once

#include <iostream>
#include <memory>
#include <cstdlib>

namespace hw03 {

    template <typename T, std::size_t PoolSize = 100>
    class UniversalAllocator {
    public:
        using value_type = T;
        using pointer = T*;
        using const_pointer = const T*;
        using reference = T&;
        using const_reference = const T&;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;

        template <typename U>
        struct rebind {
            using other = UniversalAllocator<U, PoolSize>;
        };

        UniversalAllocator() noexcept {
            m_pool = static_cast<char*>(::operator new(PoolSize * sizeof(T)));

            for (size_type i = 0; i < PoolSize - 1; ++i) {
                *reinterpret_cast<char**>(m_pool + i * sizeof(T)) = m_pool + (i + 1) * sizeof(T);
            }
            *reinterpret_cast<char**>(m_pool + (PoolSize - 1) * sizeof(T)) = nullptr;

            m_free_list = m_pool;
            m_allocated = 0;
        }

        ~UniversalAllocator() {
            ::operator delete(m_pool);
        }

        template <typename U>
        UniversalAllocator(const UniversalAllocator<U, PoolSize>&) noexcept
            : UniversalAllocator() {}

        pointer allocate(size_type n) {
            if (n == 1 && m_free_list) {
                pointer result = reinterpret_cast<pointer>(m_free_list);
                m_free_list = *reinterpret_cast<char**>(m_free_list);
                m_allocated++;
                return result;
            } else if (m_allocated + n <= PoolSize) {
                pointer result = reinterpret_cast<pointer>(m_pool + m_allocated * sizeof(T));
                m_allocated += n;
                return result;
            }
            throw std::bad_alloc();
        }

        void deallocate(pointer p, size_type n) noexcept {
            if (!p) return;

            if (n == 1) {
                *reinterpret_cast<char**>(p) = m_free_list;
                m_free_list = reinterpret_cast<char*>(p);
            } else {
                char* current = reinterpret_cast<char*>(p);
                for (size_type i = 0; i < n; ++i) {
                    char* next = (i == n - 1) ? m_free_list : current + sizeof(T);
                    *reinterpret_cast<char**>(current) = next;
                    current += sizeof(T);
                }
                m_free_list = reinterpret_cast<char*>(p);
            }

            m_allocated -= n;
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
            return PoolSize;
        }

    private:
        char* m_pool = nullptr;
        char* m_free_list = nullptr;
        size_type m_allocated = 0;
    };

    template <typename T1, typename T2, std::size_t N>
    bool operator==(const UniversalAllocator<T1, N>&, const UniversalAllocator<T2, N>&) {
        return true;
    }

    template <typename T1, typename T2, std::size_t N>
    bool operator!=(const UniversalAllocator<T1, N>&, const UniversalAllocator<T2, N>&) {
        return false;
    }

} // namespace hw03