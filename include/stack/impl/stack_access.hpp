/**
 * @FILE    implementation for constructors and deconstructors of stack
 * @AUTHOR  Stephen Zhang
 * @DATE    2021-03-08
 */

#ifndef __BDS_STACK_ACCESS_IMPL_H
#define __BDS_STACK_ACCESS_IMPL_H

#pragma once

#include <utility>
#include "../stack.h"

namespace dsa
{
    template<typename T>
    template<typename... Args>
    void Stack<T>::push(Args&&... args)
    {
        _basic_storage.emplace_back(std::forward<Args>(args)...);
    }

    template<typename T>
    void Stack<T>::push(const T& value)
    {
        _basic_storage.push_back(std::move(value));
    }

    template<typename T>
    void Stack<T>::pop(T& value)
    {
        value = std::move(_basic_storage.back());

        drop();
    }

    template<typename T>
    T& Stack<T>::top(void)
    {
        return _basic_storage.back();
    }

    template<typename T>
    void Stack<T>::drop(void)
    {
        _basic_storage.erase(_basic_storage.end() - 1);
    }

    template<typename T>
    bool Stack<T>::empty(void)
    {
        return _basic_storage.empty();
    }

    template<typename T>
    uint32_t Stack<T>::depth(void)
    {
        return _basic_storage.size();
    }
}

#endif /*_BDS_STACK_ACCESS_IMPL_H*/

// EOF