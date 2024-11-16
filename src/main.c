/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:40:18 by maambuhl          #+#    #+#             */
/*   Updated: 2024/11/16 17:01:47 by maambuhl         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	destroy_images(t_game *game)
{
	if (game->img.is_player)
		mlx_destroy_image(game->mlx, game->img.player);
	if (game->img.is_wall)
		mlx_destroy_image(game->mlx, game->img.wall);
	if (game->img.is_grass)
		mlx_destroy_image(game->mlx, game->img.grass);
	if (game->img.is_coin)
		mlx_destroy_image(game->mlx, game->img.coin);
	if (game->img.is_door)
		mlx_destroy_image(game->mlx, game->img.door);
}

int	close_window(t_game *game)
{
	multi_free(game->map);
	if (game->img.is_set)
		destroy_images(game);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
}

void	parse_map(char *file, t_game *game)
{
	int		fd;
	int		nb;
	int		i;
	char	**map;

	fd = open_map(game);
	nb = count_line_fd(fd, game);
	close(fd);
	map = malloc(sizeof(char *) * (nb + 1));
	if (!map)
		err("Error\nMap malloc error", NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		err("Error\nRead error", NULL);
	i = 0;
	while (i < nb)
		map[i++] = get_next_line(fd);
	map[i] = NULL;
	close(fd);
	game->map = map;
	get_player_pos(game);
}

int	display_map(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '1')
				display_map_helper(game, x, y, game->img.wall);
			if (game->map[y][x] == '0')
				display_map_helper(game, x, y, game->img.grass);
			if (game->map[y][x] == 'P')
			{
				display_map_helper(game, x, y, game->img.player);
				game->map[y][x] = '0';
			}
			if (game->map[y][x] == 'C')
				display_map_helper(game, x, y, game->img.coin);
			if (game->map[y][x] == 'E')
				display_map_helper(game, x, y, game->img.door);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		err("Error\nYou must provide one argument", NULL);
	game.map_file = av[1];
	game.img.is_set = 0;
	game.mlx = 0;
	game.win = 0;
	check_file_extension(&game);
	parse_map(game.map_file, &game);
	count_coin(&game);
	map_check(&game);
	check_path(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
		err("Error\nCannot connect to X11", &game);
	game.win = mlx_new_window(game.mlx, 3560, 2000, "so_long");
	if (!game.win)
		err("Error\nCannot create window", &game);
	set_images(&game);
	mlx_expose_hook(game.win, display_map, &game);
	mlx_key_hook(game.win, handle_key, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
}
