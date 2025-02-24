# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/24 19:43:10 by ozouine           #+#    #+#              #
#    Updated: 2024/12/25 11:08:32 by ozouine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = philo.c routine.c utils.c algo.c initializing.c mtx_fcnt.c

Objects = ${SRCS:.c=.o}

NAME = philo

CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=thread

Includes = philo.h

all : ${NAME}

${NAME} : ${Objects} 
	cc ${CFLAGS}  ${Objects} -pthread -o ${NAME}

clean :
	rm -f ${Objects}
fclean : clean
	rm -f ${NAME}
re : fclean all

.SECONDARY: $(Objects)
.PHONY: all clean fclean re