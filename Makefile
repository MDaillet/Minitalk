# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/07 16:59:54 by mdaillet          #+#    #+#              #
#    Updated: 2021/08/16 12:21:31 by mdaillet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server

CLIENT = client

CC = gcc $(FLAGS)

FLAGS = -Wall -Werror -Wextra

SERVER_SRC = server_main.c ft_utils.c 
SERVER_SRC_BONUS = server_main_bonus.c ft_utils.c      

CLIENT_SRC = client_main.c  ft_utils.c
CLIENT_SRC_BONUS = client_main_bonus.c  ft_utils.c

SERVER_SRC_OBJ	= $(SERVER_SRC:.c=.o)
SERVER_SRC_BONUS_OBJ  = $(SERVER_SRC_BONUS:.c=.o)

CLIENT_SRC_OBJ	= $(CLIENT_SRC:.c=.o)
CLIENT_SRC_BONUS_OBJ  = $(CLIENT_SRC_BONUS:.c=.o)

all : fclean $(SERVER_SRC_OBJ) $(CLIENT_SRC_OBJ)
				@$(CC) $(SERVER_SRC) minitalk.h -o server
				@$(CC) $(CLIENT_SRC) minitalk.h -o client

bonus : fclean $(SERVER_SRC_BONUS_OBJ) $(CLIENT_SRC_BONUS_OBJ)
				@$(CC) $(SERVER_SRC_BONUS) minitalk.h -o server
				@$(CC) $(CLIENT_SRC_BONUS) minitalk.h -o client

clean :
	@rm -rf *.o

fclean: clean
	@rm -rf $(SERVER) $(CLIENT)

re: fclean all

.PHONY : all clean fclean

