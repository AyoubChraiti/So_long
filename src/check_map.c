/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:51:38 by achraiti          #+#    #+#             */
/*   Updated: 2024/01/01 12:05:50 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	check_if_rectangle(char **map)
{
	size_t	x;
	size_t	y;
	size_t	len;

	x = 0;
	y = 0;
	if (!map)
		return (0);
	if (map != NULL && map[y] != NULL)
	{
		x = ft_strlen(map[y]);
		y++;
	}
	while (map[y] != NULL)
	{
		len = ft_strlen(map[y]);
		if (len != x)
			return (0);
		y++;
	}
	return (1);
}

int	check_duplicate_exit_start(char **map)
{
	int	exit;
	int	start;
	int	cole;

	exit = 0;
	start = 0;
	cole = 0;
	if (!map)
		return (0);
	if (!handle(map, exit, start, cole))
		return (0);
	return (1);
}

int	handle(char **map, int exit, int start, int cole)
{
	int	j;

	while (*map != NULL)
	{
		j = 0;
		while ((*map)[j] != '\0')
		{
			if ((*map)[j] == 'E')
				exit++;
			else if ((*map)[j] == 'P')
				start++;
			else if ((*map)[j] == 'C')
				cole++;
			j++;
		}
		map++;
	}
	if (exit > 1 || start > 1 || cole < 1
		|| exit == 0 || start == 0 || cole == 0)
		return (0);
	return (1);
}

int	check_map_close(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(map[0]);
	if (!map)
		return (0);
	while (map[0][i] && map[0][i] == '1')
		i++;
	if (i != len)
		return (0);
	i = 0;
	while (map[i] != NULL)
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (map[i - 1][j] && map[i - 1][j] == '1')
		j++;
	if (j != len)
		return (0);
	return (1);
}

int	check_car(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!map)
		return (0);
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C' &&
				map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != '\n')
			{
				print_error("char not found");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
