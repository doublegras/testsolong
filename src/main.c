/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:40:18 by maambuhl          #+#    #+#             */
/*   Updated: 2024/11/15 17:51:29 by maambuhl         ###   LAUSANNE.ch       */
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
	if (!game)
		exit(1);
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

void	err(char *str, t_game *game)
{
	ft_putstr_fd(str, 2);
	if (game)
		close_window(game);
	exit(1);
}

int	count_line_fd(int fd, t_game *game)
{
	int		i;
	char	*line;

	line = get_next_line(fd);
	if (!line)
		err("Error\nCan't get the line", game);
	i = 1;
	while (1)
	{
		free(line);
		line = get_next_line(fd);
		if (!line || *line == '\n')
		{
			if (i < 3)
				err("Error\nYour map should be a rectangle", NULL);
			return (i);
		}
		i++;
	}
		
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

void	parse_map(char *file, t_game *game)
{
	int		fd;
	int		nb;
	int		i;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		err("Error\nRead error", NULL);
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

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img.wall, x * PIXEL_SIZE, y * PIXEL_SIZE);
			if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->img.grass, x * PIXEL_SIZE, y * PIXEL_SIZE);
			if (game->map[y][x] == 'P')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->img.player, x * PIXEL_SIZE, y * PIXEL_SIZE);
				game->map[y][x] = '0';
			}
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img.coin, x * PIXEL_SIZE, y * PIXEL_SIZE);
			if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img.door, x * PIXEL_SIZE, y * PIXEL_SIZE);
			x++;
		}
		y++;
	}
	return (0);
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
