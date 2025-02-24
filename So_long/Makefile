NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = parce_0.c so_long.c ft_split.c GNL/get_next_line_utils.c\
	 GNL/get_next_line.c mlx_fct.c player_movement.c floodfill.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJ) ./ft_printf/libftprintf.a ./MLX/libmlx.a  -L/usr/lib -lX11 -lXext -o $(NAME)
clean:
	rm -f $(OBJ)
	make clean -C ft_printf

fclean: clean
	rm -f $(NAME)
	make fclean -C ft_printf

re: fclean all
.SECONDARY: $(OBJ)