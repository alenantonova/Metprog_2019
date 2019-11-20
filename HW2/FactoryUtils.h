#include "TypeListUtils.h"

template<typename Item1, typename Item2>
struct CompareFactories
{
};

template<typename Item>
struct CompareFactories<Item, EmptyTypeList>
{
    typedef typename std::integral_constant<bool, false> is_eq;
};

template<typename Item, typename ...TailItems>
struct CompareFactories<Item, TypeList<TailItems...> >
{
    typedef typename std::integral_constant<bool,
            std::is_same<Item, typename TypeList<TailItems...>::Head>::value
            ? true
            : CompareFactories<Item, typename TypeList<TailItems...>::Tail >::is_eq::value> is_eq;
};

template<typename ConcreteFactory, unsigned int IndexFrom, typename TL>
struct FindFactoryHelper :
        std::integral_constant<unsigned int, 0>
{};

template<typename ConcreteFactory, unsigned int IndexFrom>
struct FindFactoryHelper<TypeList<ConcreteFactory>, IndexFrom, EmptyTypeList> :
        std::integral_constant<unsigned int, 0>
{
};

template<typename ConcreteFactory, unsigned int IndexFrom, typename CurFactory, typename ...CurTail>
struct FindFactoryHelper< ConcreteFactory, IndexFrom, TypeList<CurFactory, CurTail...> > :
        std::integral_constant< unsigned int, CompareFactories< ConcreteFactory, CurFactory>::is_eq::value
                                              ? IndexFrom
                                              : IndexFrom + 1 + FindFactoryHelper<ConcreteFactory, IndexFrom, TypeList<CurTail...>>::value>
{
};

template<typename ConcreteFactory, typename Factories>
struct FindFactory
{
};

template<typename ...Args>
struct FindFactory<EmptyTypeList, TypeList<Args...> > :
        Constants::npos
{
};

template<typename ConcreteFactory, typename FactoryListHead, typename ...FactoryListTail>
struct FindFactory< ConcreteFactory, TypeList<FactoryListHead, FactoryListTail...> > :
        std::integral_constant<unsigned int,
        FindFactoryHelper<ConcreteFactory, 0, TypeList<FactoryListHead, FactoryListTail...> >::value>
{
};

template<typename BaseItems, typename FactoryItems>
class SimpleFactory
{
public:
    typedef FactoryItems ItemsList;
    typedef BaseItems FactoryBase;

    void printBase() {
        std::cout << FactoryBase() << std::endl;
    }
    void printClasses() {
        std::cout << ItemsList() << std::endl;
    }

    template<typename Item>
    Item* Get()
    {return new typename TypeAt< Find< Item, FactoryBase>::value, ItemsList >::type;}
};

template<unsigned int N, unsigned int M, typename BaseTypeList, typename ...TypeLists>
class GetAbstractFactory
{
public:
    typedef BaseTypeList base;
    typedef TypeList<TypeLists...> factories;

    GetAbstractFactory()
    {
        if (Length<base>::value != N)
        {
            throw std::invalid_argument("Incorrect number of base types in input");
        }

        if (Length<factories>::value != M-1)
        {
            throw std::invalid_argument("Incorrect number of factories in input");
        }
    }

    template<typename ConcreteTag>
    auto  GetConcreteFactory()
    {
        typedef typename TypeAt< FindFactory<ConcreteTag, factories>::value, factories>::type factory;
        return new SimpleFactory<base, factory>();
    }

};