# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 11:05:58 by achraiti          #+#    #+#              #
#    Updated: 2024/01/01 10:41:46 by achraiti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = src/check_map.c src/so_long.c src/check_path.c src/map_checker.c src/show_window.c src/moving.c src/helpers.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

LDFLAGS = -lmlx -framework OpenGL -framework AppKit

INCLUDES = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	cd libft && $(MAKE)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) -o $(NAME) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	rm -f libft/*.o
	rm -rf $(OBJ)

fclean: clean
	rm -f libft/libft.a
	rm -rf $(NAME)

re: fclean all

.PHONY: clean re all fclean