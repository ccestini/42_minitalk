# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 13:32:50 by ccestini          #+#    #+#              #
#    Updated: 2022/06/16 17:30:25 by ccestini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

NAME	= minitalk

CLIENT			= client
CLIENT_BONUS	= client_bonus

SERVER			= server
SERVER_BONUS	= server_bonus

SRCS		= client.c server.c
SRCS_BONUS	= client_bonus.c server_bonus.c

OBJS		= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

all:	libft/libft.a $(SERVER) $(CLIENT)

bonus:	libft/libft.a $(SERVER_BONUS) $(CLIENT_BONUS)

$(NAME): all

libft/libft.a:
		$(MAKE) all -C libft

$(CLIENT): client.o
		$(CC) $(CFLAGS) libft/libft.a client.o -o client

$(CLIENT_BONUS): client_bonus.o
		$(CC) $(CFLAGS) libft/libft.a client_bonus.o -o client_bonus

$(SERVER): server.o
		$(CC) $(CFLAGS) libft/libft.a server.o -o server

$(SERVER_BONUS): server_bonus.o
		$(CC) $(CFLAGS) libft/libft.a server_bonus.o -o server_bonus
			
clean:
		$(RM) $(OBJS) $(OBJS_BONUS)
		$(MAKE) clean -C libft

fclean:	clean
		$(RM) server client server_bonus client_bonus
		$(MAKE) fclean -C libft

re:		fclean all

rebonus:		fclean bonus

.PHONY:	all clean fclean re bonus rebonus