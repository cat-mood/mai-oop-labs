#pragma once

#include <memory>
using size_t = unsigned long;

namespace lab05 {
    template <class T, class Allocator = std::allocator<T>>
    class Stack {
    public:
        Stack();
        Stack(const Stack& other);
        Stack(Stack&& other) noexcept;
        ~Stack() noexcept;
        Stack& operator=(const Stack& other);
        Stack& operator=(Stack&& other) noexcept;
        const T& top() const;
        bool empty() const;
        size_t size() const;
        void push(const T& value);
        void push(T&& value) noexcept;
        void pop();
    private:
        struct _Node {
            T val;
            _Node* next;
        };

        _Node* _top;
        size_t _size;
    };

    template <class T, class Allocator>
    Stack<T, Allocator>::Stack() : _top{nullptr}, _size{0} {}
    
    template <class T, class Allocator>
    Stack<T, Allocator>::Stack(const Stack& other) : _size{other._size} {
        _top = new _Node;
        _top->val = other._top->val;
        _Node* other_cur = other._top;
        _Node* prev = _top;
        for (size_t i = 0; i < _size - 1; ++i) {
            _Node* cur = new _Node;
            other_cur = other_cur->next;
            cur->val = other_cur->val;
            prev->next = cur;
            prev = cur;
        }
    }

    template <class T, class Allocator>
    Stack<T, Allocator>::Stack(Stack&& other) noexcept {
        _top = other._top;
        _size = std::move(other._size);
    }

    template <class T, class Allocator>
    Stack<T, Allocator>::~Stack() noexcept {
        _Node* next = _top;
        for (size_t i = 0; i < _size; ++i) {
            _Node* cur = next;
            next = next->next;
            delete cur;
        }
    }
}
