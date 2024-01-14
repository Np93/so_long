# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 19:07:37 by nhirzel           #+#    #+#              #
#    Updated: 2021/12/09 18:23:57 by nhirzel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

CFLAGS	= -Wall -Wextra -Werror -Imlx #-fsanitize=address -g
OPTION	= -Lmlx -lmlx -lz -framework OpenGL -framework AppKit
RM		= rm -f
CC		= gcc

FILES	= src/get_next_line_utils.c \
		src/get_next_line.c \
		src/main.c \
		src/ft_itoa.c \
		src/draw_map.c \
		src/erreur_fin.c \
		src/info_div.c \
		src/load_map.c \

OBJS 	= $(FILES:.c=.o)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
		make -C mlx
		$(CC) $(CFLAGS) $(OPTION) -o $(NAME) $(OBJS)

all:	$(NAME)

clean:
		make clean -C mlx
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
