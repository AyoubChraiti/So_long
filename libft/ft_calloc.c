/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:02:31 by achraiti          #+#    #+#             */
/*   Updated: 2023/11/11 12:22:00 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_elmnt, size_t size)
{
	size_t	total_bytes;
	void	*p;

	total_bytes = num_elmnt * size;
	if (num_elmnt && size && num_elmnt > (MAX_SIZE / size))
		return (NULL);
	p = (void *)malloc(total_bytes);
	if (!p)
	{
		return (NULL);
	}
	ft_bzero(p, total_bytes);
	return (p);
}
