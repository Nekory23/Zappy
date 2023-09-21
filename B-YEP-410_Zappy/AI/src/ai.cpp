/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** ai
*/

#include "ai.hpp"
#include "main.hpp"

Player::Player(int ac, char **av)
{
    this->_port = 0;
    this->_name = "";
    this->_machine = "localhost";
    for (int i = 1; i < ac; i += 2) {
        if (strcmp(av[i], "-p") == 0)
            this->_port = std::atoi(av[i + 1]);
        if (strcmp(av[i], "-n") == 0)
            this->_name = av[i + 1];
        if (strcmp(av[i], "-h") == 0)
            this->_machine = av[i + 1];
    }
    start_client(this->_port);
}

void Player::ai_algo(void)
{
    if (canElevate()) {
        cmd.action = Incantation;
        return;
    }
    if ((getMsg() != "") && getLevel() > 1 /*&& isEnoughPlayer() */ && !stuff.empty()) {
        cmd.action = Take;
        cmd.cmdstr = stuff.front().item;
        stuff.erase(stuff.begin());
        return;
    }
    if (stuff.empty() && getTile()) {
        cmd.action = Look;
        setDirection(FORWARD);
        setTile(0);
        return;
    }
    cmd.action = Inventory;
    //move();
}

bool Player::canElevate()
{
    return false;
}

Player::~Player()
{
}

void Player::process(void)
{
    while (this->life > 0) {
        ai_algo();
        //sendaction();
        //client_loop(this->_cli);
    }
}