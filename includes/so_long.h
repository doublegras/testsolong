/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marcambuehl4@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:51:36 by maambuhl          #+#    #+#             */
/*   Updated: 2024/11/10 22:56:43 by maambuhl         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include "../ft_printf/ft_printf.h"
# include "../ft_printf/libft/libft.h"
# include <stdio.h>

# define PIXEL_SIZE 64

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

void	move_player(t_game *game, int key, int *i);
int		close_window(t_game *game);

#endif
