/*
** EPITECH PROJECT, 2021
** Trade
** File description:
** Settings class definition
*/

#include <cstring>
#include "Settings.h"

void Settings::dropLines(size_t num)
{
    std::string line;

    for (size_t i = 0; i < num && std::getline(std::cin, line); ++i);
}

std::vector<std::string> Settings::splitData(const std::string& info,
                                             const std::string& delim)
{
    std::vector<std::string> data;
    char *str = (char *)info.c_str();
    char *token = strtok(str, delim.c_str());

    while (token != nullptr) {
        data.emplace_back(token);
        token = strtok(nullptr, delim.c_str());
    }
    return (data);
}

Settings::Settings()
{
    std::string line;
    std::vector<std::string> aux;

    dropLines(4);
    std::getline(std::cin, line);
    this->interval = std::stol(splitData(line, " ").back());
    std::getline(std::cin, line);
    this->format = splitData(splitData(line, " ").back(), ",");
    std::getline(std::cin, line);
    this->total = std::stol(splitData(line, " ").back());
    std::getline(std::cin, line);
    this->given = std::stol(splitData(line, " ").back());
    std::getline(std::cin, line);
    this->stack = std::stol(splitData(line, " ").back());
    std::getline(std::cin, line);
    this->fee = std::stod(splitData(line, " ").back());
}

unsigned long Settings::getInterval() const
{
    return (interval);
}

const std::vector<std::string> &Settings::getFormat() const
{
    return (format);
}

unsigned long Settings::getTotal() const
{
    return (total);
}

unsigned long Settings::getGiven() const
{
    return (given);
}

unsigned long Settings::getStack() const
{
    return (stack);
}

double Settings::getFee() const
{
    return (fee);
}
