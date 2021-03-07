/**
 * @FILE    implementation for iterators supporting
 * @AUTHOR  Stephen Zhang
 * @DATE    2021-03-02
 */

#ifndef __BDS_VECTOR_ITERATOR_IMPL_H
#define __BDS_VECTOR_ITERATOR_IMPL_H

#pragma once

#include "../vector.h"
#include <iterator>

namespace dsa
{
    template<typename T, typename _Size_t>
    constexpr auto Vector<T, _Size_t>::begin(void) noexcept -> iterator
    {
        return iterator(_basic_ptr);
    }

    template<typename T, typename _Size_t>
    constexpr auto Vector<T, _Size_t>::end(void) noexcept -> iterator
    {
        return iterator(_basic_ptr + _size_used);
    }
}

#endif /*__BDS_VECTOR_ITERATOR_IMPL_H*/

// EOF