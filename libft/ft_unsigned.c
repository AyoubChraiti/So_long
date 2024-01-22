/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:09:45 by achraiti          #+#    #+#             */
/*   Updated: 2023/12/20 15:00:12 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_unsigned(unsigned int n)
{
	long			nbr;
	char			x[12];
	int				i;

	i = 0;
	nbr = n;
	while (nbr >= 10)
	{
		x[i] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i++;
	}
	x[i] = (nbr % 10) + '0';
	while (i >= 0)
	{
		ft_printfputchar(x[i]);
		i--;
	}
	return (ft_len(n));
}
