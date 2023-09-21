/*
** EPITECH PROJECT, 2021
** EpitechTools
** File description:
** main
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

/* INCLUDE */
#include <stdbool.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <uuid/uuid.h>
#include <arpa/inet.h>
#include <signal.h>
#include <stdlib.h>
#include <iostream>

/* STRUCTURES */
typedef struct client_s
{
    int sockfd;
    struct sockaddr_in servaddr;
    fd_set fd;
} client_t;

/* STATIC CONST */
static const int SUCCESS = 0;
static const int FAIL = 1;
static const int ERROR = 84;

static volatile sig_atomic_t run = 1;

/* PROTOTYPE */
bool start_client(char *port_arg);

#endif /* !MAIN_H_ */