/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marcambuehl4@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 12:06:59 by maambuhl          #+#    #+#             */
/*   Updated: 2024/10/06 17:30:59 by maambuhl         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(uintptr_t n)
{
	int	c;

	c = 1;
	while (n >= 16)
	{
		n = n / 16;
		c++;
	}
	return (c);
}

static int	ft_pitoa(uintptr_t n)
{
	char	*str;
	int		c;

	c = ft_count(n) + 2;
	str = malloc(sizeof(char) * (c + 1));
	if (!str)
		return (0);
	str[c] = 0;
	while (--c >= 0)
	{
		str[c] = "0123456789abcdef"[n % 16];
		n = n / 16;
	}
	str[0] = '0';
	str[1] = 'x';
	ft_putstr(str);
	return ((int)ft_strlen(str));
}

int	ft_printptr(void *ptr)
{
	int	len;

	if (!ptr)
	{
		ft_putstr("(nil)");
		return (5);
	}
	len = ft_pitoa((uintptr_t)ptr);
	return (len);
}
