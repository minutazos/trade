/*
** EPITECH PROJECT, 2021
** Trade
** File description:
** Candle class implementation
*/

#include "Candles.h"

Candles::Candles()
{
    this->btc_eth = new Pair("BTC_ETH");
    this->usdt_eth = new Pair("USDT_ETH");
    this->usdt_btc = new Pair("USDT_BTC");
}

void Candles::update(const std::string& info)
{
    std::vector<std::string> data = Settings::splitData(info,";");
    std::vector<std::string> pair;

    for (const std::string& aux : data) {
        pair = Settings::splitData(aux, ",");
        if (pair[0] == "BTC_ETH")
            this->btc_eth->appendData(pair);
        else if (pair[0] == "USDT_ETH")
            this->usdt_eth->appendData(pair);
        else
            this->usdt_btc->appendData(pair);
    }
}

Candles::~Candles()
{
    delete this->btc_eth;
    delete this->usdt_btc;
    delete this->usdt_eth;
}

Pair *Candles::getUsdtEth() const
{
    return (usdt_eth);
}

Pair *Candles::getUsdtBtc() const
{
    return (usdt_btc);
}

Pair *Candles::getBtcEth() const
{
    return (btc_eth);
}
