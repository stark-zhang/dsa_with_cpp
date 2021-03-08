/**
 * @FILE    implementation for constructors and destructors of Vector
 * @AUTHOR  Stephen Zhang
 * @DATE    2021-03-03
 */

#ifndef __BDS_VECTOR_CONSTRUCT_IMPL_H
#define __BDS_VECTOR_CONSTRUCT_IMPL_H

#pragma once

#include "../vector.h"
#include <cstring>
#include <memory>

namespace dsa
{
    template<typename T, typename _Size_t>
    Vector<T, _Size_t>::Vector(const _Size_t& length)
        : _size_of_cap(length), _basic_ptr(nullptr)
    {

    }

    template<typename T, typename _Size_t>
    Vector<T, _Size_t>::Vector(const T* arr, const _Size_t& length)
        : Vector(length)
    {
        reserve();

        for(size_type i = 0; i < length; i++)
        {
            _basic_ptr[i] = arr[i];
            _size_used++;
        }
    }

    template<typename T, typename _Size_t>
    Vector<T, _Size_t>::Vector(const T& init_value, const _Size_t& length)
        : Vector(length)
    {
        reserve();

        for(size_type i = 0; i < length; i++)
        {
            _basic_ptr[i] = init_value; _size_used++;
        }
    }

    template<typename T, typename _Size_t>
    Vector<T, _Size_t>::Vector(const Vector& v)
        : _size_of_cap(v._size_of_cap), _size_used(v._size_used)
    {
        reserve();

        for(size_type i = 0; i < _size_used; i++)
        {
            _basic_ptr[i] = v[i];
        }
    }

    template<typename T, typename _Size_t>
    Vector<T, _Size_t>::Vector(Vector&& v)
        : _basic_ptr(v._basic_ptr), _size_of_cap(v._size_of_cap), _size_used(v._size_used)
    {
        v._basic_ptr = nullptr;
    }

    template<typename T, typename _Size_t>
    Vector<T, _Size_t>::~Vector(void)
    {
        if(_basic_ptr == nullptr) { return ; }

        for(auto p = _basic_ptr + _size_used; p != _basic_ptr;)
        {
            alloc.destroy(--p);
        }

        alloc.deallocate(_basic_ptr, _size_of_cap);

        _size_of_cap = 0;
        _size_used = 0;
    }

    template<typename T, typename _Size_t>
    Vector<T, _Size_t>& Vector<T, _Size_t>::operator=(const Vector& v)
    {
        if(this == &v) { return *this; }

        this = new Vector<T, _Size_t>(v);
        return *this;
    }

    template<typename T, typename _Size_t>
    Vector<T, _Size_t>& Vector<T, _Size_t>::operator=(Vector&& v)
    {
        // avoid move self to self
        if(this == &v) { return *this; }

        // avoid memory leak
        if(_basic_ptr != nullptr) { delete[] _basic_ptr; }

        _basic_ptr = v._basic_ptr;
        v._basic_ptr = nullptr;

        _size_used = v._size_used;
        _size_of_cap = v._size;

        return *this;
    }
}

#endif /*__BDS_VECTOR_CONSTRUCT_IMPL_H*/

// EOF