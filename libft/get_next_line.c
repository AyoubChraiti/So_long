/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:06:13 by achraiti          #+#    #+#             */
/*   Updated: 2023/12/31 11:58:16 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*func(int fd, char *buff, char *b)
{
	int		linee;
	char	*tmp;

	linee = 1;
	while (linee != 0)
	{
		linee = read(fd, buff, BUFFER_SIZE);
		if (linee == -1)
			return (0);
		else if (linee == 0)
			break ;
		buff[linee] = '\0';
		if (!b)
			b = ft_strdup("");
		tmp = b;
		b = ft_strjoin(tmp, buff);
		free(tmp);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (b);
}

static char	*last_chars(char *line)
{
	size_t	i;
	char	*m;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
	{
		return (0);
	}
	m = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*m == '\0')
	{
		free(m);
		m = NULL;
	}
	line[i + 1] = '\0';
	return (m);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buff;
	static char	*b;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (0);
	}
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	line = func(fd, buff, b);
	free(buff);
	if (!line)
		return (NULL);
	b = last_chars(line);
	return (line);
}
