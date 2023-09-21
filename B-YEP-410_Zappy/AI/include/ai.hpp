/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** AI
*/

#ifndef AI
#define AI

#include "main.hpp"
#include "client.hpp"

enum Action {
    NoneAction,
    Forward,
    Right,
    Left,
    Look,
    Inventory,
    Broadcast_text,
    Connect_nbr,
    Fork,
    Eject,
    Take,
    Set,
    Incantation
};

enum Direction
{
    FORWARD,
    RIGHT,
    LEFT
};

struct Loot
{
    std::string item;
    unsigned int pos = 0;
};

struct Command
{
    Action action = NoneAction;
    std::string cmdstr;
    bool issent = false;
};

struct Map
{
    int x;
    int y;
};

class Player
{
private:
    int _port;
    std::string _name;
    std::string _machine;
    std::string msg;
    unsigned int _lvl = 1;
    unsigned int tile = 0;
    int life;
    int nb_player;
    Map map;
    Direction direction = FORWARD;
    std::vector<Loot> stuff;
    std::map<std::string, int> _stach;
    //server_t _serv;
    client_t _cli;
protected:
    Command cmd;
public:
    Player(int ac, char **av);
    ~Player();
    void process(void);
    void ai_algo(void);
    void connectServer(void);
    bool canElevate(void);
    const std::string &getName(void) const { return _name; }
    void setName(const std::string &name) { _name = name; }
    const std::string &getMsg(void) { return msg; }
    void setMsg(const std::string &message) { msg = message; }
    const int getLevel(void) { return _lvl; }
    void setLevel(int level) { _lvl = level; }
    const int getItems(std::string item) { return ((_stach.find(item) == _stach.end()) ? 0 : _stach.find(item)->second); }
    void setItems(const std::string &item, int n) { _stach[item] = n; }
    const int getnbPlayer() { return (this->nb_player); }
    void setnbPlayer(int n) { this->nb_player = n; }
    const std::vector<Loot> &getStuff(void) const {return stuff; }
    const int getTile(void) { return tile; }
    void setTile(int n) { tile = n; }
    void setDirection(Direction dir) { this->direction = dir; }
    Direction getDirection(void) { return (this->direction); }
    void move(void);
    bool isEnoughPlayer(void);
    bool isEnoughItems(void);
};

bool start_client(int port);

#endif /* !AI */
