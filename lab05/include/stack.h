#pragma once

#include <memory>
#include <exception>
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
        std::allocator_traits<Allocator>::template rebind_alloc<_Node> alloc;
    public:
        class Iterator {
        public:
            using difference_type = std::ptrdiff_t;
            using value_type = T;
            using pointer = T*;
            using reference = T&;
            using iterator_category = std::forward_iterator_tag;

            Iterator(_Node* ptr);
            ~Iterator() noexcept = default;
            Iterator& operator++();
            reference operator*();
            pointer operator->();
            bool operator==(const Iterator& other) const;
            bool operator!=(const Iterator& other) const;
        private:
            _Node* _cur;
        };

        class ConstIterator {
        public:
            using difference_type = std::ptrdiff_t;
            using value_type = const T;
            using pointer = const T*;
            using reference = const T&;
            using iterator_category = std::forward_iterator_tag;

            ConstIterator(_Node* ptr);
            ~ConstIterator() noexcept = default;
            ConstIterator& operator++();
            reference operator*();
            pointer operator->();
            bool operator==(const ConstIterator& other) const;
            bool operator!=(const ConstIterator& other) const;
        private:
            _Node* _cur;
        };

        Iterator begin();
        Iterator end();
        ConstIterator cbegin();
        ConstIterator cend();
    };

    /*----------------------Implementation-------------------------------------*/

    /*----------------------Stack--------------------------*/

    template <class T, class Allocator>
    Stack<T, Allocator>::Stack() : _top{nullptr}, _size{0} {}
    
    template <class T, class Allocator>
    Stack<T, Allocator>::Stack(const Stack<T, Allocator>& other) : _size{other._size} {
        _top = alloc.allocate(1);
        _top->val = other._top->val;
        _Node* other_cur = other._top;
        _Node* prev = _top;
        for (size_t i = 0; i < _size - 1; ++i) {
            _Node* cur = alloc.allocate(1);
            other_cur = other_cur->next;
            cur->val = other_cur->val;
            prev->next = cur;
            prev = cur;
        }
    }

    template <class T, class Allocator>
    Stack<T, Allocator>::Stack(Stack<T, Allocator>&& other) noexcept {
        _top = other._top;
        _size = std::move(other._size);
        other._size = 0;
    }

    template <class T, class Allocator>
    Stack<T, Allocator>::~Stack() noexcept {
        _Node* next = _top;
        for (size_t i = 0; i < _size; ++i) {
            _Node* cur = next;
            next = next->next;
            alloc.deallocate(cur, 1);
        }
    }

    template <class T, class Allocator>
    Stack<T, Allocator>& Stack<T, Allocator>::operator=(const Stack<T, Allocator>& other) {
        _size = other._size;
        _top = alloc.allocate(1);
        _top->val = other._top->val;
        _Node* other_cur = other._top;
        _Node* prev = _top;
        for (size_t i = 0; i < _size - 1; ++i) {
            _Node* cur = alloc.allocate(1);
            other_cur = other_cur->next;
            cur->val = other_cur->val;
            prev->next = cur;
            prev = cur;
        }
    }

    template <class T, class Allocator>
    Stack<T, Allocator>& Stack<T, Allocator>::operator=(Stack<T, Allocator>&& other) noexcept {
        _top = other._top;
        _size = other._size;
    }

    template <class T, class Allocator>
    const T& Stack<T, Allocator>::top() const {
        return _top->val;
    }

    template <class T, class Allocator>
    bool Stack<T, Allocator>::empty() const {
        return _size == 0;
    }

    template <class T, class Allocator>
    size_t Stack<T, Allocator>::size() const {
        return _size;
    }

    template <class T, class Allocator>
    void Stack<T, Allocator>::push(const T& value) {
        _Node* new_el = alloc.allocate(1);
        new (&new_el->val) T();
        new_el->val = value;
        new_el->next = _top;
        _top = new_el;
        ++_size;
    }

    template <class T, class Allocator>
    void Stack<T, Allocator>::push(T&& value) noexcept {
        _Node* new_el = alloc.allocate(1);
        new (&new_el->val) T();
        new_el->val = value;
        new_el->next = _top;
        _top = new_el;
        ++_size;
    }

    template <class T, class Allocator>
    void Stack<T, Allocator>::pop() {
        if (_size <= 0) {
            throw std::logic_error("Stack is empty");
        }
        _Node* old = _top;
        _top = _top->next;
        alloc.deallocate(old, 1);
        --_size;
    }

    template <class T, class Allocator>
    Stack<T, Allocator>::Iterator Stack<T, Allocator>::begin() {
        Iterator iter(_top);
        return iter;
    }

    template <class T, class Allocator>
    Stack<T, Allocator>::Iterator Stack<T, Allocator>::end() {
        Iterator iter(nullptr);
        return iter;
    }

    template <class T, class Allocator>
    Stack<T, Allocator>::ConstIterator Stack<T, Allocator>::cbegin() {
        ConstIterator iter(_top);
        return iter;
    }

    template <class T, class Allocator>
    Stack<T, Allocator>::ConstIterator Stack<T, Allocator>::cend() {
        ConstIterator iter(nullptr);
        return iter;
    }

    /*------------------Iterator-----------------------------*/

    template <class T, class Allocator>
    Stack<T, Allocator>::Iterator::Iterator(_Node* ptr) : _cur{ptr} {}

    template <class T, class Allocator>
    Stack<T, Allocator>::Iterator& Stack<T, Allocator>::Iterator::operator++() {
        _cur = _cur->next;
        return *this;
    }

    template <class T, class Allocator>
    lab05::Stack<T, Allocator>::Iterator::reference Stack<T, Allocator>::Iterator::operator*() {
        return _cur->val;
    }

    template <class T, class Allocator>
    lab05::Stack<T, Allocator>::Iterator::pointer Stack<T, Allocator>::Iterator::operator->() {
        return &_cur->val;
    }

    template <class T, class Allocator>
    bool Stack<T, Allocator>::Iterator::operator==(const Iterator& other) const {
        return _cur == other._cur;
    }

    template <class T, class Allocator>
    bool Stack<T, Allocator>::Iterator::operator!=(const Iterator& other) const {
        return _cur != other._cur;
    }

    /*---------------ConstIterator------------------------------*/

    template <class T, class Allocator>
    Stack<T, Allocator>::ConstIterator::ConstIterator(_Node* ptr) : _cur{ptr} {}

    template <class T, class Allocator>
    Stack<T, Allocator>::ConstIterator& Stack<T, Allocator>::ConstIterator::operator++() {
        _cur = _cur->next;
        return *this;
    }

    template <class T, class Allocator>
    lab05::Stack<T, Allocator>::ConstIterator::reference Stack<T, Allocator>::ConstIterator::operator*() {
        return _cur->val;
    }

    template <class T, class Allocator>
    lab05::Stack<T, Allocator>::ConstIterator::pointer Stack<T, Allocator>::ConstIterator::operator->() {
        return &_cur->val;
    }

    template <class T, class Allocator>
    bool Stack<T, Allocator>::ConstIterator::operator==(const ConstIterator& other) const {
        return _cur == other._cur;
    }

    template <class T, class Allocator>
    bool Stack<T, Allocator>::ConstIterator::operator!=(const ConstIterator& other) const {
        return _cur != other._cur;
    }
}
