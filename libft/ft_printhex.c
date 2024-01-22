/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:01:23 by achraiti          #+#    #+#             */
/*   Updated: 2023/12/20 22:35:56 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	strrev(char *s, int len)
{
	int		i;
	char	tmp;

	i = 0;
	while (i < len / 2)
	{
		tmp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = tmp;
		i++;
	}
}

int	hexa(uintmax_t nb, char *hexChars)
{
	char	digits[32];
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (nb >= 16)
	{
		digits[i] = hexChars[nb % 16];
		nb = nb / 16;
		i++;
	}
	digits[i++] = hexChars[nb];
	digits[i] = '\0';
	strrev(digits, i);
	write(1, digits, i);
	return (i);
}

// static void strrev(char *s, int len)
// {
//     int start = 0;
//     int end = len - 1;

//     while (start < end)
//     {
//         char tmp = s[start];
//         s[start] = s[end];
//         s[end] = tmp;

//         start++;
//         end--;
//     }
// }

// int main()
// {
//     char str[] = "Hello, World!";
//     int len = strlen(str);

//     strrev(str, len);

//     printf("Reversed string: %s\n", str);

//     return 0;
// }