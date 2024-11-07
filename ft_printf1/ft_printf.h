/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marcambuehl4@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:32:49 by maambuhl          #+#    #+#             */
/*   Updated: 2024/10/06 16:44:31 by maambuhl         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_printf(const char *s, ...);
int		ft_putnbr(int nb);
int		ft_uputnbr(unsigned int nb);
int		ft_printptr(void *ptr);
char	*ft_xitoa(unsigned int n);
char	*ft_xbitoa(unsigned int n);

#endif
