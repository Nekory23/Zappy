/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** main
*/

#include "main.hpp"
#include "ai.hpp"
#include "client.hpp"

int main(int ac, char **av)
{
    if (ac == 2 && std::string(av[1]) == "-help") {
        std::cout << "USAGE: ./zappy_ai -p port -n name -h machine\n\
            \tport\tis the port number\n\
            \tname\tis the name of the team\n\
            \tmachine\tis the name of the machine; \
            localhost by default" << std::endl;
        return (0);
    }
    if (ac < 2)
        return (84);
    start_client(std::atoi(av[1]));
    Player ai(ac, av);
    ai.process();
    return (0);
}