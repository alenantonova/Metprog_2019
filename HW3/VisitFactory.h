#pragma once

#include "Acceptor.h"

template <class Visit, class Acc, class Func>
class VisitFactory {
public:
    template <typename... FArgs, typename R, typename... Args>
    auto Go(Visitor<R, Args...>* v, Acceptor<R, Args...>* a, FArgs... args) -> decltype(a->accept(v, args...));
};

template <class Visit, class Acc, class Func>
template <typename... Args, typename R, typename... FArgs>
auto VisitFactory<Visit, Acc, Func>::Go(Visitor<R, FArgs...> *v,
        Acceptor<R, FArgs...> *a, Args... args) -> decltype(a->accept(v, args...)) {
    return a->accept(v, args...);
}

