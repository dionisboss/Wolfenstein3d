/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_rendering.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:27:42 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/17 17:38:17 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_engine.h"

static void	init_color(t_game *game)
{
	t_spr_render	*render;
	t_double_vectors		*sprites;

	render = &game->sprites.render;
	sprites = &game->sprites;
	render->d = (render->y) * 256 - game->map.r[1] * 128 +
		render->sprite_height * 128;
	render->tex_y = ((render->d * sprites->tex_data.height) /
			render->sprite_height) / 256;
	render->color = ((int*)game->sprites.tex_data.img_data.addr)
		[sprites->tex_data.width * render->tex_y + render->tex_x];
}

static int	need_drawing(t_game *game, double *z_buff)
{
	t_spr_render	*render;

	render = &game->sprites.render;
	return (render->transform_y > 0 && render->stripe > 0 &&
			render->stripe < game->map.r[0] &&
			render->transform_y < z_buff[render->stripe]);
}

static void	render_stripe(t_game *game_data, double *z_buff)
{
	t_spr_render	*render;
	t_double_vectors		*sprites;

	render = &game_data->sprites.render;
	sprites = &game_data->sprites;
	while (render->stripe < render->draw_end_x)
	{
		render->tex_x = (int)(256 * (render->stripe -
					(-render->sprite_width / 2 + render->sprite_screen_x)) *
				sprites->tex_data.width / render->sprite_width) / 256;
		if (need_drawing(game_data, z_buff))
		{
			render->y = render->draw_start_y;
			while (render->y < render->draw_end_y)
			{
				init_color(game_data);
				if ((render->color & 0x00FFFFFF) != 9961608)
					my_mlx_pixel_put(&game_data->img_data, render->stripe,
							render->y, render->color);
				render->y++;
			}
		}
		render->stripe++;
	}
}

void		render_sprites(t_game *game_data, double *z_buff)
{
	t_double_vectors		*sprites;
	t_spr_render	*render;
	size_t			i;

	sprites = &game_data->sprites;
	render = &sprites->render;
	init_order(game_data);
	sort_double_vectors(render->sprite_order,
			render->sprite_distance, sprites->num_sprites);
	i = 0;
	while (i < game_data->sprites.num_sprites)
	{
		init_double_vector(game_data, i);
		calculate_drawstart_end(game_data);
		render->stripe = render->draw_start_x;
		render_stripe(game_data, z_buff);
		i++;
	}
}
