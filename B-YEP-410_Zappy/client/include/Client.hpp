/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Client
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include <string>

namespace core {
    class Core {
        public :
            explicit Core(int ac, char **av) noexcept;
            ~Core() = default;
            void StartGraph() noexcept;

        private :
            int _port;
            std::string _machine;
    };
};

static const int SUCCESS = 0;
static const int FAIL = 1;
static const int ERROR = 84;

#endif /* !CLIENT_HPP_ */
