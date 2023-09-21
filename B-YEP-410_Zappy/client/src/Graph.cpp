/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Graph
*/

#include "Graph.hpp"
#include "Screen.hpp"

graph::Graph::Graph() noexcept
{
    _window = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1920, 1080));
    _window->setWindowCaption(L"Zappy");
    _receiver = new EventReceiver(_window, *this);
    _window->setEventReceiver(_receiver);
    _state = graph::stateGraph::MENU;
}

graph::Graph::~Graph()
{
    delete(_receiver);
}

bool graph::Graph::getIsOpen() const noexcept
{
    return _window->run();
}

irr::IrrlichtDevice *graph::Graph::getWindow() const noexcept
{
    return _window;
}

static void Draw(irr::IrrlichtDevice *window) noexcept
{
    window->getSceneManager()->drawAll();
    window->getGUIEnvironment()->drawAll();
    window->getVideoDriver()->endScene();
}

void graph::Graph::display(graph::Menu &menu, graph::Game &game) noexcept
{
    switch (_state) {
        case MENU:
            menu.draw(_window);
            break;
        case GAME:
            game.draw(_window);
            break;
        default:
            break;
    }
    if (_receiver->isKeyDown(irr::KEY_ESCAPE))
        _window->closeDevice();
    Draw(_window);
}