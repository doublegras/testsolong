/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marcambuehl4@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:54:17 by maambuhl          #+#    #+#             */
/*   Updated: 2024/11/14 20:33:36 by maambuhl         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

extern int	g_nb_coin;
int			g_coins = 0;
int			g_exit = 0;

static	int	check_wall(char c)
{
	if (c != '1' && c != '\n' && c != 0 && c != 'X')
		return (1);
	return (0);
}

static void	fill(t_game *game, int y, int x)
{
	if (game->map[y][x] == 'C')
		g_coins++;
	if (game->map[y][x] == 'E')
		g_exit++;
	if (game->map[y][x] == '0')
		game->map[y][x] = 'X';
	if (check_wall(game->map[y][x + 1]))
		fill(game, y, x + 1);
	if (check_wall(game->map[y - 1][x]))
		fill(game, y - 1, x);
	if (check_wall(game->map[y][x - 1]))
		fill(game, y, x - 1);
	if (check_wall(game->map[y + 1][x]))
		fill(game, y + 1, x);
}

void	check_path(t_game *game)
{
	fill(game, game->player_y, game->player_x);
	if (g_coins != g_nb_coin || g_exit != 1)
		printf("exit = %d\ntotal coin = %d\ncoins = %d\n", g_exit, g_nb_coin, g_exit);
		/*err("Error\nExit and coins should be accessible by the player", game);*/
}
