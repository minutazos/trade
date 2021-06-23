/*
** EPITECH PROJECT, 2021
** Trade
** File description:
** Trading bot
*/

#ifndef TRADE_BOT_H
#define TRADE_BOT_H

#include "Settings.h"
#include "Wallet.h"
#include "Candles.h"

enum Tendency {
    UP,
    DOWN,
    NONE
};

class Bot {
private:
    Settings settings;
    Wallet *wallet;
    Candles *candles;
    const size_t period = 20;
    size_t numCandles;
    enum Tendency tendency;
    enum Tendency oldTendency;
    double maxValue;
    double actualValue;
    double lastValue;
    double lastStack;

    void takeAction();
    void updateTendency();
    void updateStack(const std::string& stacks);

public:
    Bot();
    ~Bot();
    void run();
};


#endif //TRADE_BOT_H
