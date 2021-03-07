/**
 * @FILE    decleration of Stack, one of basic data structures
 * @AUTHOR  Stephen Zhang
 * @DATE    2021-02-28
 */

#ifndef __BDS_STACK_H
#define __BDS_STACK_H

#include "../vector/vector.h"
#include <vector>

namespace dsa
{
    template<typename T>
    class Stack
    {
    public:
        Stack(void);
        Stack(const Stack& s);
        Stack(Stack&& s);
        ~Stack(void);

        void push(const T& value);
        T& pop(const T& value);
        T& top(void);
        T& drop(void);
        bool empty(void);

    private:
        Vector<T> _basic_storage;
    };
}

#include "stack_impl.h"

#endif /*__BDS_STACK_H*/

// EOF