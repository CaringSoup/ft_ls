# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gferreir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/24 08:44:46 by gferreir          #+#    #+#              #
#    Updated: 2018/09/27 14:38:30 by gferreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = main.c\
	  ft_print_normal.c\
	  ft_get_time.c\
	  ft_permissions.c\

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -I./libft -L libft -lft

%.o:	%.c
	gcc $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc -o $(NAME) $(CFLAGS) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
