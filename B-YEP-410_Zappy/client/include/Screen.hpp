/*
** EPITECH PROJECT, 2021
** B-YEP_Zappy
** File description:
** Screens
*/

#ifndef SCREENS_HPP_
#define SCREENS_HPP_

#include <map>
#include "irrlicht.h"
#include "IScreen.hpp"

namespace graph {
    class Menu : public IScreen {
        public :
            Menu(irr::IrrlichtDevice *window) noexcept;
            ~Menu();

            void draw(irr::IrrlichtDevice *window) noexcept;

        private :
            std::map<std::string, irr::video::ITexture *> _textures;
    };

    class Game : public IScreen  {
        public :
            Game(irr::IrrlichtDevice *window) noexcept;
            ~Game();

            void draw(irr::IrrlichtDevice *window) noexcept;

        private :
            std::map<std::string, irr::video::ITexture *> _textures;
    };
}

#endif /* !SCREENS_HPP_ */
