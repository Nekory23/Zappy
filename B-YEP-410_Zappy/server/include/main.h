/*
** EPITECH PROJECT, 2021
** EpitechTools
** File description:
** main
*/

#ifndef MAIN_H_
#define MAIN_H_

/* INCLUDE */
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <signal.h>
#include <uuid/uuid.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

/* STATIC CONST */
static const char STR_ERROR[] = "Error: ";
static const char ERR_ARG_NBR[] = "This program takes 1 argument.\n";
static const char ERR_PORT[] = "Argument must be a port number.\n";

static const int SUCCESS = 0;
static const int FAIL = 1;
static const int ERROR = 84;

static volatile sig_atomic_t run = 1;

/* STRUCTURES */
typedef struct server_s {
    int port;
    int sockfd;
    int queue;
    struct sockaddr_in address;
    socklen_t size_addr;
    socklen_t size_socket;
    int nb_client;
    int width;
    int height;
    char **names;
    int clientNb;
    float f;
} server_t;

typedef struct data_s
{
    int fd;
    char *ip;
    bool is_connected;
    char **cmd;
    char *uuid;
    char *name;
    struct sockaddr_in addr;
} data_t;

typedef struct client_s {
    int sockfd;
    struct sockaddr_in address;
    fd_set active_fd;
    fd_set read_fd;
    data_t **data;
} client_t;

/* PROTOTYPES */
int checkArguments(int argc, char **argv, server_t *st);
bool init_server(server_t *s);
bool start_server(server_t *server, client_t *client);
bool handle_client(server_t *server, client_t *client);
bool new_client(server_t *server, client_t *client, int fd);

#endif /* !MAIN_H_ */
