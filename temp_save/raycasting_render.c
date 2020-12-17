/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_render.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:49:20 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/17 16:52:00 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "new_map.h"
#include "game_engine.h"
#include "mlx.h"

int		raycasting_render(t_game *game_data)
{
	t_ray_dir			*ray;
	static size_t		i;

	draw_sky(game_data);
	draw_land(game_data);

	ray = &game_data->ray;

	player_move(game_data);

	i = 0;
	while (i < game_data->map.r[0])
	{
		ray->camera_x = 2 * (game_data->map.r[0] - i) / (double)(game_data->map.r[0]) - 1;
		ray->dir.x = game_data->player.dir.x + ray->plane.x * ray->camera_x;
		ray->dir.y = game_data->player.dir.y + ray->plane.y * ray->camera_x;

		ray->map.x = (int)game_data->player.pos.x;
		ray->map.y = (int)game_data->player.pos.y;

		ray->side_d.delta_x = fabs(1 / ray->dir.x);
		ray->side_d.delta_y = fabs(1 / ray->dir.y);

		if (ray->dir.x < 0)
		{
			ray->step.x = -1;
			ray->side_d.x = (game_data->player.pos.x - ray->map.x) * ray->side_d.delta_x;
		}
		else
		{
			ray->step.x = 1;
			ray->side_d.x = (ray->map.x + 1.0 - game_data->player.pos.x) * ray->side_d.delta_x;
		}
		if (ray->dir.y < 0)
		{
			ray->step.y = -1;
			ray->side_d.y = (game_data->player.pos.y - ray->map.y) * ray->side_d.delta_y;
		}
		else
		{
			ray->step.y = 1;
			ray->side_d.y = (ray->map.y + 1.0 - game_data->player.pos.y) * ray->side_d.delta_y;
		}

		ray->hit = 0;
		while (ray->hit == 0)
		{
			if (ray->side_d.x < ray->side_d.y)
			{
				ray->side_d.x += ray->side_d.delta_x;
				ray->map.x += ray->step.x;
				ray->side = 0;
			}
			else
			{
				ray->side_d.y += ray->side_d.delta_y;
				ray->map.y += ray->step.y;
				ray->side = 1;
			}
			if (game_data->map.map[ray->map.y][ray->map.x] == '1')
				ray->hit = 1;
		}

		if (ray->side == 0)
			ray->perp_wall_dist = (ray->map.x - game_data->player.pos.x + (1 - ray->step.x) / 2) / ray->dir.x;
		else
			ray->perp_wall_dist = (ray->map.y - game_data->player.pos.y + (1 - ray->step.y) / 2) / ray->dir.y;

		ray->line_h = (int)(game_data->map.r[1] / ray->perp_wall_dist);
		ray->draw_start = -(ray->line_h) / 2 + game_data->map.r[1] / 2;

		if (ray->draw_start < 0)
			ray->draw_start = 0;

		ray->draw_end = ray->line_h / 2 + game_data->map.r[1] / 2;

		if (ray->draw_end >= game_data->map.r[1])
			ray->draw_end = game_data->map.r[1] - 1;

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
