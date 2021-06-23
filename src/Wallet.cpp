/*
** EPITECH PROJECT, 2021
** Trade
** File description:
** Wallet class definition
*/

#include "Wallet.h"

double Wallet::get(Coin_t pair)
{
    switch(pair) {
        case Coin_t::USDT:
            return (this->usdt);
        case Coin_t::BTC:
            return (this->btc);
        case Coin_t::ETH:
            return (this->eth);
        default:
            throw std::runtime_error("Retrieving wallet info");
    }
}

void Wallet::add(Coin_t pair, double amount)
{
    switch(pair) {
        case Coin_t::USDT:
            if (this->usdt + amount < 0)
                throw (84);
            this->usdt += amount;
            break;
        case Coin_t::BTC:
            if (this->btc + amount < 0)
                throw (84);
            this->usdt += amount;
            break;
        case Coin_t::ETH:
            if (this->eth + amount < 0)
                throw (84);
            this->usdt += amount;
            break;
        default:
            throw std::runtime_error("Adding money to wallet");
    }
}

void Wallet::set(Coin_t pair, double amount)
{
    switch(pair) {
        case Coin_t::ETH:
            this->eth = amount;
            break;
        case Coin_t::BTC:
            this->btc = amount;
            break;
        case Coin_t::USDT:
            this->usdt = amount;
            break;
    }
}
