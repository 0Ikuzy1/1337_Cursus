server = server
client = client
server_bonus = server_bonus
client_bonus = client_bonus

NAME = $(server) $(client)
NAME_BONUS = $(server_bonus) $(client_bonus)

CC = cc
CFLAGS = -Wall -Wextra -Werror

serversrc = server.c utils.c
clientsrc = client.c utils.c

server_bonussrc = server_bonus.c utils.c
client_bonussrc = client_bonus.c utils.c

server_OBJ = $(serversrc:.c=.o)
client_OBJ = $(clientsrc:.c=.o)
OBJ = $(server_OBJ) $(client_OBJ)

server_OBONUS = $(server_bonussrc:.c=.o)
client_OBONUS = $(client_bonussrc:.c=.o)
OBONUS = $(server_OBONUS) $(client_OBONUS)

all: $(NAME)

$(server): $(server_OBJ)
	$(CC) $(CFLAGS) $(server_OBJ) -o $(server)

$(client): $(client_OBJ)
	$(CC) $(CFLAGS) $(client_OBJ) -o $(client)

$(server_bonus): $(server_OBONUS)
	$(CC) $(CFLAGS) $(server_OBONUS) -o $(server_bonus)

$(client_bonus): $(client_OBONUS)
	$(CC) $(CFLAGS) $(client_OBONUS) -o $(client_bonus)

bonus: $(NAME_BONUS)

clean:
	rm -f $(OBJ) $(OBONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all