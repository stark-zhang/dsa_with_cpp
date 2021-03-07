/**
 * @FILE    implementation for reading data into Vector
 * @AUTHOR  Stephen Zhang
 * @DATE    2021-03-02
 */

#ifndef __BDS_VECTOR_READDATA_IMPL_H
#define __BDS_VECTOR_READDATA_IMPL_H

#include <stdexcept>
#include <type_traits>

#pragma once

#include "../vector.h"
#include <exception>

namespace dsa
{
    template<typename T, typename _Size_t>
    T& Vector<T, _Size_t>::at(const _Size_t& idx)
    {
        if(idx <= _size_used) { return _basic_ptr[idx]; }
        else { throw std::out_of_range("Illegal Index!"); }
    }

    template<typename T, typename _Size_t>
    T& Vector<T, _Size_t>::operator[](const _Size_t& idx)
    {
        return _basic_ptr[idx];
    }

    template<typename T, typename _Size_t>
    T& Vector<T, _Size_t>::front(void)
    {
        return _basic_ptr[0];
    }

    template<typename T, typename _Size_t>
    T& Vector<T, _Size_t>::back(void)
    {
        return _basic_ptr[_size_used - 1];
    }

    template<typename T, typename _Size_t>
    T* Vector<T, _Size_t>::data(void)
    {
        return _basic_ptr;
    }
}

#endif /*__BDS_VECTOR_READDATA_IMPL_H*/

// EOF