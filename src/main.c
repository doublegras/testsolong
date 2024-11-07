/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marcambuehl4@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:02:43 by maambuhl          #+#    #+#             */
/*   Updated: 2024/11/07 18:21:27 by maambuhl         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	exit(0);
}

void	err(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

int	count_line(int fd)
{
	int		i;
	char	*line;
	void	*ptr;

	line = get_next_line(fd);
	if (!line)
		err("Error while getting the line");
	i = 1;
	ptr = malloc(1000);
	if (!ptr)
		exit(9);
	free(ptr);
	while (1)
	{
		free(line);
		line = get_next_line(fd);
		if (!line || *line == '\n')
		{
			return (i);
		}
		i++;
	}
}

int	parse_map(char *file)
{
	int		fd;
	int		nb;

	fd = open(file, O_RDONLY);
	nb = count_line(fd);
	printf("nb line %d", nb);
	return (0);
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_window(game);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;
	t_imgx	img;
	int		img_w;
	int		img_h;

	if (ac != 2)
		err("You must provide one argument");
	parse_map(av[1]);
	game.mlx = mlx_init();
	if (!game.mlx)
		exit(1);
	game.win = mlx_new_window(game.mlx, 1920, 1080, "so_long");
	if (!game.win)
		exit(1);
	img.player = mlx_xpm_file_to_image(game.mlx, "mlx-linux/test/open24.xpm", &img_w, &img_h);
	if (!img.player)
		exit(1);
	game.img = &img;
	mlx_put_image_to_window(game.mlx, game.win, game.img->player, 1, 1);
	mlx_key_hook(game.win, handle_key, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
}
