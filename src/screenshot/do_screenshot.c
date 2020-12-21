/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_screenshot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 13:23:27 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/21 20:04:38 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include "game_engine.h"

static int		create_clean_file(const char *name)
{
	int		fd;

	fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (fd < 0)
		write(2, "ERROR: can't create file\n", 25);
	return (fd);
}

static void		write_img(int fd, t_game *game)
{
	int32_t		y;
	int32_t		x;
	int			color;

	y = game->map.r[1] - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < game->map.r[0])
		{
			color = *(int*)(game->img.addr + (y * game->img.line_lenght +
						x * (game->img.bits_per_pixel / 8)));
			write(fd, &color, 4);
			x++;
		}
		y--;
	}
}

void			do_screenshot(t_game *game)
{
	int		fd;
	void	*bitmap;

	init_game_space(game);
	raycasting_render(game);
	fd = create_clean_file("screenshot.bmp");
	if (fd < 0)
		exit(-1);
	bitmap = init_bitmap54(game);
	write(fd, bitmap, 54);
	write_img(fd, game);
	game->map.clear(&game->map);
	close(fd);
}
