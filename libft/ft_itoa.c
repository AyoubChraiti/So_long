/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:59:40 by achraiti          #+#    #+#             */
/*   Updated: 2023/11/09 11:34:03 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_of_n(int n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		return (1);
	}
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*m;

	if (n == MIN_INT)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = len_of_n(n);
	m = (char *)malloc(sizeof(char) * (len + 1));
	if (!m)
		return (0);
	if (n < 0)
	{
		n = -n;
		m[0] = '-';
	}
	m[len] = '\0';
	len--;
	while (n > 0)
	{
		m[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (m);
}
