/*
** Created by ruby on 2021-11-28
** File : main.cpp
** description:
** main
*/

#include "../include/Daemon.hpp"

#include <stdio.h>
#include <stdlib.h>

int verif_if_number(const char *str)
{
    int i = 0;
    while (str[i] && str[i] >= 48 && str[i] <= 57)
        ++i;
    return str[i] != '\0' ? 0 : 1;
}

int print_help()
{
    printf("Usage: ./Dyson-Marvin [frequency]\n Default: 20 secondes");
    return 0;
}


int main(int ac, char **av)
{
    int frequency = 20;
    if (ac == 2) {
        if (verif_if_number(av[1]))
            frequency = atoi(av[1]);
    } else if (ac > 2)
        return print_help();;
    return EchDyson(frequency);

}