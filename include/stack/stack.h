/**
 * @FILE    decleration of Stack, one of basic data structures
 * @AUTHOR  Stephen Zhang
 * @DATE    2021-02-28
 */

#ifndef __BDS_STACK_H
#define __BDS_STACK_H

#include "../vector/vector.h"
#include <cstdint>

namespace dsa
{
    template<typename T>
    class Stack
    {
    public:
        Stack(void);
        ~Stack(void) = default;

        template<typename... Args>
        void push(Args&&... args);
        void push(const T& value);
        void pop(T& value);
        T& top(void);
        void drop(void);
        bool empty(void);
        uint32_t depth(void);

    private:
        Vector<T> _basic_storage;
    };
}

#include "stack_impl.h"

#endif /*__BDS_STACK_H*/

// EOF