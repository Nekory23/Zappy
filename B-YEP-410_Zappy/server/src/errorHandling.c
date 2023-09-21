/*
** EPITECH PROJECT, 2021
** EpitechTools
** File description:
** error handling
*/

#include "main.h"

bool checkFloat(char *str)
{
    for (int i = 0; str[i] != '\0'; ++i) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
            return false;
    }
    return true;
}

bool checkInt(char *str)
{
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

bool checkArgu(char a, char *next)
{
    if (a != 'p' && a != 'x' && a != 'y' && a != 'n' && a != 'c' && a != 'f')
        return false;
    if (a == 'p' && checkInt(next) == false)
        return false;
    if (a == 'x' && checkInt(next) == false)
        return false;
    if (a == 'y' && checkInt(next) == false)
        return false;
    if (a == 'c' && checkInt(next) == false)
        return false;
    if (a == 'f' && checkFloat(next) == false)
        return false;
    return true;
}

void setTeamsName(server_t *st, int i, char **argv)
{
    int nb = 0;

    for (int x = i + 1; argv[x] && argv[x][0] != '-'; x++)
        nb++;
    st->names = malloc(nb * sizeof(char *));
    nb = 0;
    for (int x = i + 1; argv[x] && argv[x][0] != '-'; x++, nb++) {
        st->names[nb] = malloc((strlen(argv[x]) + 1) * sizeof(char));
        st->names[nb] = strcat(st->names[nb], argv[x]);
    }
}

void getArgu(server_t *st, int i, char **argv)
{
    if (argv[i][1] == 'p')
        st->port = atoi(argv[i + 1]);
    if (argv[i][1] == 'x')
        st->width = atoi(argv[i + 1]);
    if (argv[i][1] == 'y')
        st->height = atoi(argv[i + 1]);
    if (argv[i][1] == 'c')
        st->clientNb = atoi(argv[i + 1]);
    if (argv[i][1] == 'f')
        st->f = atof(argv[i + 1]);
    if (argv[i][1] == 'n')
        setTeamsName(st, i, argv);
}

int checkArguments(int argc, char **argv, server_t *st)
{
    for (int i = 0; i < (argc - 1); i++) {
        if (argv[i][0] == '-' && checkArgu(argv[i][1], argv[i + 1]) == false)
            return ERROR;
        else if (argv[i][0] == '-')
            getArgu(st, i, argv);
    }
    return SUCCESS;
}