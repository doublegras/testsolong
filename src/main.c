/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:40:18 by maambuhl          #+#    #+#             */
/*   Updated: 2024/11/10 21:22:15 by maambuhl         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	destroy_images(t_game *game)
{
	if (game->img)
		mlx_destroy_image(game->mlx, game->img->player);
}

int	close_window(t_game *game)
{
	destroy_images(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

void	err(char *str, t_game *game)
{
	perror(str);
	if (game)
		close_window(game);
	exit(1);
}

int	count_line(int fd, t_game *game)
{
	int		i;
	char	*line;

	line = get_next_line(fd);
	if (!line)
		err("Error while getting the line", game);
	i = 1;
	while (1)
	{
		free(line);
		line = get_next_line(fd);
		if (!line || *line == '\n')
			return (i);
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
		err("Read error", game);
	nb = count_line(fd, game);
	close(fd);
	map = malloc(sizeof(char *) * (nb + 1));
	if (!map)
		err("Map malloc error", game);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		err("Read error", game);
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
				mlx_put_image_to_window(game->mlx, game->win, game->img->wall, x * PIXEL_SIZE, y * PIXEL_SIZE);
			if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->img->grass, x * PIXEL_SIZE, y * PIXEL_SIZE);
			if (game->map[y][x] == 'P')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->img->player, x * PIXEL_SIZE, y * PIXEL_SIZE);
				game->map[y][x] = '0';
			}
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img->coin, x * PIXEL_SIZE, y * PIXEL_SIZE);
			if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img->door, x * PIXEL_SIZE, y * PIXEL_SIZE);
			x++;
		}
		y++;
	}
	return (0);
}

void	move_player(t_game *game, int key)
{
	// s = 115 a = 97 d = 100
	if (key == 119 && game->map[game->player_y - 1][game->player_x] == '0')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img->grass, game->player_x * PIXEL_SIZE, game->player_y * PIXEL_SIZE);
		mlx_put_image_to_window(game->mlx, game->win, game->img->player, game->player_x * PIXEL_SIZE, --game->player_y * PIXEL_SIZE);
	}
	else if (key == 115 && game->map[game->player_y + 1][game->player_x] == '0')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img->grass, game->player_x * PIXEL_SIZE, game->player_y * PIXEL_SIZE);
		mlx_put_image_to_window(game->mlx, game->win, game->img->player, game->player_x * PIXEL_SIZE, ++game->player_y * PIXEL_SIZE);
	}
	else if (key == 97 && game->map[game->player_y][game->player_x - 1] == '0')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img->grass, game->player_x * PIXEL_SIZE, game->player_y * PIXEL_SIZE);
		mlx_put_image_to_window(game->mlx, game->win, game->img->player, --game->player_x * PIXEL_SIZE, game->player_y * PIXEL_SIZE);
	}
	else if (key == 100 && game->map[game->player_y][game->player_x + 1] == '0')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img->grass, game->player_x * PIXEL_SIZE, game->player_y * PIXEL_SIZE);
		mlx_put_image_to_window(game->mlx, game->win, game->img->player, ++game->player_x * PIXEL_SIZE, game->player_y * PIXEL_SIZE);
	}
}

int	handle_key(int keycode, t_game *game)
{
	static int	i;

	if (keycode == 65307)
		close_window(game);
	if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100)
	{
		move_player(game, keycode);
		ft_printf("%d\n", ++i);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;
	t_imgx	img;
	int		img_w;
	int		img_h;

	if (ac != 2)
		err("You must provide one argument", NULL);
	game.mlx = mlx_init();
	if (!game.mlx)
		exit(1);
	game.win = mlx_new_window(game.mlx, 1920, 1080, "so_long");
	if (!game.win)
		exit(1);
	img.player = mlx_xpm_file_to_image(game.mlx, "img/cadillac.xpm", &img_w, &img_h);
	img.wall = mlx_xpm_file_to_image(game.mlx, "img/wall.xpm", &img_w, &img_h);
	img.grass = mlx_xpm_file_to_image(game.mlx, "img/grass.xpm", &img_w, &img_h);
	img.coin = mlx_xpm_file_to_image(game.mlx, "img/coin.xpm", &img_w, &img_h);
	img.door = mlx_xpm_file_to_image(game.mlx, "img/door.xpm", &img_w, &img_h);
	if (!img.player)
		exit(1);
	game.img = &img;
	parse_map(av[1], &game);
	mlx_expose_hook(game.win, display_map, &game);
	mlx_key_hook(game.win, handle_key, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
}
