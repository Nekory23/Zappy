/*
** EPITECH PROJECT, 2021
** EpitechTools
** File description:
** main
*/

#include "main.h"

void printHelp()
{
    printf("USAGE: ./zappy_server -p port -x width");
    printf(" -y height -n name1 name2 ... -c clientsNb -f freq\n");
    printf("\tport\t\tis the port number\n");
    printf("\twidth\t\tis the width of the world\n");
    printf("\theight\t\tis the height of the world\n");
    printf("\tnameX\t\tis the name of the team X\n");
    printf("\tclientsNb\tis the number of authorized clients per team\n");
    printf("\tfreq\t\tis the reciprocal of time unit for execution of actions\n");
}

int main(int argc, char **argv)
{
    server_t *st = malloc(sizeof(server_t));
    client_t *client = malloc(sizeof(client_t));

    (void) argc;
    if (argc < 2)
        return ERROR;
    if (strcmp(argv[1], "-help") == 0) {
        printHelp();
        return SUCCESS;
    }
    if (argc < 13)
        return ERROR;
    else if (checkArguments(argc, argv, st) == ERROR)
        return ERROR;
    if (init_server(st) == true || start_server(st, client) == true)
        return ERROR;
    return SUCCESS;
}