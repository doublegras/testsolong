/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marcambuehl4@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:51:36 by maambuhl          #+#    #+#             */
/*   Updated: 2024/11/16 16:57:50 by maambuhl         ###   LAUSANNE.ch       */
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
# define PXL 64
# define P "img/cadillac.xpm"
# define W "img/wall.xpm"
# define O "img/grass.xpm"
# define C "img/coin.xpm"
# define D "img/door.xpm"

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
	int			total_coin;
	int			path_coin;
	int			path_exit;
}	t_game;

void	move_player(t_game *game, int key, int *i);
int		close_window(t_game *game);
void	map_check(t_game *game);
void	err(char *str, t_game *game);
int		count_line(t_game *game);
int		check_case(t_game *game, char c);
void	count_coin(t_game *game);
void	check_file_extension(t_game *game);
void	check_path(t_game *game);
void	multi_free(char **map);
void	set_images(t_game *game);
int		open_map(t_game *game);
int		count_line_fd(int fd, t_game *game);
void	get_player_pos(t_game *game);
int		handle_key(int keycode, t_game *game);
int		display_map_helper(t_game *game, int x, int y, void *img);

#endif
