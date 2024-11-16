/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marcambuehl4@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:54:17 by maambuhl          #+#    #+#             */
/*   Updated: 2024/11/16 15:07:22 by maambuhl         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int			g_coins = 0;
int			g_exit = 0;

static	int	check_wall(char c)
{
	if (c != '1' && c != '\n' && c != 0 && c != 'X')
		return (1);
	return (0);
}

static void	fill(char **map, int y, int x)
{
	if (map[y][x] == 'C')
		g_coins++;
	if (map[y][x] == 'E')
		g_exit++;
	map[y][x] = 'X';
	if (check_wall(map[y][x + 1]))
		fill(map, y, x + 1);
	if (check_wall(map[y - 1][x]))
		fill(map, y - 1, x);
	if (check_wall(map[y][x - 1]))
		fill(map, y, x - 1);
	if (check_wall(map[y + 1][x]))
		fill(map, y + 1, x);
}

void	multi_free(char **map)
{
	int	y;

	if (map)
	{
		y = 0;
		while (map[y])
			free(map[y++]);
		free(map);
	}
}

void	check_path(t_game *game)
{
	char	**map;
	int		nb_line;
	int		y;

	nb_line = count_line(game) + 1;
	map = malloc(nb_line * sizeof(char *));
	if (!map)
		err("Error\nMalloc error", game);
	y = 0;
	while (game->map[y])
	{
		map[y] = ft_strdup(game->map[y]);
		if (!map[y])
		{
			multi_free(map);
			err("Error\nft_strdup retuned NULL", game);
		}
		y++;
	}
	map[y] = 0;
	fill(map, game->player_y, game->player_x);
	multi_free(map);
	if (g_coins != game->total_coin || g_exit != 1)
		err("Error\nExit and coins should be accessible by the player", game);
}
