/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 12:39:41 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/10 16:04:00 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "game_engine.h"

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_sky(t_game_data *game_data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < game_data->map.r[1] / 2)
	{
		x = 0;
		while (x < game_data->map.r[0])
		{
			my_mlx_pixel_put(&game_data->img_data, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
}

void	draw_land(t_game_data *game_data)
{
	size_t	x;
	size_t	y;

	y = game_data->map.r[1] / 2;
	while (y < game_data->map.r[1])
	{
		x = 0;
		while (x < game_data->map.r[0])
		{
			my_mlx_pixel_put(&game_data->img_data, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
}
