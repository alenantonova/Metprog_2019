#pragma once

#include <type_traits>
#include <ostream>

namespace internal {
    struct Void
    {
    };
} // internal

template<typename ...Args>
struct TypeList
{
    typedef internal::Void Head;
    typedef internal::Void Tail;
};

typedef TypeList<> EmptyTypeList;

template<typename H, typename ...T>
struct TypeList<H, T...>
{
    typedef H Head;
    typedef TypeList<T...> Tail;
};