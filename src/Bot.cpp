/*
** EPITECH PROJECT, 2021
** Trade
** File description:
** Trading bot implementation
*/

#include "Bot.h"

Bot::Bot()
{
    this->wallet = new Wallet((double) this->settings.getStack(), 0.0, 0.0);
    this->candles = new Candles();
    numCandles = 0;
    lastStack = 0;
    maxValue = 0;
    lastValue = 0;
    actualValue = 0;
    oldTendency = Tendency::NONE;
    tendency = Tendency::NONE;
}

Bot::~Bot()
{
    delete this->wallet;
    delete this->candles;
}

void Bot::updateTendency()
{
    std::vector<double> high = this->candles->getUsdtEth()->high;
    size_t size = high.size();
    double relative = (high[size - 1] / (high[size - period - 1] - 1)) * 100;
    double preRelative = (high[size - 2] / (high[size - period - 2] - 1)) * 100;

    if (tendency != Tendency::DOWN and relative < 100 and preRelative >= 100)
        tendency = Tendency::DOWN;
    else if (tendency != Tendency::UP and relative >= 100 and preRelative < 100)
        tendency = Tendency::UP;
}

void Bot::takeAction()
{
    if (oldTendency != tendency) {
        oldTendency = tendency;
        if (tendency == Tendency::UP and
            this->wallet->get(Coin_t::USDT) > actualValue) {
            maxValue = actualValue > maxValue ? actualValue : maxValue;
            std::cout << "buy USDT_ETH 0.2" << std::endl;
        } else if (tendency == Tendency::DOWN and
                    this->wallet->get(Coin_t::ETH) > 0.3)
                std::cout << "sell USDT_ETH 0.2" << std::endl;
        else
            std::cout << "pass" << std::endl;
    } else if (this->wallet->get(Coin_t::ETH) > 0.3 and
                actualValue > lastValue)
        std::cout << "sell USDT_ETH 0.3" << std::endl;
    else
        std::cout << "pass" << std::endl;
}

void Bot::updateStack(const std::string& stacks)
{
    std::vector<std::string> pairs = Settings::splitData(stacks, ",");
    std::vector<std::string> aux;
    double amount;

    for(const std::string& str : pairs) {
        aux = Settings::splitData(str, ":");
        amount = std::stod(aux[1]);
        if (aux[0] == "USDT") {
            this->wallet->set(Coin_t::USDT, amount);
            if (lastStack != amount)
                lastStack = amount;
        } else if (aux[0] == "ETH")
            this->wallet->set(Coin_t::ETH, amount);
        else
            this->wallet->set(Coin_t::BTC, amount);
    }
}

void Bot::run()
{
    std::vector<std::string> aux;

    for(std::string line; getline(std::cin, line);) {
        aux = Settings::splitData(line, " ");
        if (aux[0] == "update" and aux[2] == "next_candles") {
            this->candles->update(aux[3]);
            this->lastValue = actualValue;
            this->actualValue = this->candles->getUsdtEth()->high.back();
            this->numCandles++;
            if (this->numCandles == this->period) {
                updateTendency();
                this->numCandles = 0;
            }
        }
        else if (aux[0] == "action" and aux[1] == "order")
            this->takeAction();
        else
            this->updateStack(aux[3]);
    }
}