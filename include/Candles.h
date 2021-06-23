/*
** EPITECH PROJECT, 2021
** Trade
** File description:
** Candle class definition
*/

#ifndef TRADE_CANDLES_H
#define TRADE_CANDLES_H

#include "Pair.h"
#include <utility>
#include "Settings.h"

class Candles {
private:
    Pair *usdt_eth;
    Pair *usdt_btc;
    Pair *btc_eth;
public:
    Pair *getUsdtEth() const;
    Pair *getUsdtBtc() const;
    Pair *getBtcEth() const;

public:
    Candles();
    ~Candles();
    void update(const std::string& info);
};


#endif //TRADE_CANDLES_H
