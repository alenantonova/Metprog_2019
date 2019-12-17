#pragma once

#include <string>
#include <stdexcept>
#include <utility>
#include <iostream>

#include "Acceptor.h"

class EURExchangeAcceptor : public Acceptor<double> {
    double exchange_cny_coeff = 0.14;
    double exchange_rub_coeff = 0.016;
public:
    double getExchangeCoeff(const std::string& country) {
        if (country == "RU") {
            return exchange_rub_coeff;
        } else if (country == "CN") {
            return exchange_cny_coeff;
        }

        return -1;
    }

    double accept(Visitor<double>* visitor) override {
        return visitor->visit(this);
    }
};

class USDExchangeAcceptor : public Acceptor<double> {
    double exchange_cny_coeff = 0.13;
    double nb_exchange_cny_coeff = 2.06;
    double exchange_rub_coeff = 0.014;
    double nb_exchange_rub_coeff = 0.23;
public:
    double  getExchangeCoeff(const std::string& country, const std::string& dollar_counry) {
        if (country == "RU") {
            if (dollar_counry == "USA") {
                return exchange_rub_coeff;
            } else if (dollar_counry == "NA") {
                return nb_exchange_rub_coeff;
            }
        } else if (country == "CN") {
            if (dollar_counry == "USA") {
                return exchange_cny_coeff;
            } else if (dollar_counry == "NA") {
                return nb_exchange_cny_coeff;
            }
        }
        return -1;
    }

    double accept(Visitor<double>* visitor) override {
        return visitor->visit(this);
    }
};

class BankVisitor : public Visitor<double> {
protected:
    double balance;
    std::string dollar_country;
public:
    BankVisitor(double init_balance, std::string dollar_country) : balance(init_balance),
                                                                      dollar_country(std::move(dollar_country)) {}
    double get_balance() { return balance; }
    std::string get_usd_country() { return dollar_country; }

};

class RussianVisitor : public BankVisitor {
    std::string currency;
public:
    RussianVisitor(double init_balance, std::string dollar_country) : BankVisitor(init_balance, std::move(dollar_country)), currency("RUB") {}

    std::string get_currency() { return currency; }

    double visit(USDExchangeAcceptor* acc) override {;
        double coef = acc->getExchangeCoeff("RU", dollar_country);
        if (coef > 0) {
            balance *= coef;
            currency = "USD (" + dollar_country + ")";
            return 1;
        } else {
            std::cout << "Can't provide RUB->USD exchange\n";
            return -1;
        }
    }

    double visit(EURExchangeAcceptor* acc) override {
        double coef = acc->getExchangeCoeff("RU");
        if (coef > 0) {
            balance *= coef;
            currency = "EUR";
            return 1;
        } else {
            std::cout << "Can't provide RUB->EUR exchange\n";
            return -1;
        }
    }

};

class ChineseVisitor : public BankVisitor {
    std::string currency;
public:
    ChineseVisitor(double init_balance, std::string dollar_country) : BankVisitor(init_balance, std::move(dollar_country)),
    currency("CNY") {}

    std::string get_currency() { return currency; }

    double visit(USDExchangeAcceptor* acc) override {
        double coef = acc->getExchangeCoeff("CN", dollar_country);
        if (coef > 0) {
            balance *= coef;
            currency = "USD (" + dollar_country + ")";
            return 1;
        } else {
            std::cout << "Can't provide CNY->USD exchange\n";
            return -1;
        }
    }

    double visit(EURExchangeAcceptor* acc) override {
        double coef = acc->getExchangeCoeff("CN");
        if (coef > 0) {
            balance *= coef;
            currency = "EUR";
            return 1;
        } else {
            std::cout << "Can't provide CNY->EUR exchange\n";
            return -1;
        }
    }

};

class RUB_USDExchangeFunctor {
public:
   void operator()(RussianVisitor& visitor, USDExchangeAcceptor& acceptor) {
       std::cout << "Providing exchange " + visitor.get_currency() + "->USD(" + visitor.get_usd_country() + ")"
       + " with coef = " + std::to_string(acceptor.getExchangeCoeff("RU", visitor.get_usd_country())) << std::endl;
   }
};

class CNY_EURExchangeFunctor {
public:
    void operator()(ChineseVisitor& visitor, EURExchangeAcceptor& acceptor) {
        std::cout << "Providing exchange " + visitor.get_currency() + "->EUR"
                     + " with coef = " + std::to_string(acceptor.getExchangeCoeff("CN")) << std::endl;
    }
};

