# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/24 13:16:13 by pcrosnie          #+#    #+#              #
#    Updated: 2016/11/14 12:13:30 by pcrosnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pcrosnie.filler

LIB = libft/libft.a

SRC = src/main.c src/ft_parse_info.c src/ft_check_pos.c src/ft_algo.c

SRCO = $(SRC:.c=.o)

FLAG = -g -fsanitize=address -Wall -Werror -Wextra

all: $(NAME)


$(NAME): $(SRCO)
	make -C libft
	gcc $(FLAG) -c $(SRC)
	gcc -o $(NAME) $(SRCO) $(LIB)

clean:
	make -C libft clean
	rm -f $(SRCO)

fclean: clean
	make -C libft fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
