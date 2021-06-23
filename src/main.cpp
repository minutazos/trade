/*
** EPITECH PROJECT, 2021
** Trade
** File description:
** Program entry point
*/

#include <exception>
#include <iostream>
#include "Bot.h"

int main(int ac, char **av)
{
    (void) ac;
    (void) av;
    Bot bot;

    try {
        bot.run();
        return (0);
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
}