/*
** EPITECH PROJECT, 2021
** Trade
** File description:
** Wallet class definition
*/

#ifndef TRADE_WALLET_H
#define TRADE_WALLET_H

#include <stdexcept>

typedef enum Coin_e {
    USDT,
    BTC,
    ETH
} Coin_t;

class Wallet {
private:
    double usdt;
    double btc;
    double eth;

public:
    Wallet(double usdt_, double btc_, double eth_) :
    usdt(usdt_), btc(btc_), eth(eth_) {};
    void set(Coin_t pair, double amount);
    double get(Coin_t pair);
    void add(Coin_t pair, double amount);
};


#endif //TRADE_WALLET_H
