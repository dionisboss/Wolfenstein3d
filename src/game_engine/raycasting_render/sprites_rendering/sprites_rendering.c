/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_rendering.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:27:42 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/17 18:58:53 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_engine.h"

static void	init_color(t_game *game)
{
	t_spr_render		*render;
	t_double_vectors	*sprites;

	render = &game->sprites.render;
	sprites = &game->sprites;
	render->d = (render->y) * 256 - game->map.r[1] * 128 +
		render->sprite_height * 128;
	render->tex_y = ((render->d * sprites->texture.height) /
			render->sprite_height) / 256;
	render->color = ((int*)game->sprites.texture.img.addr)
		[sprites->texture.width * render->tex_y + render->tex_x];
}

static int	need_drawing(t_game *game, double *z_buff)
{
	t_spr_render	*render;

	render = &game->sprites.render;
	return (render->transform_y > 0 && render->stripe > 0 &&
			render->stripe < game->map.r[0] &&
			render->transform_y < z_buff[render->stripe]);
}

static void	render_stripe(t_game *game, double *z_buff)
{
	t_spr_render		*render;
	t_double_vectors	*sprites;

	render = &game->sprites.render;
	sprites = &game->sprites;
	while (render->stripe < render->draw_end_x)
	{
		render->tex_x = (int)(256 * (render->stripe -
					(-render->sprite_width / 2 + render->sprite_screen_x)) *
				sprites->texture.width / render->sprite_width) / 256;
		if (need_drawing(game, z_buff))
		{
			render->y = render->draw_start_y;
			while (render->y < render->draw_end_y)
			{
				init_color(game);
				if ((render->color & 0x00FFFFFF) != 9961608)
					my_mlx_pixel_put(&game->img, render->stripe,
							render->y, render->color);
				render->y++;
			}
		}
		render->stripe++;
	}
}

void		render_sprites(t_game *game, double *z_buff)
{
	t_double_vectors		*sprites;
	t_spr_render			*render;
	size_t					i;

	sprites = &game->sprites;
	render = &sprites->render;
	init_order(game);
	sort_double_vectors(render->sprite_order,
			render->sprite_distance, sprites->num_sprites);
	i = 0;
	while (i < game->sprites.num_sprites)
	{
		init_double_vector(game, i);
		calculate_drawstart_end(game);
		render->stripe = render->draw_start_x;
		render_stripe(game, z_buff);
		i++;
	}
}
