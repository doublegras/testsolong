/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marcambuehl4@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:57:10 by maambuhl          #+#    #+#             */
/*   Updated: 2024/11/27 14:02:14 by maambuhl         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_case(t_game *game, char c)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == c)
				i++;
			x++;
		}
		y++;
	}
	return (i);
}

void	check_file_extension(t_game *game)
{
	size_t	len;

	len = ft_strlen(game->map_file);
	if (len <= 4)
		err("Error\nMap file should look like this: <map name>.ber", NULL);
	len--;
	if (game->map_file[len] != 'r' || game->map_file[len - 1] != 'e'
		|| game->map_file[len - 2] != 'b' || game->map_file[len - 3] != '.')
		err("Error\nMap file should look like this: <map name>.ber", NULL);
}

void	count_coin(t_game *game)
{
	int	y;
	int	x;
	int	c;

	y = 0;
	c = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				c++;
			x++;
		}
		y++;
	}
	game->total_coin = c++;
}

void	set_images(t_game *game)
{
	int		img_w;
	int		img_h;

	img_w = PIXEL_SIZE;
	img_h = PIXEL_SIZE;
	game->img.player = mlx_xpm_file_to_image(game->mlx, P, &img_w, &img_h);
	if (game->img.player)
		game->img.is_player = 1;
	game->img.wall = mlx_xpm_file_to_image(game->mlx, W, &img_w, &img_h);
	if (game->img.wall)
		game->img.is_wall = 1;
	game->img.grass = mlx_xpm_file_to_image(game->mlx, O, &img_w, &img_h);
	if (game->img.grass)
		game->img.is_grass = 1;
	game->img.coin = mlx_xpm_file_to_image(game->mlx, C, &img_w, &img_h);
	if (game->img.coin)
		game->img.is_coin = 1;
	game->img.door = mlx_xpm_file_to_image(game->mlx, D, &img_w, &img_h);
	if (game->img.door)
		game->img.is_door = 1;
	game->img.is_set = 1;
	if (!game->img.player || !game->img.wall || !game->img.grass
		|| !game->img.coin || !game->img.door)
		close_window(game);
}

int	count_line(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		i++;
	return (i);
}
