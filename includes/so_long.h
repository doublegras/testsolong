/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marcambuehl4@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:51:36 by maambuhl          #+#    #+#             */
/*   Updated: 2024/11/09 18:42:24 by SET YOUR USER    ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include "../ft_printf/ft_printf.h"
# include "../ft_printf/libft/libft.h"
# include <stdio.h>

# define PIXEL_SIZE 50

typedef struct s_imgx
{
	void	*player;
	void	*wall;
	void	*grass;
	void	*coin;
	void	*door;
}	t_imgx;

typedef struct s_game
{
	t_xvar		*mlx;
	t_win_list	*win;
	t_imgx		*img;
	char		**map;
	int			player_x;
	int			player_y;
}	t_game;

#endif
