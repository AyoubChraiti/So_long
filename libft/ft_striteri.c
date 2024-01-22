/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:55:08 by achraiti          #+#    #+#             */
/*   Updated: 2023/11/11 14:54:22 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// void ft_fon(unsigned int i, char *s)
// {
// 	while(s[i])
// 	{
// 		s[i] = ft_toupper(s[i]);
// 		i++;
// 	}
// }
//
// int main()
// {
// 	char x[] = "ayoub";
// 	ft_striteri(x, ft_fon);
// 	printf("%s\n", x);
// }