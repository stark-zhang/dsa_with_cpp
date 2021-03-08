/**
 * @FILE    implementation for memory allocating in Vector
 * @AUTHOR  Stephen Zhang
 * @DATE    2021-03-02
 */

#ifndef __BDS_VECTOR_CAPACITY_IMPL_H
#define __BDS_VECTOR_CAPACITY_IMPL_H

#pragma once

#include "../vector.h"
#include <cstring>
#include <memory>

namespace dsa
{
    template<typename T, typename _Size_t>
    bool Vector<T, _Size_t>::empty(void) const
    {
        return _size_used == 0;
    }

    template<typename T, typename _Size_t>
    _Size_t Vector<T, _Size_t>::size(void) const
    {
        return _size_used;
    }

    template<typename T, typename _Size_t>
    _Size_t Vector<T, _Size_t>::capacity(void) const
    {
        return _size_of_cap;
    }

    template<typename T, typename _Size_t>
    _Size_t Vector<T, _Size_t>::max_size(void) const
    {
        return _max_size;
    }

    template<typename T, typename _Size_t>
    void Vector<T, _Size_t>::shrink(void)
    {
        // no need to shrink if empty
        if(empty()) { return ; }

        T* old_basic_ptr = _basic_ptr;
        _basic_ptr = new T[_size_used];
    }

    template<typename T, typename _Size_t>
    void Vector<T, _Size_t>::reserve(void)
    {
        if(size() < capacity()) { return ; }

        auto expected_size = size() ? 2 * size() : 1;
        auto new_basic_ptr = alloc.allocate(expected_size);

        // prepare to copy data
        _size_of_cap = expected_size;

        // copy existed data to new destination
        for(_Size_t i = 0; i < _size_used; i++)
        {
            new_basic_ptr[i] = std::move(_basic_ptr[i]);
        }

        // delete the older storage
        delete[] _basic_ptr;
        _basic_ptr = new_basic_ptr;
    }

    // to make complier happy
    #if __cplusplus < 201703L
        template<typename T, typename _Size_t>
        std::allocator<T> Vector<T, _Size_t>::alloc = std::allocator<T>();
    #endif /*__cplusplus < 201703L*/
}

#endif /*__BDS_VECTOR_CAPACITY_IMPL_H*/

// EOF