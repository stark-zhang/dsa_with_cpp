/**
 * @FILE    implementation for constructors and destructors of stack
 * @AUTHOR  Stephen Zhang
 * @DATE    2021-03-08
 */

#ifndef __BDS_STACK_CONSTRUCT_IMPL_H
#define __BDS_STACK_CONSTRUCT_IMPL_H

#pragma once

#include "../stack.h"

namespace dsa
{
    template<typename T>
    Stack<T>::Stack(void)
        : _basic_storage(Vector<T>())
    {

    }
}

#endif /*__BDS_STACK_CONSTRUCT_IMPL_H*/

// EOF