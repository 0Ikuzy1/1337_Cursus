CC := cc
MLXFLAGS :=    -lX11 -lXext -lmlx -lm
CFLAGS := -g -Wall -Wextra -Werror

RM := rm -f
NAME := cub3d
SRC :=  main.c \
		./sources/actions.c \
		./sources/create_map.c \
		./sources/parse.c \
		./sources/parse0.c \
		./sources/player.c \
		./sources/process_map.c \
		./sources/raycast_utils.c \
		./sources/raycast.c \
		./sources/read_map.c \
		./sources/render.c \
		./sources/textures.c \
		./sources/vectors.c \
		./sources/validate_map.c \

OBJ := $(SRC:.c=.o)
LIBFT := ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC)  $(OBJ) $(CFLAGS)  $(MLXFLAGS) $(LIBFT) -o $(NAME) 

$(LIBFT):
	make -C ./libft

clean:
	$(RM) $(OBJ)
	make clean -C ./libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./libft

re: fclean all