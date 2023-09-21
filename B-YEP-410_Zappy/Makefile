##
## EPITECH PROJECT, 2021
## B-YEP_Zappy
## File description:
## Makefile
##

SERVER_BIN	=	zappy_server
AI_BIN		=	zappy_ai
CLIENT_BIN	=	zappy_gui

all:	zappy_server zappy_ai zappy_gui

zappy_server:
	make -C server/ -f Makefile -s
	mv server/$(SERVER_BIN) ./

zappy_ai:
	make -C AI/ -f Makefile -s
	mv AI/$(AI_BIN) ./

zappy_gui:
	make -C client/ -f Makefile -s
	mv client/$(CLIENT_BIN) ./

tests_run:
	@rm -f $(SERVER_BIN)
	@printf "[\033[0;31mdestroyed\033[0m] % 30s\n" $(SERVER_BIN) | tr ' ' '.'
	make tests_run -C server/ -f Makefile -s
	@rm -f $(AI_BIN)
	@printf "[\033[0;31mdestroyed\033[0m] % 30s\n" $(AI_BIN) | tr ' ' '.'
	make tests_run -C AI/ -f Makefile -s

coverage:
	make coverage -C server/ -f Makefile -s
	make coverage -C AI/ -f Makefile -s

clean:
	make clean -C server/ -f Makefile -s
	make clean -C AI/ -f Makefile -s

fclean:
	make fclean -C server/ -f Makefile -s
	@printf "[\033[0;31mdestroyed\033[0m] % 30s\n" $(SERVER_BIN) | tr ' ' '.'
	@rm -f $(SERVER_BIN)
	make fclean -C AI/ -f Makefile -s
	@printf "[\033[0;31mdestroyed\033[0m] % 30s\n" $(AI_BIN) | tr ' ' '.'
	@rm -f $(AI_BIN)
	@printf "[\033[0;31mdestroyed\033[0m] % 30s\n" $(CLIENT_BIN) | tr ' ' '.'
	@rm -f $(CLIENT_BIN)

re:		fclean all

.PHONY: all zappy_server clean fclean re