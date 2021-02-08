# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/06 19:27:19 by nle-biha          #+#    #+#              #
#    Updated: 2021/02/07 15:51:10 by nle-biha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_printf.c printf_convert.c printf_parsing.c printf_utils.c printf_display.c printf_utils2.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	@make all -C libft
	ar rcs ${NAME} ${OBJS} libft/ft_*.o
	ranlib ${NAME}


all: ${NAME}

clean:
	@make fclean -C libft
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
