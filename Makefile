# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 22:09:41 by ncontin           #+#    #+#              #
#    Updated: 2024/10/23 18:13:26 by ncontin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c ft_putchar.c ft_putnbr_uns.c ft_putnbr.c ft_putstr.c ft_puthex.c ft_putptr.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
OBJ = $(SRC:.c=.o)
RM = rm -f

all: ${NAME}

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
	$(RM) ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re






