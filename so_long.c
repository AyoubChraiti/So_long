/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:51:11 by achraiti          #+#    #+#             */
/*   Updated: 2024/01/01 10:40:52 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int			fd;
	t_Mapinfo	mapinfo;

	if (argc != 2 || !(is_ber_file(argv[1])))
		print_error("Error\nYou didn't provide a map /valid map extention\n");
	fd = open(argv[1], O_RDWR);
	if (map_checker(fd, &mapinfo))
	{
		show_window(&mapinfo);
	}
	else
	{
		print_error("Error\nMap is not valid");
	}
	close(fd);
}
