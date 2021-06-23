/*
** EPITECH PROJECT, 2021
** Trade
** File description:
** Pair class implementation
*/

#include "Pair.h"

void Pair::appendData(std::vector<std::string> data)
{
    try {
        this->date.push_back(std::stoul(data[1]));
        this->high.push_back(std::stod(data[2]));
        this->low.push_back(std::stod(data[3]));
        this->open.push_back(std::stod(data[4]));
        this->close.push_back(std::stod(data[5]));
        this->volume.push_back(std::stoul(data[6]));
    } catch (std::exception const &e) {
        std::cout << "Failed appending data to Pair\n" << e.what() << std::endl;
    }
}

double Pair::getAvg(size_t period)
{
    double hAvg = 0;
    double lAvg = 0;

    for (unsigned long i = period - 1; i != 0; --i) {
        hAvg += high[high.size() - i];
        lAvg += low[low.size() - i];
    }
    hAvg = hAvg / (double) period;
    lAvg = lAvg / (double) period;
    avg = (hAvg + lAvg) / 2;
    return (avg);
}
