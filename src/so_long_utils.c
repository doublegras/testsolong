/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marcambuehl4@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:57:10 by maambuhl          #+#    #+#             */
/*   Updated: 2024/11/11 16:35:51 by maambuhl         ###   LAUSANNE.ch       */
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

int	count_line(t_game *game)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (game->map[y])
	{
		if (game->map[y][0] != '\n')
			i++;
		y++;
	}
	return (i);
}
