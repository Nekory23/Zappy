/*
** EPITECH PROJECT, 2021
** B-NWP_myTeams
** File description:
** connection
*/

#include "main.h"

static void handle_sig(int sig)
{
    (void) sig;
    run = 0;
}

bool start_loop(server_t *server, client_t * client)
{
    if (signal(SIGINT, handle_sig) == SIG_ERR) {
        perror("signal");
        return true;
    }
    while (run != 0) {
        client->read_fd = client->active_fd;
        if (select(FD_SETSIZE, &client->read_fd, NULL, NULL, NULL) < 0) {
            if (errno == EINTR)
                continue;
            perror("select");
            break;
        }
        if (handle_client(server, client))
            return true;
    }
    return false;
}

bool start_server(server_t *server, client_t *client)
{
    char *ip = inet_ntoa(server->address.sin_addr);

    FD_ZERO(&client->active_fd);
    FD_SET(server->sockfd, &client->active_fd);
    client->data = NULL;
    if (!strcmp(ip, "0.0.0.0"))
        printf("Server started on 127.0.0.1 %d\n", server->port);
    else
        printf("Server started on %s %d\n", ip, server->port);
    if (signal(SIGPIPE, SIG_IGN) == SIG_ERR) {
        perror("signal");
        return true;
    }
    return start_loop(server, client);
}