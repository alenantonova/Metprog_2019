#pragma once

template <typename R, typename... Args>
class Impl {
public:
    virtual R operator()(Args...) const = 0;
    virtual Impl* copy() const = 0;
};

template <typename F, typename R, typename... Args>
class Handler : public Impl<R, Args...> {
    F &function_;
public:
    explicit Handler(F& f) : function_(f) {}

    Handler* copy() const {
        return new Handler(*this);
    }

    R operator()(Args... args) const {
        return function_.operator()(args...);
    }
};

template <typename R, typename... Args>
class Functor {
    Impl<R, Args...>* impl;
public:
    Functor() {}

    template <typename F>
    Functor(F &f) : impl(new Handler<F, R, Args...>(f)) {}

    Functor& operator=(const Functor &func) {
        if (impl) {
            delete impl;
        }
        impl = func.impl.copy();
        return *this;
    }

    R operator() (Args... args) {
        return (*impl)(args...);
    }
};
