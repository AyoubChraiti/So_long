/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 10:14:48 by achraiti          #+#    #+#             */
/*   Updated: 2024/02/18 16:14:46 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
void	load_images(t_info *i)
{
	i->wall = mlx_xpm_file_to_image(i->mlx, "image/walls.xpm", &i->imgw, &i->imgh);
	i->floor = mlx_xpm_file_to_image(i->mlx, "image/floor.xpm", &i->imgw, &i->imgh);
	i->colle = mlx_xpm_file_to_image(i->mlx, "image/coins/coin1.xpm", &i->imgw, &i->imgh);
	i->p = mlx_xpm_file_to_image(i->mlx, "image/player/chilling.xpm", &i->imgw, &i->imgh);
	i->exit = mlx_xpm_file_to_image(i->mlx, "image/exits/exit1.xpm", &i->imgw, &i->imgh);
}

void	draw_map(t_info *i)
{
	int	x;
	int	y;

	y = 0;
	i->y = 0;
	i->colle = mlx_xpm_file_to_image(i->mlx, "image/coins/coin1.xpm", &i->imgw, &i->imgh);
	while (i->map[y])
	{
		x = 0;
		i->x = 0;
		while (i->map[y][x])
		{
			handle_image(i, x, y);
			x++;
			i->x += 32;
		}
		i->y += 32;
		y++;
	}
}

void	handle_image(t_info *i, int x, int y)
{
	if (i->map[y][x] == '1')
		mlx_put_image_to_window(i->mlx, i->win, i->wall, i->x, i->y);
	else if (i->map[y][x] == '0')
		mlx_put_image_to_window(i->mlx, i->win, i->floor, i->x, i->y);
	else if (i->map[y][x] == 'C')
		mlx_put_image_to_window(i->mlx, i->win, i->colle, i->x, i->y);
	else if (i->map[y][x] == 'P')
	{
		mlx_put_image_to_window(i->mlx, i->win, i->p, i->x, i->y);
		i->player_pos_x = x;
		i->player_pos_y = y;
	}
	else if (i->map[y][x] == 'E')
		mlx_put_image_to_window(i->mlx, i->win, i->exit, i->x, i->y);
}

void	show_window(t_Mapinfo *mapinfo)
{
	t_info	i;

	i.map = mapinfo->map;
	i.rows = mapinfo->rows;
	i.cols = mapinfo->cols;
	i.coins = mapinfo->coin_count;
	i.imgw = 32;
	i.imgh = 32;
	i.can_exit = 0;
	i.mv = 0;
	i.mlx = mlx_init();
	i.win = mlx_new_window(i.mlx, (i.cols * 32), (i.rows * 32), "so_long");
	load_images(&i);
	draw_map(&i);
	mlx_key_hook(i.win, handle_keypress, &i);
	handle_close_window(&i);
	mlx_loop(i.mlx);
}
