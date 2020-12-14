/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_render.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:49:20 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/14 15:36:29 by gdrive           ###   ########.fr       */
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

	//void	**texture = &game_data->tex_data.img;
	i = 0;
	while (i < game_data->map.r[0])
	{
		init_ray(game_data, i);
		calculate_draw_start_end(game_data);

		t_player	*player;
		int			tex_num;

		player = &game_data->player;
		tex_num = game_data->map.map[ray->map.y][ray->map.x] - 1;

		double	wall_x;

		if (ray->side == 0)
			wall_x = player->pos.y + ray->perp_wall_dist * ray->dir.y;
		else
			wall_x = player->pos.x + ray->perp_wall_dist * ray->dir.x;
		wall_x -= floor((wall_x));

		int		tex_x;

		tex_x = (int)(wall_x * (double)(64));
		if (ray->side == 0 && ray->dir.x > 0)
			tex_x = 64 - tex_x - 1;
		if (ray->side == 1 && ray->dir.y < 0)
			tex_x = 64 - tex_x - 1;

		//texture 64 x 64
		double	step = 1.0 * 64 / ray->line_h;

		double	tex_pos = (ray->draw_start - game_data->map.r[1] / 2 + ray->line_h / 2) * step;
		uint32_t	color;
		for (int y = ray->draw_start; y < ray->draw_end; y++)
			{
				// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
				int			tex_y;

				tex_y = (int)tex_pos & (64 - 1);
				tex_pos += step;


				color = ((int*)game_data->tex_data.img_data.addr)[64 * tex_y + tex_x];
				if (ray->side == 1)
					color = (color >> 1) & 8355711;
				my_mlx_pixel_put(&game_data->img_data, i, y, color);
			}
			i++;
	}
	mlx_put_image_to_window(game_data->mlx_data.mlx, game_data->mlx_data.win, game_data->img_data.img, 0, 0);
	return (0);
}
