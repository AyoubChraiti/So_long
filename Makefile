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

SRC = check_map.c so_long.c check_path.c map_checker.c show_window.c moving.c helpers.c

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