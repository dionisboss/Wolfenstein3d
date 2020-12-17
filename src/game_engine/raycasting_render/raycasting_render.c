/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_render.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:49:20 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/17 16:51:42 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "new_map.h"
#include "game_engine.h"
#include "mlx.h"
#include <stdio.h>

int		raycasting_render(t_game *game_data)
{
	t_mlx_data			*mlx;
	t_ray				*ray;
	double				z_buff[game_data->map.r[0]];
	size_t				x;

	player_move(game_data);
	draw_sky(game_data);
	draw_land(game_data);
	mlx = &game_data->mlx_data;
	ray = &game_data->ray;
	x = 0;
	while (x < game_data->map.r[0])
	{
		init_ray(game_data, x);
		calculate_draw_start_end(game_data);
		draw_textures(game_data, x);
		z_buff[x] = ray->perp_wall_dist;
		x++;
	}
	render_sprites(game_data, z_buff);
	mlx_put_image_to_window(mlx->mlx, mlx->win, game_data->img_data.img, 0, 0);
	return (0);
}
