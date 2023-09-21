/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Graph
*/

#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <irrlicht.h>
#include <map>

namespace graph {
    class EventReceiver;
    class Menu;
    class Game;

    enum Buttons {
        // count
        BUTTON_COUNT
    };

    enum stateGraph {
        MENU,
        GAME
    };

    class Graph {
        public:
            Graph() noexcept;
            ~Graph();

            bool getIsOpen() const noexcept;
            irr::IrrlichtDevice *getWindow() const noexcept;
            void display(graph::Menu &menu, graph::Game &game) noexcept;

        protected:
        private:
            graph::EventReceiver *_receiver;
            int _state;

            irr::IrrlichtDevice *_window;
    };

    class EventReceiver : public irr::IEventReceiver {
        public:
            //EventReceiver() = default;
            explicit EventReceiver(irr::IrrlichtDevice *window, graph::Graph &graph) noexcept;

            bool OnEvent(const irr::SEvent &event) override;
            //bool click(const irr::SEvent &event) noexcept;
            bool keyInputs(const irr::SEvent &event) noexcept;

            virtual bool isKeyDown(irr::EKEY_CODE keyCode) const noexcept;
            //virtual bool isButtonPressed(Buttons) const noexcept;
            
            EventReceiver &operator=(const EventReceiver &copy);

            irr::IrrlichtDevice *getWindow() const noexcept;
            graph::Graph getGraph() const noexcept;
        private:
            irr::IrrlichtDevice *_window;
            graph::Graph &_graph;

            bool _keyIsDown[irr::KEY_KEY_CODES_COUNT];
            //bool _buttonClicked[BUTTON_COUNT];
    };
}

#endif /* !GRAPH_HPP_ */
