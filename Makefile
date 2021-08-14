# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/07 16:59:54 by mdaillet          #+#    #+#              #
#    Updated: 2021/08/13 10:11:35 by mdaillet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server

CLIENT = client

CC = gcc $(FLAGS)

FLAGS = -Wall -Werror -Wextra

SERVER_SRC = server_main.c ft_utils.c 

CLIENT_SRC = client_main.c  ft_utils.c

SERVER_SRC_OBJ	= $(SERVER_SRC:.c=.o)

CLIENT_SRC_OBJ	= $(CLIENT_SRC:.c=.o)

all : fclean $(SERVER_SRC_OBJ) $(CLIENT_SRC_OBJ)
				@$(CC) $(SERVER_SRC) minitalk.h -o server
				@$(CC) $(CLIENT_SRC) minitalk.h -o client

clean :
	@rm -rf *.o *.o

fclean: clean
	@rm -rf $(SERVER) $(CLIENT)

re: fclean all

.PHONY : all clean fclean

