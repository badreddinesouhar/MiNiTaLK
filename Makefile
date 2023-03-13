# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 06:47:15 by bsouhar           #+#    #+#              #
#    Updated: 2023/03/13 14:38:25 by bsouhar          ###   ########.fr        #
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
	make -C ft_libft/ all
	make -C ft_printf/ all
	$(CC) $(CFLAGS) -o $@ $^ ft_libft/libft.a ft_printf/libftprintf.a

$(CLIENT): client.c
	make -C ft_libft/ all
	make -C ft_printf/ all
	$(CC) $(CFLAGS) -o $@ $^ ft_libft/libft.a ft_printf/libftprintf.a

$(BONUSNAME): $(SERVERBONUS) $(CLIENTBONUS)

$(SERVERBONUS) : server_bonus.c
	make -C ft_libft/ all
	make -C ft_printf/ all
	$(CC) $(CFLAGS) -o $@ server_bonus.c ft_libft/libft.a ft_printf/libftprintf.a

$(CLIENTBONUS) : client_bonus.c
	make -C ft_libft/ all
	make -C ft_printf/ all
	$(CC) $(CFLAGS) -o $@ client_bonus.c ft_libft/libft.a ft_printf/libftprintf.a

bonus: $(SERVERBONUS) $(CLIENTBONUS)

clean:
	make -C ft_libft/ clean
	make -C ft_printf/ clean

fclean:
	make -C ft_libft/ fclean
	make -C ft_printf/ fclean
	rm -f $(SERVER) $(CLIENT)
	rm -f $(CLIENTBONUS) $(SERVERBONUS)

re : fclean $(NAME)

.PHONY: all re clean fclean bonus
