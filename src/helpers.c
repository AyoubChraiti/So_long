/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 22:44:07 by achraiti          #+#    #+#             */
/*   Updated: 2024/01/01 10:39:01 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	close_window(t_info *i)
{
	exit_game(i, "Window Closed");
	return (0);
}

int	handle_close_window(t_info *i)
{
	mlx_hook(i->win, 17, 0, close_window, i);
	return (0);
}

void	print_error(char *error)
{
	ft_printf("%s\n", error);
	exit(0);
}

void	free_map(char **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
