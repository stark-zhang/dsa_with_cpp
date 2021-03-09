/**
 * @FILE    the set of algorithms in the name space dsa
 * @AUTHOR  Stephen Zhang
 * @DATE    2021-03-09
 */

#ifndef __ALG_ALGORITHM_ENTRY_H
#define __ALG_ALGORITHM_ENTRY_H

#pragma once

namespace dsa
{
    /* ** Algorithm for HEAP ** */
    template<typename _Random_It>
    void make_heap(_Random_It first, _Random_It last);

    template<typename _Random_It, typename _Comp>
    void make_heap(_Random_It first, _Random_It last, _Comp compare);
}

#include "alg_impl.h"

#endif /*__ALG_ALGORITHM_ENTRY_H*/

// EOF