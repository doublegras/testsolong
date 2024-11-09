/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xbitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marcambuehl4@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 12:02:30 by maambuhl          #+#    #+#             */
/*   Updated: 2024/10/06 16:57:03 by maambuhl         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(unsigned int n)
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

char	*ft_xbitoa(unsigned int n)
{
	char	*str;
	int		c;

	c = ft_count(n);
	str = malloc(sizeof(char) * (c + 1));
	if (!str)
		return (0);
	str[c] = 0;
	while (--c >= 0)
	{
		str[c] = "0123456789ABCDEF"[n % 16];
		n = n / 16;
	}
	return (str);
}
