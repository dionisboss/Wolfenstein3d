/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_render.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:49:20 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/14 12:48:52 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "new_map.h"
#include "game_engine.h"
#include "mlx.h"

int		raycasting_render(t_game_data *game_data)
{
	t_ray				*ray;
	static size_t		i;

	draw_sky(game_data);
	draw_land(game_data);

	ray = &game_data->ray;

	player_move(game_data);

	i = 0;
	while (i < game_data->map.r[0])
	{
		init_ray(game_data, i);
		calculate_draw_start_end(game_data);
		while (ray->draw_start <= ray->draw_end)
		{
			my_mlx_pixel_put(&game_data->img_data, i, ray->draw_start, 0x0000FF);
			ray->draw_start++;
		}
		i++;
	}
	mlx_put_image_to_window(game_data->mlx_data.mlx, game_data->mlx_data.win, game_data->img_data.img, 0, 0);
	return (0);
}
