/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 12:39:41 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/17 19:58:07 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "game_engine.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_sky(t_game *game)
{
	size_t	x;
	size_t	y;
	size_t	color;

	y = 0;
	color = game->map.c;
	while (y < game->map.r[1] / 2)
	{
		x = 0;
		while (x < game->map.r[0])
		{
			my_mlx_pixel_put(&game->img, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_land(t_game *game)
{
	size_t	x;
	size_t	y;
	size_t	color;

	y = game->map.r[1] / 2;
	color = game->map.f;
	while (y < game->map.r[1])
	{
		x = 0;
		while (x < game->map.r[0])
		{
			my_mlx_pixel_put(&game->img, x, y, color);
			x++;
		}
		y++;
	}
}
