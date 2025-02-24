NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f



SRC = ft_printf.c  ft_putchar.c  ft_putnbr.c  ft_putstr.c ft_printadd.c ft_putlong.c ft_putnbr_base.c ft_strlen.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)
 
$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all