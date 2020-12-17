/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 18:40:39 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/17 19:58:24 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "game_engine.h"

static int	init_ray_steps(t_ray *ray, t_player *player)
{
	t_double_vector *pos;

	pos = &player->pos;
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_d.x = (pos->x - ray->map.x) * ray->side_d.delta_x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_d.x = (ray->map.x + 1.0 - pos->x) * ray->side_d.delta_x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_d.y = (pos->y - ray->map.y) * ray->side_d.delta_y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_d.y = (ray->map.y + 1.0 - pos->y) * ray->side_d.delta_y;
	}
	return (0);
}

int			init_ray(t_game *game, size_t i)
{
	t_ray			*ray;
	t_player		*player;
	t_map			*map;

	ray = &game->ray;
	player = &game->player;
	map = &game->map;
	ray->camera_x = 2 * (map->r[0] - i) / (double)(map->r[0]) - 1;
	ray->dir.x = player->dir.x + ray->plane.x * ray->camera_x;
	ray->dir.y = player->dir.y + ray->plane.y * ray->camera_x;
	ray->map.x = (int)game->player.pos.x;
	ray->map.y = (int)game->player.pos.y;
	ray->side_d.delta_x = fabs(1 / ray->dir.x);
	ray->side_d.delta_y = fabs(1 / ray->dir.y);
	init_ray_steps(ray, player);
	ray->hit = 0;
	return (0);
}
