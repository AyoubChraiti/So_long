/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:20:36 by achraiti          #+#    #+#             */
/*   Updated: 2023/12/19 14:14:43 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_split(char **str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}

static size_t	word_count(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*str_dup(const char *s1, char c)
{
	char	*scpy;
	size_t	slen;
	size_t	i;

	slen = 0;
	while (s1[slen] && s1[slen] != c)
		slen++;
	scpy = (char *)malloc((slen + 1) * sizeof(char));
	if (scpy == NULL)
		return (0);
	i = 0;
	while (i < slen)
	{
		scpy[i] = s1[i];
		i++;
	}
	scpy[i] = '\0';
	return (scpy);
}

int	split_error(char **str)
{
	ft_free_split(str);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	count;

	count = word_count(s, c);
	str = (char **)malloc((count + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			str[count] = str_dup(s, c);
			if (str[count] == NULL && split_error(str))
				return (NULL);
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	str[count] = NULL;
	return (str);
}
// int main()
// {
// 	char **s = ft_split("xxpxxxpxxpxxxpxx", 'x');
// 	int i = 0;
// 	while(i < word_count("xxpxxxpxxpxxxpxx", 'x') + 2)
// 	{
// 		printf("%s\n", s[i++]);
// 	}
// }