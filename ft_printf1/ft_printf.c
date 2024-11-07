/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marcambuehl4@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:12:28 by maambuhl          #+#    #+#             */
/*   Updated: 2024/10/06 17:31:41 by maambuhl         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check(char format, va_list arg)
{
	int	c;

	c = 0;
	if (format == 's')
		c = ft_putstr(va_arg(arg, char *));
	else if (format == '%')
		c = ft_putchar('%');
	else if (format == 'd' || format == 'i')
		c = ft_putstr(ft_itoa(va_arg(arg, int)));
	else if (format == 'u')
		c = ft_uputnbr(va_arg(arg, int));
	else if (format == 'x')
		c = ft_putstr(ft_xitoa(va_arg(arg, int)));
	else if (format == 'X')
		c = ft_putstr(ft_xbitoa(va_arg(arg, int)));
	else if (format == 'p')
		c = ft_printptr(va_arg(arg, void *));
	return (c);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		c;
	va_list	args;

	i = 0;
	c = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && ft_isprint(s[i + 1]))
		{
			c += ft_check(s[i + 1], args);
			i += 2;
		}
		else
		{
			ft_putchar(s[i++]);
			c++;
		}
	}
	va_end(args);
	return (c);
}
