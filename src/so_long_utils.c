/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marcambuehl4@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:57:10 by maambuhl          #+#    #+#             */
/*   Updated: 2024/11/12 16:24:13 by maambuhl         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	nb_coin = 0;

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
	if (len < 4)
		err("Map file should look like this: <map name>.ber", NULL);
	len--;
	if (game->map_file[len] != 'r' || game->map_file[len - 1] != 'e'
	|| game->map_file[len - 2] != 'b' || game->map_file[len - 3] != '.')
		err("Map file should look like this: <map name>.ber", NULL);
}

int	count_coin(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				nb_coin++;
			x++;
		}
		y++;
	}
	return (nb_coin);
}

int	count_line(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		i++;
	return (i);
}
