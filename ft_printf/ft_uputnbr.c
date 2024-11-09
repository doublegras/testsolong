/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uputnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marcambuehl4@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 11:56:10 by maambuhl          #+#    #+#             */
/*   Updated: 2024/10/06 11:58:18 by maambuhl         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uputnbr(unsigned int nb)
{
	char	c;
	int		len;

	len = 1;
	if (nb >= 10)
	{
		ft_uputnbr(nb / 10);
		len++;
	}
	c = (nb % 10) + '0';
	ft_putchar(c);
	return (len);
}
