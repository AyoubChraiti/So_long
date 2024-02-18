/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:06:32 by achraiti          #+#    #+#             */
/*   Updated: 2024/02/18 16:15:20 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_movements(t_info *i)
{
	i->mv++;
	printf("Number of Movements is: %d\n", i->mv);
}

void	exit_game(t_info *i, const char *message)
{
	printf("%s\n", message);
	free_map(i->map, i->rows);
	mlx_destroy_window(i->mlx, i->win);
	exit(0);
}

int	handle_keypress(int key, t_info *i)
{
	if (key == 53)
		exit_game(i, "Game Over");
	else if (key == 123)
	{
		move_player(i, -1, 0);
		i->p = mlx_xpm_file_to_image(i->mlx, "image/player/left_move.xpm", &i->imgw, &i->imgh);
	}
	else if (key == 124)
	{
		move_player(i, 1, 0);
		i->p = mlx_xpm_file_to_image(i->mlx, "image/player/right_move.xpm", &i->imgw, &i->imgh);
	}
	else if (key == 125)
	{
		move_player(i, 0, 1);
		i->p = mlx_xpm_file_to_image(i->mlx, "image/player/down_move.xpm", &i->imgw, &i->imgh);
	}
	else if (key == 126)
	{
		move_player(i, 0, -1);
		i->p = mlx_xpm_file_to_image(i->mlx, "image/player/up_move.xpm", &i->imgw, &i->imgh);
	}
	mlx_clear_window(i->mlx, i->win);
	draw_map(i);
	return (0);
}

void	move_player(t_info *i, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = i->player_pos_x + dx;
	new_y = i->player_pos_y + dy;
	if (new_x >= 0 && new_x < i->cols && new_y >= 0 && new_y < i->rows)
	{
		handleee(i, new_x, new_y);
	}
}

void	handleee(t_info *i, int new_x, int new_y)
{
	if (i->map[new_y][new_x] != '1')
	{
		if (i->map[new_y][new_x] == 'C')
			i->coins--;
		if (i->map[new_y][new_x] == 'E' && i->coins == 0)
			exit_game(i, "Congratulations You Won!");
		if (i->map[new_y][new_x] == 'E' && i->coins != 0)
			return ;
		else
		{
			i->map[i->player_pos_y][i->player_pos_x] = '0';
			i->player_pos_x = new_x;
			i->player_pos_y = new_y;
			i->map[i->player_pos_y][i->player_pos_x] = 'P';
			update_movements(i);
			if(i->coins < 1)
				i->exit = mlx_xpm_file_to_image(i->mlx, "image/exits/exit2.xpm", &i->imgw, &i->imgh);
			draw_map(i);
		}
	}
}
