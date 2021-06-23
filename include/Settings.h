/*
** EPITECH PROJECT, 2021
** Trade
** File description:
** Settings for the bot
*/

#ifndef TRADE_SETTINGS_H
#define TRADE_SETTINGS_H


#include <string>
#include <vector>
#include <iostream>

class Settings {
private:
    unsigned long interval;
    std::vector<std::string> format;
    unsigned long total;
    unsigned long given;
    unsigned long stack;
    double fee;
    static void dropLines(size_t num);

public:
    static std::vector<std::string> splitData(const std::string& info,
                                              const std::string& delim);
    unsigned long getInterval() const;
    const std::vector<std::string> &getFormat() const;
    unsigned long getTotal() const;
    unsigned long getGiven() const;
    unsigned long getStack() const;
    double getFee() const;
    Settings();
};


#endif //TRADE_SETTINGS_H
