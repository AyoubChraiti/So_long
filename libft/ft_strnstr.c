/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:18:40 by achraiti          #+#    #+#             */
/*   Updated: 2023/11/11 15:29:12 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (substr[0] == '\0')
	{
		return ((char *)str);
	}
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] && str[i + j] == substr[j] && (i + j) < len)
		{
			j++;
			if (substr[j] == '\0')
			{
				return ((char *)&str[i]);
			}
		}
		i++;
	}
	return (0);
}
