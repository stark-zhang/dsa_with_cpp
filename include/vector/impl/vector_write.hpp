/**
 * @FILE    implementation for writing data into Vector
 * @AUTHOR  Stephen Zhang
 * @DATE    2021-03-02
 */

#ifndef __BDS_VECTOR_WRITEDATA_IMPL_H
#define __BDS_VECTOR_WRITEDATA_IMPL_H

#include <utility>
#pragma once

#include "../vector.h"
#include "vector_iterator.hpp"

namespace dsa
{
    template<typename T, typename _Size_t>
    void Vector<T, _Size_t>::push_back(const T& val)
    {
        reserve();

        _basic_ptr[_size_used] = val;
        _size_used++;
    }

    template<typename T, typename _Size_t>
    void Vector<T, _Size_t>::pop_back(void)
    {
        erase(end());
    }

    template<typename T, typename _Size_t>
    void Vector<T, _Size_t>::swap(Vector& v)
    {
        _swap_sth(_size_of_cap, v._size);
        _swap_sth(_size_used, v._size_used);
        _swap_sth(_basic_ptr, v._basic_ptr);
    }

    template<typename T, typename _Size_t>
    void Vector<T, _Size_t>::clear(void)
    {
        erase(begin(), end());
    }

    template<typename T, typename _Size_t>
    void Vector<T, _Size_t>::insert(const T& val, const _Size_t& pos)
    {
        reserve();

        for(size_type i = _size_used; i--; i > pos)
        {
            _basic_ptr[i+1] = _basic_ptr[i];
        }

        _basic_ptr[pos] = val;
        _size_used++;
    }

    template<typename T, typename _Size_t>
    constexpr void Vector<T, _Size_t>::resize(const _Size_t& count, const T& value)
    {
        if(count > _size_used)
        {
            for(size_type i = count; i < _size_used; i++)
            {
                push_back(value);
            }
        }

        _size_used = count;
    }

    template<typename T, typename _Size_t>
    constexpr auto Vector<T, _Size_t>::erase(const iterator _It) -> iterator
    {
        for (iterator it = _It; it < end(); it++)
        {
            *it = *(it + 1);
        }
        _size_used--;

        return _It;
    }

    template<typename T, typename _Size_t>
    constexpr auto Vector<T, _Size_t>::erase(iterator first, iterator last) -> iterator
    {
        if(first < last)
        {
            last = last > end() ? end() : last;
            for(iterator _It = first; _It < last; _It++)
            {
                *_It = _It[last - first];
                _size_used--;
            }
        }
        
        return last;
    }

    template<typename T, typename _Size_t>
    template<typename... Args>
    void Vector<T, _Size_t>::emplace_back(Args&&... args)
    {
        reserve();

        #if __cplusplus <= 201703L      // for cpp17 and before
        /**
         * std::allocator::construct() has been deprecated in cpp17 and will be removed in cpp20
         */
        alloc.construct
        #else                           // for cpp20
        std::construct_at
        #endif /*__cplusplus <= 201703L*/
            (_basic_ptr + _size_used, std::forward<Args>(args)...);
    }

    template<typename T, typename _Size_t>
    template<typename U>
    void Vector<T, _Size_t>::_swap_sth(U& left, U& right)
    {
        U tmp = right;

        right = left;
        left = tmp;
    }
}

#endif /*__BDS_VECTOR_WRITEDATA_IMPL_H*/

// EOF