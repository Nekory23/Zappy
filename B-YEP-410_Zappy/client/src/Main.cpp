/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Main
*/

#include <string.h>
#include <iostream>
#include "Client.hpp"
#include "Graph.hpp"

static void displayHelp()
{
    std::cout << "USAGE: ./zappy_gui -p port -h machine";
    std::cout << std::endl << "\tport    is the port number";
    std::cout << std::endl << "\tmachine is the name of the machine; localhost by default";
    std::cout << std::endl;
}

static bool errorHandling(int ac, char **av)
{
    if (ac == 5) {
        if (strcmp(av[1], "-p") || strcmp(av[3], "-h"))    
            return true;
        for (auto i = 0; av[2][i] != '\0'; ++i)
            if (av[2][i] < '0' || av[2][i] > '9')
                return true;
    } else if (ac == 3) {
        if (strcmp(av[1], "-p"))
            return true;
        for (auto i = 0; av[2][i] != '\0'; ++i)
            if (av[2][i] < '0' || av[2][i] > '9')
                return true;
    } else
        return true;
    return false;
}

int main(int ac, char **av)
{
    if (ac == 2 && !strcmp(av[1], "-help"))
        displayHelp();
    else {
        if (errorHandling(ac, av)) {
            std::cerr << "Error: please retry with -help" << std::endl;
            return ERROR;
        }
        core::Core core(ac, av);
        core.StartGraph();
    }
    return SUCCESS;
}