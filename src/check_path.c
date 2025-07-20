/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:30:31 by achraiti          #+#    #+#             */
/*   Updated: 2023/12/29 22:47:19 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

char	**copy_map(char **original, int rows, int cols)
{
	char	**copy;
	int		i;

	copy = malloc(rows * sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		copy[i] = malloc(cols + 1);
		if (!copy[i])
		{
			free_map(copy, i);
			return (NULL);
		}
		ft_strlcpy(copy[i], original[i], cols + 1);
		i++;
	}
	return (copy);
}

void	find_player_position(t_Mapinfo *mapinfo)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mapinfo->x = -1;
	while (i < mapinfo->rows)
	{
		j = 0;
		while (j < mapinfo->cols)
		{
			if (mapinfo->map[i][j] == 'P')
			{
				mapinfo->x = i;
				mapinfo->y = j;
			}
			if (mapinfo->map[i][j] == 'C')
				mapinfo->coins++;
			j++;
		}
		i++;
	}
	mapinfo->coin_count = mapinfo->coins;
}

void	flood_fill(t_Mapinfo *mapinfo, int x, int y)
{
	if (x < 0 || x >= mapinfo->rows || y < 0 || y >= mapinfo->cols
		|| mapinfo->map2[x][y] == '1' || mapinfo->map2[x][y] == '-')
		return ;
	if (mapinfo->map2[x][y] == 'E')
		mapinfo->exitfound = 1;
	if (mapinfo->map2[x][y] == 'C')
	{
		mapinfo->map2[x][y] = '-';
		mapinfo->coins--;
	}
	if (mapinfo->map2[x][y] != 'E')
		mapinfo->map2[x][y] = '-';
	flood_fill(mapinfo, x - 1, y);
	flood_fill(mapinfo, x + 1, y);
	flood_fill(mapinfo, x, y - 1);
	flood_fill(mapinfo, x, y + 1);
}

int	valid_path(char **map, t_Mapinfo *mapinfo)
{
	int			i;

	i = 0;
	if (!map)
		return (0);
	while (map[i] != NULL)
		i++;
	mapinfo->rows = i;
	mapinfo->cols = ft_strlen(map[0]);
	mapinfo->valid = 1;
	mapinfo->exitfound = 0;
	mapinfo->map2 = copy_map(map, mapinfo->rows, mapinfo->cols);
	mapinfo->coins = 0;
	find_player_position(mapinfo);
	if (mapinfo->x == -1)
	{
		free_map(mapinfo->map2, mapinfo->rows);
		return (0);
	}
	flood_fill(mapinfo, mapinfo->x, mapinfo->y);
	if (mapinfo->exitfound == 0 || mapinfo->coins != 0)
		mapinfo->valid = 0;
	free_map(mapinfo->map2, mapinfo->rows);
	return (mapinfo->valid);
}
