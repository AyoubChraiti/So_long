/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:53:17 by achraiti          #+#    #+#             */
/*   Updated: 2023/12/20 15:00:01 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle(const char *str, va_list arg, int i)
{
	int	len;

	len = 0;
	if (str[i] == 'c')
		len += ft_printfputchar(va_arg(arg, int));
	else if (str[i] == 's')
		len += ft_printfputstr(va_arg(arg, char *));
	else if (str[i] == 'd' || str[i] == 'i')
		len += ft_printfputnbr(va_arg(arg, int));
	else if (str[i] == 'u')
		len += ft_unsigned(va_arg(arg, long));
	else if (str[i] == 'X')
		len += hexa(va_arg(arg, unsigned int), "0123456789ABCDEF");
	else if (str[i] == 'x')
		len += hexa(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (str[i] == 'p')
	{
		write(1, "0x", 2);
		len += hexa((uintmax_t)va_arg(arg, void *), "0123456789abcdef") + 2;
	}
	else if (str[i] == '%')
		len += ft_printfputchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	arg;

	i = 0;
	len = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += handle(str, arg, i);
		}
		else
			len += ft_printfputchar(str[i]);
		i++;
	}
	va_end(arg);
	return (len);
}
