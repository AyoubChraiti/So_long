/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfputnbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:53:25 by achraiti          #+#    #+#             */
/*   Updated: 2023/12/20 14:58:50 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printfputnbr(int n)
{
	long	nbr;
	char	x[11];
	int		i;

	i = 0;
	nbr = n;
	if (nbr < 0)
	{
		ft_printfputchar('-');
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
		ft_printfputchar(x[i]);
		i--;
	}
	return (ft_len(n));
}
