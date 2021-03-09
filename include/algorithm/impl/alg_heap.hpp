/**
 * @FILE    algorithm about Heap
 * @AUTHOR  Stephen Zhang
 * @DATE    2021-03-09
 */

#ifndef __ALG_HEAP_IMPL_H
#define __ALG_HEAP_IMPL_H

#pragma once

#include <cstdint>
#include <iterator>

namespace dsa
{
    template<typename _Random_It, typename _Comp>
    void __heapify(_Random_It first, _Random_It last, size_t& index, _Comp compare)
    {
        using _Value_Type = typename std::iterator_traits<_Random_It>::value_type;

        const size_t _len = last - first;

        constexpr auto left = [=](const size_t& index) -> size_t
        {
            return 2 * index;
        };

        constexpr auto right = [=](const size_t& index) -> size_t
        {
            return left(index) + 1;
        };

        // the index to max/min value
        size_t _target_idx = 0;
        size_t __l = left(index);
        size_t __r = right(index);

        if((__l < _len) && compare(first[__l], first[index]))
        {
            _target_idx = __l;
        }
        else
        {
            _target_idx = index;
        }

        if((__r < _len) && compare(first[__r], first[index]))
        {
            _target_idx = __r;
        }

        if(_target_idx != index)
        {
            std::swap<_Value_Type>(first[index], first[_target_idx]);
            __heapify(first, last, _target_idx, compare);
        }

    }

    template<typename _Random_It>
    void make_heap(_Random_It first, _Random_It last)
    {
        // get true value_type from the iterators
        using value_type = typename std::iterator_traits<_Random_It>::value_type;

        make_heap(first, last, std::greater<value_type>());
    }

    template<typename _Random_It, typename _Comp>
    void make_heap(_Random_It first, _Random_It last, _Comp compare)
    {
        if(first + 2 >= last)
        {
            return ;
        }

        for(size_t i = (last - first) / 2; i > 0; i--)
        {
            __heapify(first, last, i, compare);
        }
    }
}

#endif /*__ALG_HEAP_IMPL_H*/

// EOF