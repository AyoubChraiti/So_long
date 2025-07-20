/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:56:49 by achraiti          #+#    #+#             */
/*   Updated: 2024/01/01 10:39:18 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
char	**read_and_join_map(int fd)
{
	char	*line;
	char	*map_content;
	char	*temp;
	char	**s;
	int		check;

	map_content = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		temp = ft_strjoin(map_content, line);
		map_content = temp;
	}
	if (!map_content)
		print_error("Error\nfile is empty");
	check = check_new_line(map_content);
	if (check == 0)
		return (NULL);
	s = ft_split(map_content, '\n');
	free(map_content);
	return (s);
}

int	check_new_line(char *map)
{
	int	row;

	row = 0;
	if (map[0] == '\n')
		return (0);
	while (map[row])
	{
		if ((map[row] == '\n' && map[row + 1] == '\n'))
			return (0);
		row++;
	}
	if (map[row] == '\0' && map[row - 1] == '\n')
		return (0);
	return (1);
}

int	is_ber_file(char *file)
{
	int	length;
	int	ch;

	length = ft_strlen(file);
	ch = ft_strncmp(&file[length - 4], ".ber", 4);
	if (length >= 4 && ch == 0)
		return (1);
	else
		return (0);
}

int	map_checker(int fd, t_Mapinfo *mapinfo)
{
	char	**c;

	c = read_and_join_map(fd);
	mapinfo->map = c;
	if (c && check_map_close(c) && check_if_rectangle(c)
		&& check_duplicate_exit_start(c) && check_car(c)
		&& valid_path(c, mapinfo))
		return (1);
	else
	{
		free_map(c, mapinfo->rows);
		return (0);
	}
}
