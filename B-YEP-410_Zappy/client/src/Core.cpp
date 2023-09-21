/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Core
*/

#include "Client.hpp"
#include "Graph.hpp"
#include "Screen.hpp"

core::Core::Core(int ac, char **av) noexcept
{
    _port = std::atoi(av[2]);
    if (ac == 5)
        _machine = av[4];
    else
        _machine = "localhost";
}

void core::Core::StartGraph() noexcept
{
    graph::Graph graph;
    graph::Menu menu(graph.getWindow());
    graph::Game game(graph.getWindow());

    while (graph.getIsOpen())
        graph.display(menu, game);
}