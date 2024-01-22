/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:17:25 by achraiti          #+#    #+#             */
/*   Updated: 2023/11/06 18:43:01 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static int	first_position(char const *s, char const *set)
{
	int	i;

	i = 0;
	while (s[i] && check_set(s[i], set))
		i++;
	return (i);
}

static int	last_position(char const *s, char const *set)
{
	int	i;

	i = ft_strlen(s) - 1;
	while (i >= 0 && check_set(s[i], set))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*m;
	int		i;
	int		len;
	int		start;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	len = last_position(s1, set) - first_position(s1, set) + 1;
	start = first_position(s1, set);
	if (len <= 0)
	{
		m = (char *)malloc(1);
		if (!m)
			return (NULL);
		m[0] = '\0';
		return (m);
	}
	m = (char *)malloc(len + 1);
	if (!m)
		return (NULL);
	while (i < len)
		m[i++] = s1[start++];
	m[i] = '\0';
	return (m);
}
