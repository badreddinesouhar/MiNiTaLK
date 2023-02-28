# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 06:47:15 by bsouhar           #+#    #+#              #
#    Updated: 2023/02/23 16:30:48 by bsouhar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc

CFLAGS= -Wall -Wextra -Werror

NAME = minitalk

CLIENT = client

SERVER = server

SERVERBONUS = server_bonus

CLIENTBONUS = client_bonus

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): server.c
	make -C libft/ all
	make -C printf/ all
	$(CC) $(CFLAGS) -o $@ $^ libft/libft.a printf/libftprintf.a

$(CLIENT): client.c
	make -C libft/ all
	make -C printf/ all
	$(CC) $(CFLAGS) -o $@ $^ libft/libft.a printf/libftprintf.a

$(BONUSNAME): $(SERVERBONUS) $(CLIENTBONUS)

$(SERVERBONUS) : server_bonus.c
	make -C libft/ all
	make -C printf/ all
	$(CC) $(CFLAGS) -o $@ server_bonus.c libft/libft.a printf/libftprintf.a

$(CLIENTBONUS) : client_bonus.c
	make -C libft/ all
	make -C printf/ all
	$(CC) $(CFLAGS) -o $@ client_bonus.c libft/libft.a printf/libftprintf.a

bonus: $(SERVERBONUS) $(CLIENTBONUS)

clean:
	make -C libft/ clean
	make -C printf/ clean

fclean: clean
	make -C libft/ fclean
	make -C printf/ fclean
	rm $(SERVER) $(CLIENT)
	rm $(CLIENTBONUS) $(SERVERBONUS)

re : fclean $(NAME)

.PHONY: all re clean fclean bonus
