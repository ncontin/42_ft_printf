# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noscrub <noscrub@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 22:09:41 by noscrub           #+#    #+#              #
#    Updated: 2024/10/22 23:06:53 by noscrub          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c ft_putchar.c ft_putnbr_uns.c ft_putnbr.c ft_putstr.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
OBJ = $(SRC:.c=.o)
RM = rm -f

all: ${NAME}

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
	$(RM) ${OBJ}

fclean:
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re






