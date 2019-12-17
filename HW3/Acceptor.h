#pragma once

#include "Visitor.h"

template <typename R, typename... Args>
class Acceptor {
public:
    virtual R accept(Visitor<R, Args...>* visitor, Args... args) = 0;
};
