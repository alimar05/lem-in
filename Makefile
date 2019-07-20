# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rymuller <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/20 12:31:51 by rymuller          #+#    #+#              #
#    Updated: 2019/07/20 15:07:45 by rymuller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := lem-in

SRC :=	create_linked_list.c \
		free_linked_list.c \
		lem-in.c \
		parse_room.c \
		parse_link.c 

CFLAGS := -Wall -Wextra -Werror
HEADER := -I./libft/includes
LIB := -L./libft -lft -L./ft_printf -lftprintf

all: $(NAME)

$(NAME): $(SRC)
	make -C libft
	make -C ft_printf
	gcc $(CFLAGS) $(HEADER) $(SRC) $(LIB) -o $(NAME)

clean:
	make -C libft clean
	make -C ft_printf clean

fclean:
	make -C libft fclean
	make -C ft_printf fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean flcean all re