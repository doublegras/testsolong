/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marcambuehl4@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:51:36 by maambuhl          #+#    #+#             */
/*   Updated: 2024/11/07 17:46:28 by maambuhl         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx-linux/mlx.h"
# include "../mlx-linux/mlx_int.h"
# include "../ft_printf/ft_printf.h"
# include "../ft_printf/libft/libft.h"
# include <stdio.h>

# define PIXEL_SIZE 50

typedef struct s_imgx
{
	void	*player;
}	t_imgx;

typedef struct s_game
{
	t_xvar		*mlx;
	t_win_list	*win;
	t_imgx		*img;
}	t_game;

#endif
