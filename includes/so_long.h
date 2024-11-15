/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marcambuehl4@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:51:36 by maambuhl          #+#    #+#             */
/*   Updated: 2024/11/15 17:39:05 by maambuhl         ###   LAUSANNE.ch       */
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
	int		is_player;
	void	*wall;
	int		is_wall;
	void	*grass;
	int		is_grass;
	void	*coin;
	int		is_coin;
	void	*door;
	int		is_door;
	int		is_set;
}	t_imgx;

typedef struct s_game
{
	t_xvar		*mlx;
	t_win_list	*win;
	t_imgx		img;
	char		**map;
	int			player_x;
	int			player_y;
	char		*map_file;
}	t_game;

void	move_player(t_game *game, int key, int *i);
int		close_window(t_game *game);
void	map_check(t_game *game);
void	err(char *str, t_game *game);
int		count_line(t_game *game);
int		check_case(t_game *game, char c);
int		count_coin(t_game *game);
void	check_file_extension(t_game *game);
void	check_path(t_game *game);
void	multi_free(char **map);
void	set_images(t_game *game);

#endif
