/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:55:38 by achraiti          #+#    #+#             */
/*   Updated: 2023/12/23 15:10:30 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*m;

	i = 0;
	j = 0;
	if (!s1 && s2)
		return ((char *)s2);
	else if (s1 && !s2)
		return ((char *)s1);
	m = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!m)
		return (0);
	while (s1[i])
	{
		m[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		m[i + j] = s2[j];
		j++;
	}
	m[i + j] = '\0';
	return (m);
}
