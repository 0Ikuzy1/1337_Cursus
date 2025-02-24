# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 15:13:20 by ozouine           #+#    #+#              #
#    Updated: 2024/05/08 16:33:49 by ozouine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BNAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_split.c push.c rotation.c utils.c basic_instructions.c\
		linked_functions.c strjoin.c ft_putstr_fd.c mini_sort.c\
		reverse_rotation.c swap.c Push_Swap.c errors.c algo.c\
		final_fct.c\
		
BSRC = ft_split.c bonus/push_bonus.c bonus/rotation_bonus.c utils.c basic_instructions.c\
		linked_functions.c strjoin.c ft_putstr_fd.c mini_sort.c\
		bonus/reverse_rotation_bonus.c bonus/swap_bonus.c errors.c algo.c final_fct.c\
		bonus/bonus_help.c bonus/bonus_utils.c\
		bonus/get_next_line.c bonus/checker.c\

OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(BNAME): $(BOBJS)
	$(CC) $(CFLAGS) $(BOBJS) -o $(BNAME)

bonus: $(BNAME)

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME) $(BNAME)

re: fclean all