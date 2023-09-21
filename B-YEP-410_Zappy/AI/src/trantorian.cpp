/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** ai's useful functions
*/

#include "ai.hpp"

bool Player::canElevate(void)
{
    if (_lvl == 1 && getItems("linemate") >= 1 && getnbPlayer() >= 1)
        return true;
    else if (_lvl == 2 && getItems("linemate") >= 1 && getItems("deraumere") >= 1 && getItems("sibur") >= 1 && getnbPlayer() >= 2)
        return true;
    else if (_lvl == 3 && getItems("linemate") >= 2 && getItems("sibur") >= 1 && getItems("phiras") >= 2 && getnbPlayer() >= 2)
        return true;
    else if (_lvl == 4 && getItems("linemate") >= 1 && getItems("deraumere") >= 1 && getItems("sibur") >= 2 && getItems("phiras") >= 1 && getnbPlayer() >= 4)
        return true;
    else if (_lvl == 5 && getItems("linemate") >= 1 && getItems("deraumere") >= 2 && getItems("sibur") >= 1 && getItems("mendiane") >= 3 && getnbPlayer() >= 4)
        return true;
    else if (_lvl == 6 && getItems("linemate") >= 1 && getItems("deraumere") >= 2 && getItems("sibur") >= 3 && getItems("phiras") >= 1 && getnbPlayer() >= 6)
        return true;
    else if (_lvl == 7 && getItems("linemate") >= 2 && getItems("deraumere") >= 2 && getItems("sibur") >= 2 && getItems("mendiane") >= 2 && getItems("phiras") >= 2 && getItems("thystame") >= 1 && getnbPlayer() >= 6)
        return true;
    return false;
}

bool Player::isEnoughPlayer(void)
{
    if (_lvl == 1 && getnbPlayer() >= 1)
        return true;
    else if (_lvl == 2 && getnbPlayer() >= 2)
        return true;
    else if (_lvl == 3 && getnbPlayer() >= 2)
        return true;
    else if (_lvl == 4 && getnbPlayer() >= 4)
        return true;
    else if (_lvl == 5 && getnbPlayer() >= 4)
        return true;
    else if (_lvl == 6 && getnbPlayer() >= 6)
        return true;
    else if (_lvl == 7 && getnbPlayer() >= 6)
        return true;
    return false;
}

bool Player::isEnoughItems(void)
{
    if (_lvl == 1 && getItems("linemate") >= 1 && getnbPlayer() >= 1)
        return true;
    else if (_lvl == 2 && getItems("linemate") >= 1 && getItems("deraumere") >= 1 && getItems("sibur") >= 1)
        return true;
    else if (_lvl == 3 && getItems("linemate") >= 2 && getItems("sibur") >= 1 && getItems("phiras") >= 2)
        return true;
    else if (_lvl == 4 && getItems("linemate") >= 1 && getItems("deraumere") >= 1 && getItems("sibur") >= 2 && getItems("phiras") >= 1)
        return true;
    else if (_lvl == 5 && getItems("linemate") >= 1 && getItems("deraumere") >= 2 && getItems("sibur") >= 1 && getItems("mendiane") >= 3)
        return true;
    else if (_lvl == 6 && getItems("linemate") >= 1 && getItems("deraumere") >= 2 && getItems("sibur") >= 3 && getItems("phiras") >= 1)
        return true;
    else if (_lvl == 7 && getItems("linemate") >= 2 && getItems("deraumere") >= 2 && getItems("sibur") >= 2 && getItems("mendiane") >= 2 && getItems("phiras") >= 2 && getItems("thystame") >= 1)
        return true;
    return false;
}

void Player::move(void)
{
    auto &loot = getStuff();
    int pos = getTile();

    if (pos == 4 || pos == 1 && getDirection() == LEFT) {
        cmd.action = Right;
        setDirection(RIGHT);
        return;
    }
    if (pos == 8 || pos == 3 && getDirection() == RIGHT) {
        cmd.action = Left;
        setDirection(LEFT);
        return;
    }
    if (pos == 0 || pos == 2 || (pos >= 4 && pos <= 8)) {
        setDirection(FORWARD);
        if (getTile() == 0)
            setTile(2);
        else if (getTile() >= 1 && getTile() <= 3)
            setTile(getTile() + 4);
        else if (getTile() >= 4 && getTile() <= 8)
            setTile(getTile() + 6);
        cmd.action = Forward;
        return;
    }
}