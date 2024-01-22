/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:30:53 by achraiti          #+#    #+#             */
/*   Updated: 2023/12/30 19:12:41 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include "libft/libft.h"

# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define TILE_SIZE	32
# define MOVE_STEP	32

typedef struct map
{
	char	**map;
	char	**map2;
	int		rows;
	int		cols;
	int		coins;
	int		x;
	int		y;
	int		valid;
	int		exitfound;
	int		coin_count;
}	t_Mapinfo;

typedef struct sap
{
	char	**map;
	int		rows;
	int		cols;
	int		player_pos_x;
	int		player_pos_y;
	int		x;
	int		y;
	void	*mlx;
	void	*img;
	void	*win;
	void	*wall;
	void	*floor;
	void	*colle;
	void	*p;
	void	*exit;
	int		imgw;
	int		imgh;
	int		moving;
	int		direction;
	int		can_exit;
	int		mv;
	int		coins;
}	t_info;

int		check_if_rectangle(char **map);
int		check_duplicate_exit_start(char **map);
int		check_map_close(char **map);
int		check_car(char **map);
char	**read_and_join_map(int fd);
void	print_error(char *error);
int		map_checker(int fd, t_Mapinfo *mapinfo);
void	show_window(t_Mapinfo *mapinfo);
int		valid_path(char **map, t_Mapinfo *mapinfo);
int		handle(char **map, int exit, int start, int cole);
void	find_player_position(t_Mapinfo *mapinfo);
int		check_new_line(char *map);
int		is_ber_file(char *file);
void	free_map(char **map, int rows);
char	**copy_map(char **original, int rows, int cols);
void	flood_fill(t_Mapinfo *mapinfo, int x, int y);
void	draw_map(t_info *i);
int		handle_keypress(int key, t_info *i);
void	update_movements(t_info *i);
void	exit_game(t_info *i, const char *message);
int		handle_keypress(int key, t_info *i);
void	move_player(t_info *i, int dx, int dy);
int		handle_close_window(t_info *i);
int		close_window(t_info *i);
void	free_map(char **map, int rows);
void	handleee(t_info *i, int new_x, int new_y);
void	handle_image(t_info *i, int x, int y);

#endif