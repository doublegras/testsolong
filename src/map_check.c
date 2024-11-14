/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: SET YOUR USER UP <SET YOUR EMAIL UP>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:40:56 by SET YOUR USER     #+#    #+#             */
/*   Updated: 2024/11/14 19:05:59 by maambuhl         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/so_long.h"

static int	check_up_down(t_game *game, int y)
{
	int	x;

	x = 0;
	while (game->map[y][x] != 0 && game->map[y][x] != '\n')
	{
		if (game->map[y][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

static int	check_side(t_game *game, int x)
{
	int	y;

	y = 0;
	while (game->map[y])
	{
		if (game->map[y][x] != '1')
			return (0);
		y++;
	}
	return (1);
}

static int	check_square(t_game *game)
{
	int		y;
	size_t	len;
	size_t	cmp;

	y = 0;
	if (count_line(game) < 2)
		return (0);
	len = ft_strlen(game->map[y++]);
	len--;
	while (game->map[y])
	{
		cmp = ft_strlen(game->map[y]);
		if (game->map[y][cmp - 1] == '\n')
			cmp--;
		if (len != cmp && len > 1)
			return (0);
		y++;
	}
	return (1);
}

static int	check_all_cases(t_game *game)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			c = game->map[y][x];
			if (c != 'P' && c != 'E' && c != '1' && c != '0' && c != '\n' && c != 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	map_check(t_game *game)
{
	if (!check_square(game))
		err("Error\nProvide a rectangle map", game);
	if (!check_all_cases(game))
		err("Error\nYour map should contains only characters 'P', 'E', '0', '1' and 'C'", game);
	if (!check_up_down(game, 0) || !check_up_down(game, count_line(game) - 1)
	|| !check_side(game, 0) || !check_side(game, ft_strlen(game->map[0]) - 2))
		err("Error\nYour map should be surrounded by wall", game);
	if (check_case(game, 'P') != 1 || check_case(game, 'E') != 1
		|| check_case(game, 'C') < 1)
		err("Error\nYour map should contains 1 player, 1 exit and at least 1 coin", game);
}
