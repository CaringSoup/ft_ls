# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gferreir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/24 08:44:46 by gferreir          #+#    #+#              #
#    Updated: 2018/09/05 14:29:03 by gferreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftls.a

SRC =

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

%.o:	%.c
	gcc $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC)
	ar -rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
