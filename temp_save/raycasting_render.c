/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_render.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:49:20 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/17 18:12:31 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "new_map.h"
#include "game_engine.h"
#include "mlx.h"

int		raycasting_render(t_game *game)
{
	t_ray_dir			*ray;
	static size_t		i;

	draw_sky(game);
	draw_land(game);

	ray = &game->ray;

	player_move(game);

	i = 0;
	while (i < game->map.r[0])
	{
		ray->camera_x = 2 * (game->map.r[0] - i) / (double)(game->map.r[0]) - 1;
		ray->dir.x = game->player.dir.x + ray->plane.x * ray->camera_x;
		ray->dir.y = game->player.dir.y + ray->plane.y * ray->camera_x;

		ray->map.x = (int)game->player.pos.x;
		ray->map.y = (int)game->player.pos.y;

		ray->side_d.delta_x = fabs(1 / ray->dir.x);
		ray->side_d.delta_y = fabs(1 / ray->dir.y);

		if (ray->dir.x < 0)
		{
			ray->step.x = -1;
			ray->side_d.x = (game->player.pos.x - ray->map.x) * ray->side_d.delta_x;
		}
		else
		{
			ray->step.x = 1;
			ray->side_d.x = (ray->map.x + 1.0 - game->player.pos.x) * ray->side_d.delta_x;
		}
		if (ray->dir.y < 0)
		{
			ray->step.y = -1;
			ray->side_d.y = (game->player.pos.y - ray->map.y) * ray->side_d.delta_y;
		}
		else
		{
			ray->step.y = 1;
			ray->side_d.y = (ray->map.y + 1.0 - game->player.pos.y) * ray->side_d.delta_y;
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
			if (game->map.map[ray->map.y][ray->map.x] == '1')
				ray->hit = 1;
		}

		if (ray->side == 0)
			ray->perp_wall_dist = (ray->map.x - game->player.pos.x + (1 - ray->step.x) / 2) / ray->dir.x;
		else
			ray->perp_wall_dist = (ray->map.y - game->player.pos.y + (1 - ray->step.y) / 2) / ray->dir.y;

		ray->line_h = (int)(game->map.r[1] / ray->perp_wall_dist);
		ray->draw_start = -(ray->line_h) / 2 + game->map.r[1] / 2;

		if (ray->draw_start < 0)
			ray->draw_start = 0;

		ray->draw_end = ray->line_h / 2 + game->map.r[1] / 2;

		if (ray->draw_end >= game->map.r[1])
			ray->draw_end = game->map.r[1] - 1;

		while (ray->draw_start <= ray->draw_end)
		{
			my_mlx_pixel_put(&game->img, i, ray->draw_start, 0x0000FF);
			ray->draw_start++;
		}
		i++;
	}
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->img.img, 0, 0);
	return (0);
}
