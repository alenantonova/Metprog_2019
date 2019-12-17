#include <iostream>
#include <vector>
#include "Functor.h"
#include "BankExchange.h"
#include "VisitFactory.h"
#include "TypeListUtils.h"

void runFunctorDemonstration() {
    auto ruTestVisitor = new RussianVisitor(200.98, "USA");
    auto cnTestVisitor = new ChineseVisitor(487.01, "NA");

    auto usdTestAcceptor = new USDExchangeAcceptor();
    auto eurTestAcceptor = new EURExchangeAcceptor();

    auto f1 = new RUB_USDExchangeFunctor();
    Functor<void, RussianVisitor, USDExchangeAcceptor> firstExchangeFunctor(*f1);
    firstExchangeFunctor.operator()(*ruTestVisitor, *usdTestAcceptor);

    auto f2 = new CNY_EURExchangeFunctor();
    Functor<void, ChineseVisitor, EURExchangeAcceptor> secondExchangeFunctor(*f2);
    secondExchangeFunctor.operator()(*cnTestVisitor, *eurTestAcceptor);

}
void runTestBankVisitFactory() {
    VisitFactory<TypeList<RussianVisitor, ChineseVisitor>, TypeList<USDExchangeAcceptor, EURExchangeAcceptor>,
            TypeList<RUB_USDExchangeFunctor, CNY_EURExchangeFunctor>> ExchangeVisitFactory;

    std::vector<BankVisitor *> bank_visitors = {new RussianVisitor(200.98, "USA"),
                                                    new ChineseVisitor(487.01, "NA")};

    std::vector<Acceptor<double> *> bank_acceptors = {new USDExchangeAcceptor(), new EURExchangeAcceptor()};

    ExchangeVisitFactory.Go(bank_visitors[0], bank_acceptors[0]);
    assert(bank_visitors[0]->get_balance() - 2.81372 < 1e-13);

    ExchangeVisitFactory.Go(bank_visitors[1], bank_acceptors[1]);
    assert(bank_visitors[1]->get_balance() - 68.1814 < 1e-13);

    std::cout << "All tests passed" << std::endl;
}

int main() {
    runFunctorDemonstration();
    runTestBankVisitFactory();
    return 0;
}