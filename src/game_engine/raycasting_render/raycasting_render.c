/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_render.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:49:20 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/17 18:49:55 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "new_map.h"
#include "game_engine.h"
#include "mlx.h"
#include <stdio.h>

int		raycasting_render(t_game *game)
{
	t_mlx	*mlx;
	t_ray	*ray;
	double	z_buff[game->map.r[0]];
	size_t	x;

	player_move(game);
	draw_sky(game);
	draw_land(game);
	mlx = &game->mlx;
	ray = &game->ray;
	x = 0;
	while (x < game->map.r[0])
	{
		init_ray(game, x);
		calculate_draw_start_end(game);
		draw_textures(game, x);
		z_buff[x] = ray->perp_wall_dist;
		x++;
	}
	render_sprites(game, z_buff);
	mlx_put_image_to_window(mlx->mlx, mlx->win, game->img.img, 0, 0);
	return (0);
}
