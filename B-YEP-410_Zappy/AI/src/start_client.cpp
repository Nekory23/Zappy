/*
** EPITECH PROJECT, 2021
** B-NWP_myTeams
** File description:
** start_client
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "client.hpp"
#include "ai.hpp"
#include "main.hpp"

static void handle_sig(int sig)
{
    (void) sig;
    run = 0;
}

static bool gest_error(std::string error)
{
    std::cerr << error << std::endl;
    return true;
}

static bool client_loop(client_t client)
{
    signal(SIGINT, handle_sig);
    while (run != 0) {
        FD_ZERO(&client.fd);
        FD_SET(STDIN_FILENO, &client.fd);
        FD_SET(client.sockfd, &client.fd);
        if (select(client.sockfd + 1, &client.fd, NULL, NULL, NULL) == -1) {
            if (errno == EINTR)
                continue;
            else
                return (gest_error("select"));
        }
        // if (FD_ISSET(STDIN_FILENO, &client.fd)) {
        //     if (send_commands(client))
        //         break;
        // } else if (FD_ISSET(client->sockfd, &client.fd))
        //     read_answers(client);
    }
    return false;
}

static bool start_connection(client_t st, int port)
{
    int is_connected = 1;

    st.servaddr.sin_family = AF_INET;
    st.servaddr.sin_port = htons(port);
    st.sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (st.sockfd == -1) {
        std::cerr << "socket" << std::endl;
        return true;
    }
    is_connected = connect(st.sockfd, (struct sockaddr *) &st.servaddr,
    sizeof(st.servaddr));
    if (is_connected == -1) {
        std::cerr << "connect" << std::endl;
        return true;
    }
    return false;
}

bool start_client(int port)
{
    client_t st;

    if (start_connection(st, port))
        return true;
    std::cout << "You are connected to the server" << std::endl;
    if (client_loop(st))
        return true;
    // end_client(st);
    return false;
}