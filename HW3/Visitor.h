#pragma once

class USDExchangeAcceptor;
class EURExchangeAcceptor;

template <typename R, typename... Args>
class Visitor {
public:
    virtual R visit(USDExchangeAcceptor* acc, Args... args) = 0;
    virtual R visit(EURExchangeAcceptor* acc, Args... args) = 0;
};
