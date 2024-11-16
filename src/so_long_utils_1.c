/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marcambuehl4@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:23:13 by maambuhl          #+#    #+#             */
/*   Updated: 2024/11/16 16:41:55 by maambuhl         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	open_map(t_game *game)
{
	int		fd;

	fd = open(game->map_file, O_RDONLY);
	if (fd < 0)
		err("Error\nRead error", game);
	return (fd);
}

static void	ft_close(int fd, char *line)
{
	close(fd);
	free(line);
}

int	count_line_fd(int fd, t_game *game)
{
	int		i;
	char	*line;

	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		err("Error\nCan't get the line", game);
	}
	i = 1;
	while (1)
	{
		free(line);
		line = get_next_line(fd);
		if (!line || *line == '\n')
		{
			if (i < 3)
			{
				ft_close(fd, line);
				err("Error\nYour map should be a rectangle", NULL);
			}
			return (i);
		}
		i++;
	}
}

void	err(char *str, t_game *game)
{
	ft_putstr_fd(str, 2);
	if (game)
		close_window(game);
	exit(1);
}

void	get_player_pos(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
