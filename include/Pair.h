/*
** EPITECH PROJECT, 2021
** Trade
** File description:
** Pair class definition
*/


#ifndef TRADE_PAIR_H
#define TRADE_PAIR_H

#include <string>
#include <exception>
#include <utility>
#include <vector>
#include <iostream>
#include <utility>

class Pair {
public:
    explicit Pair(std::string name) : pair(std::move(name)), avg(0) {};
    void appendData(std::vector<std::string> data);
    double getAvg(size_t period);
    std::string pair;
    std::vector<unsigned long> date;
    std::vector<double> high;
    std::vector<double> low;
    std::vector<double> open;
    std::vector<double> close;
    std::vector<unsigned long> volume;
    double avg;
};


#endif //TRADE_PAIR_H
