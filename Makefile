# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/24 13:16:13 by pcrosnie          #+#    #+#              #
#    Updated: 2016/08/22 16:43:15 by pcrosnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = paulo_player

LIB = libft/libft.a

SRC = main.c ft_parse_info.c

SRCO = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra

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
