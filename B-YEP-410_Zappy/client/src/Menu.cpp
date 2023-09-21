/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Menu
*/

#include "Screen.hpp"

graph::Menu::Menu(irr::IrrlichtDevice *window) noexcept
{
    _textures.emplace(std::string("background"), window->getVideoDriver()->getTexture("assets/background.png"));
}

graph::Menu::~Menu()
{
}

void graph::Menu::draw(irr::IrrlichtDevice *window) noexcept
{
    window->getVideoDriver()->draw2DImage(_textures["background"], irr::core::position2d<irr::s32>(0, 0),
        irr::core::rect<irr::s32>(0, 0, 1920, 1080), nullptr, irr::video::SColor(255, 255, 255, 255), true);
}