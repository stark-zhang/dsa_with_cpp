/**
 * @FILE    decleration of Vector, one of basic data structures
 * @AUTHOR  Stephen Zhang
 * @DATE    2021-03-01
 */

#ifndef __BDS_VECTOR_H
#define __BDS_VECTOR_H

#pragma once

#include <cstdint>
#include <iterator>
#include <memory>

#ifndef INITIAL_VECTOR_SIZE
#define INITIAL_VECTOR_SIZE     128
#endif /*INITIAL_VECTOR_SIZE*/

namespace dsa
{
    template <typename T, typename _Size_t = uint32_t>
    class Vector
    {
    public:
        // type re-definition
        using value_type = T;
        using size_type = _Size_t;
        
    class iterator
    #if __cplusplus <= 201703L      // for cpp17 and before
        : std::iterator<
                std::random_access_iterator_tag,
                value_type,
                size_type,
                const value_type*,
                value_type&
            >
    {
        value_type* _it_ptr = nullptr;
    public:
        explicit iterator(value_type* ptr) : _it_ptr(ptr) {}
        value_type& operator*(void) { return *_it_ptr; }
        value_type& operator[](const size_type& idx) { return _it_ptr[idx]; }
        bool operator==(const iterator& _It) const { return _it_ptr == _It._it_ptr; }
        bool operator!=(const iterator& _It) const { return _it_ptr != _It._it_ptr; }
        bool operator>(const iterator& _It) const { return _it_ptr > _It._it_ptr; }
        bool operator<(const iterator& _It) const { return _it_ptr < _It._it_ptr; }
        bool operator>=(const iterator& _It) const { return _it_ptr >= _It._it_ptr; }
        bool operator<=(const iterator& _It) const { return _it_ptr <= _It._it_ptr; }
        iterator& operator++(void) { _it_ptr++; return *this; }
        iterator operator++(int) { iterator tmp = *this; _it_ptr++; return tmp; }
        iterator& operator--(void) { _it_ptr++; return *this; }
        iterator operator--(int) { iterator tmp = *this; _it_ptr--; return tmp; }
        size_type operator-(const iterator& _It) { return (_it_ptr - _It._it_ptr) / sizeof(value_type); }
        iterator operator+(const size_type& num) { return iterator(_it_ptr + num); }
        iterator operator-(const size_type& num) { return iterator(_it_ptr - num); }
        friend iterator operator+(const size_type& num, iterator& _It)
        {
            _It._it_ptr += num; return _It;
        }
    };
    #else                           // for cpp20
    #endif /*__cplusplus <= 201703L*/

        // constructor and deconstructor
        Vector(const size_type& length = 0);
        Vector(const value_type* arr, const size_type& length);
        Vector(const value_type& init_value, const size_type& size);
        Vector(const Vector& v);
        Vector(Vector&& v);
        ~Vector(void);

        constexpr iterator begin(void) noexcept;
        constexpr iterator end(void) noexcept;

        // reloading for some operators
        Vector& operator=(const Vector& v);
        Vector& operator=(Vector&& v);
        value_type& operator[](const _Size_t& idx);

        // public function member for accessing data
        value_type& at(const size_type& idx);
        value_type& front(void);
        value_type& back(void);
        value_type* data(void);

        // public function member to modify stored data
        void push_back(const value_type& val);
        void pop_back(void);
        void swap(Vector& v);
        void clear(void);
        void insert(const value_type& val, const size_type& pos);
        constexpr void resize(const size_type& count, const value_type& value = 0);
        constexpr iterator erase(const iterator it);
        constexpr iterator erase(iterator first, iterator last);
        template<typename... Args>
        void emplace_back(Args&&...);

        // public function member for capacity
        bool empty(void) const;
        size_type capacity(void) const;
        size_type size(void) const;
        size_type max_size(void) const;
        void shrink(void);
        void reserve(void);

    private:
        // private data member
        value_type* _basic_ptr = nullptr;
        size_type _size_of_cap = INITIAL_VECTOR_SIZE;               // allocated memory size
        size_type _size_used = 0;                                   // used memory size
        const size_t _max_size = (1 << 30) - 1;                     // max capacity of Vector
        static std::allocator<value_type> alloc;

        // private function members
        template<typename U>
        void _swap_sth(U& left, U& right);
    };
}

#include "vector_impl.h"

#endif /*__BDS_VECTOR_H*/

// EOF