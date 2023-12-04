#pragma once

#include <deque>
#include <exception>
#include <iostream>

namespace lab05 {
    template <class T>
    class Allocator {
    private:
        using chunk = char;
        static const size_t _max_size_block = 16;
        chunk* _used_chunks;
        std::deque<chunk*> _free_chunks;
        std::size_t _free_count;
    public:
        static const size_t max_count = 500000;
        using value_type = T;
        using pointer = T*;
        using const_pointer = const T*;
        using size_type = std::size_t;
        typedef std::allocator_traits<Allocator<T>> a_t;
        
        Allocator();
        ~Allocator() noexcept;
        T* allocate(std::size_t n);
        void deallocate(T* ptr, std::size_t n);

        template<class U>
        struct rebind {
            using value = Allocator<U>;
        };

        template <typename U, typename... Args>
        void construct(U* p, Args&&...args) {
            new (p) U(std::forward<Args>(args)...);
        }

        void destroy(pointer p) {
            p->~T();
        }
    };

template <class T>
Allocator<T>::Allocator() {
    _used_chunks = new chunk[max_count * sizeof(T)];
    _free_chunks = std::deque<chunk*>(max_count);
    chunk* it = _used_chunks;
    for (chunk*& el : _free_chunks) {
        el = it;
        it += sizeof(T);
    }
    _free_count = max_count;
}

template <class T>
Allocator<T>::~Allocator() noexcept {
    delete[] _used_chunks;
}

template <class T>
T* Allocator<T>::allocate(std::size_t n) {
    T* free_ptr;
    if (n > _max_size_block) {
        throw std::bad_alloc();
    }
    // number of free blocks size of n
    std::size_t free_count_block = _free_count - (max_count - _free_count) / n - ((max_count - _free_count) % n > 0);
    if (free_count_block <= 0) {
        throw std::bad_alloc();
    }
    free_ptr = (T*) _free_chunks.front();
    for (std::size_t i = 0; i < n; ++i) {
        _free_chunks.pop_front();
    }
    _free_count -= n;
    return free_ptr;
}

template <class T>
void Allocator<T>::deallocate(T* ptr, std::size_t n) {
    for (std::size_t i = 0; i < n; ++i) {
        _free_chunks.push_back((chunk*) ptr);
    }
    _free_count += n;
}

}
