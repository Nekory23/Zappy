/*
** EPITECH PROJECT, 2021
** B-YEP_Zappy
** File description:
** IScreen
*/

#ifndef ISCREEN_HPP_
#define ISCREEN_HPP_

#include "irrlicht.h"

namespace graph {
    class IScreen {
        public :
            ~IScreen() = default;

            virtual void draw(irr::IrrlichtDevice *window) = 0;
    };
}

#endif /* !ISCREEN_HPP_ */
