/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:30:21 by achraiti          #+#    #+#             */
/*   Updated: 2023/11/03 10:32:35 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;
	char	x[11];
	int		i;

	i = 0;
	nbr = n;
	if (fd < 0)
		return ;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = nbr * -1;
	}
	while (nbr >= 10)
	{
		x[i] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i++;
	}
	x[i] = (nbr % 10) + '0';
	while (i >= 0)
	{
		ft_putchar_fd(x[i], fd);
		i--;
	}
}
