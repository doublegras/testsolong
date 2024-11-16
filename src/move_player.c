/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marcambuehl4@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:43:42 by maambuhl          #+#    #+#             */
/*   Updated: 2024/11/16 17:02:15 by maambuhl         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	make_move(t_game *game, int x, int y, int *i)
{
	static int	c;

	if (ft_strchr("0CE", game->map[y][x]))
	{
		if (game->map[y][x] == 'C')
		{
			game->map[y][x] = '0';
			c++;
		}
		if (game->map[y][x] == 'E')
		{
			if (c == game->total_coin)
				close_window(game);
			return (0);
		}
		mlx_put_image_to_window(game->mlx, game->win, game->img.grass,
			game->player_x * PIXEL_SIZE, game->player_y * PIXEL_SIZE);
		mlx_put_image_to_window(game->mlx, game->win, game->img.player,
			x * PIXEL_SIZE, y * PIXEL_SIZE);
		*i += 1;
		return (1);
	}
	return (0);
}

void	move_player(t_game *game, int key, int *i)
{
	if (key == 119)
	{
		if (make_move(game, game->player_x, game->player_y - 1, i))
			game->player_y--;
	}
	else if (key == 115)
	{
		if (make_move(game, game->player_x, game->player_y + 1, i))
			game->player_y++;
	}
	else if (key == 97)
	{
		if (make_move(game, game->player_x - 1, game->player_y, i))
			game->player_x--;
	}
	else if (key == 100)
	{
		if (make_move(game, game->player_x + 1, game->player_y, i))
			game->player_x++;
	}
}

int	handle_key(int keycode, t_game *game)
{
	static int	i;
	int			tmp;

	tmp = i;
	if (keycode == 65307)
		close_window(game);
	if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100)
	{
		move_player(game, keycode, &i);
		if (i > tmp)
			ft_printf("%d\n", i);
	}
	return (0);
}

int	display_map_helper(t_game *game, int x, int y, void *img)
{
	t_xvar		*mlx;
	t_win_list	*win;

	mlx = game->mlx;
	win = game->win;
	mlx_put_image_to_window(mlx, win, img, x * PXL, y * PXL);
	return (1);
}
