/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_draw_start_end.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 19:42:27 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/17 16:51:42 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "game_engine.h"

static void		throw_a_beam(t_ray *ray, char **maze)
{
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
		if (maze[ray->map.y][ray->map.x] == '1')
			ray->hit = 1;
	}
}

static void		calculate_perp_wall_dist(t_game *game_data)
{
	t_ray		*ray;
	t_player	*player;

	ray = &game_data->ray;
	player = &game_data->player;
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map.x - player->pos.x +
				(1 - ray->step.x) / 2) / ray->dir.x;
	else
		ray->perp_wall_dist = (ray->map.y - player->pos.y +
				(1 - ray->step.y) / 2) / ray->dir.y;
}

void			calculate_draw_start_end(t_game *game_data)
{
	t_ray	*ray;

	ray = &game_data->ray;
	throw_a_beam(ray, game_data->map.map);
	calculate_perp_wall_dist(game_data);
	ray->line_h = (int)(game_data->map.r[1] / ray->perp_wall_dist);
	ray->draw_start = -(ray->line_h) / 2 + game_data->map.r[1] / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_h / 2 + game_data->map.r[1] / 2;
	if (ray->draw_end >= game_data->map.r[1])
		ray->draw_end = game_data->map.r[1] - 1;
}
