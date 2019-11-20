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

template<typename TL>
struct IsEmpty :
        std::true_type
{
};

template<>
struct IsEmpty<TypeList<internal::Void, internal::Void>> :
std::true_type
{
};

template<typename ...Args>
struct IsEmpty<TypeList<Args...>> :
std::integral_constant<bool,
        std::is_same<typename TypeList<Args...>::Head, internal::Void>::value &&
        IsEmpty<typename TypeList<Args...>::Tail>::value>
{
};

template<typename TL>
struct Length :
        std::integral_constant<unsigned int, 0>
{
};

template<typename ...Args>
struct Length<TypeList<Args...>> :
        std::integral_constant<unsigned int,
                IsEmpty<TypeList<Args...>>::value
                ? 0
                : 1 + Length<typename TypeList<Args...>::Tail>::value>
{
};

template<unsigned int N, typename TL>
struct TypeAt
{
    typedef internal::Void type;
};

template<typename ...Args>
struct TypeAt<0, TypeList<Args...>>
{
    typedef typename TypeList<Args...>::Head type;
};

template<unsigned int N, typename ...Args>
struct TypeAt<N, TypeList<Args...>>
{
    typedef typename TypeAt<N - 1, typename TypeList<Args...>::Tail>::type type;
};

template<typename T, typename TL>
struct Contains :
        std::false_type
{};

template<typename ...Args>
struct Contains< internal::Void, TypeList<Args...> > :
        std::false_type
{};

template<typename T, typename ...Args>
struct Contains< T, TypeList<Args...> > :
        std::integral_constant<bool,
                std::is_same<typename TypeList<Args...>::Head, T>::value ||
                Contains<T, typename TypeList<Args...>::Tail>::value>
{};

// Пустой список
std::ostream& operator<<(std::ostream& ostr, EmptyTypeList)
{
    ostr << "{}";
    return ostr;
}

template<typename TL>
void PrintTypeListHelper(TL, std::ostream& ostr)
{
}

template<typename T>
void PrintTypeListHead(T, std::ostream& ostr)
{
    ostr << typeid(T).name();
}

template<typename ...Args>
void PrintTypeListHead(TypeList<Args...> tl, std::ostream& ostr)
{
    ostr << tl;
}

template<typename Head, typename ...Args>
void PrintTypeListHelper(TypeList<Head, Args...>, std::ostream& ostr)
{
    PrintTypeListHead(Head(), ostr);
    if(!IsEmpty<TypeList<Args...>>::value)
    {
        ostr << ' ';
        PrintTypeListHelper<Args...>(TypeList<Args...>(), ostr);
    }
}

template<typename ...Args>
std::ostream& operator<<(std::ostream& ostr, TypeList<Args...> tl)
{
    ostr << '{';
    PrintTypeListHelper(tl, ostr);
    ostr << '}';
    return ostr;
}

struct Constants
{
    typedef std::integral_constant<unsigned int, UINT_MAX> npos;
};

namespace internal {
    template<typename T, unsigned int IndexFrom, typename TL>
    struct FindHelper :
            std::integral_constant<unsigned int, 0>
    {
    };

    template<typename T, unsigned int IndexFrom>
    struct FindHelper<T, IndexFrom, EmptyTypeList> :
            std::integral_constant<unsigned int, 0>
    {
    };

    template<typename T, unsigned int IndexFrom, typename ...Args>
    struct FindHelper<T, IndexFrom, TypeList<Args...>> :
            std::integral_constant<unsigned int,
                    std::is_same<typename TypeList<Args...>::Head, T>::value
                    ? IndexFrom
                    : IndexFrom + 1 + FindHelper<T, IndexFrom, typename TypeList<Args...>::Tail>::value>
    {
    };
} // internal

template<typename T, typename TL>
struct Find
{
};

template<typename T>
struct Find<T, EmptyTypeList> :
        Constants::npos
{
};

template<typename ...Args>
struct Find<internal::Void, TypeList<Args...>> :
        Constants::npos
{
};

template<typename T, typename ...Args>
struct Find<T, TypeList<Args...>> :
        std::integral_constant<unsigned int,
                Contains<T, TypeList<Args...>>::value
                ? internal::FindHelper<T, 0, TypeList<Args...>>::value
                : Constants::npos::value>
{
};


