/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_rendering.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:27:42 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/16 15:38:34 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_engine.h"

void	sort_sprites(int *sprite_order, double *sprite_distance, size_t len)
{
	if (len == 0)
		return ;

	size_t	i = 0;
	size_t	j = 0;
	int		save_order;
	double	save_double;

	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (sprite_distance[i] < sprite_distance[j])
			{
				save_double = sprite_distance[i];
				sprite_distance[i] = sprite_distance[j];
				sprite_distance[j] = save_double;

				save_order = sprite_order[i];
				sprite_order[i] = sprite_order[j];
				sprite_order[j] = save_order;
			}
			j++;
		}
		i++;
	}

}

void	render_sprites(t_game_data *game_data, double *z_buff)
{
	t_sprites		*sprites;
	t_sprite		**sprite;
	t_spr_render	*render;
	t_ray			*ray;
	t_player		*player;
	size_t		i;
	double		spriteDistance[game_data->sprites.num_sprites];
	int			spriteOrder[game_data->sprites.num_sprites];

	sprites = &game_data->sprites;
	sprite = game_data->sprites.sprites;
	ray = &game_data->ray;
	player = &game_data->player;
	render = &game_data->sprites.render;

	i = 0;
	while (i < sprites->num_sprites)
	{
		spriteOrder[i] = i;
		spriteDistance[i] = ((player->pos.x - sprite[i]->x) * (player->pos.x - sprite[i]->x) + (player->pos.y - sprite[i]->y) * (player->pos.y - sprite[i]->y));
	  i++;
	}
	sort_sprites(spriteOrder, spriteDistance, sprites->num_sprites);


	i = 0;
	while (i < sprites->num_sprites)
	{
		render->sprite_x = sprite[spriteOrder[i]]->x - player->pos.x;
		render->sprite_y = sprite[spriteOrder[i]]->y - player->pos.y;
		render->inv_det =  1.0 / (ray->plane.x * player->dir.y - player->dir.x * ray->plane.y);

		render->transform_x = render->inv_det * (player->dir.y * render->sprite_x - player->dir.x * render->sprite_y);
		render->transform_y = render->inv_det * (-ray->plane.y * render->sprite_x + ray->plane.x * render->sprite_y);

		render->sprite_screen_x = (int)(game_data->map.r[0] - game_data->map.r[0] / 2 * (1 + render->transform_x / render->transform_y));

		render->sprite_height = abs((int)(game_data->map.r[1] / (render->transform_y)));
		render->draw_start_y = -render->sprite_height / 2 + game_data->map.r[1] / 2;
		if(render->draw_start_y < 0)
			render->draw_start_y = 0;
		render->draw_end_y = render->sprite_height / 2 + game_data->map.r[1] / 2;
		if(render->draw_end_y >= game_data->map.r[1])
			render->draw_end_y = game_data->map.r[1] - 1;

		render->sprite_width = abs((int)(game_data->map.r[1] / (render->transform_y)));
		render->draw_start_x = -render->sprite_width / 2 + render->sprite_screen_x;
		if(render->draw_start_x < 0)
		  render->draw_start_x = 0;
		render->draw_end_x = render->sprite_width / 2 + render->sprite_screen_x;
		render->stripe =  render->draw_start_x;
		while (render->stripe < render->draw_end_x)
		{


			render->tex_x = (int)(256 * (render->stripe - (-render->sprite_width / 2 + render->sprite_screen_x)) * sprites->tex_data.width / render->sprite_width) / 256;
			if(render->transform_y > 0 && render->stripe > 0 && render->stripe < game_data->map.r[0] && render->transform_y < z_buff[render->stripe])
			{
				render->y =  render->draw_start_y;
				while (render->y < render->draw_end_y)
				{

					render->d = (render->y) * 256 - game_data->map.r[1] * 128 + render->sprite_height * 128;
					render->tex_y = ((render->d * sprites->tex_data.height) / render->sprite_height) / 256;
					render->color = ((int*)game_data->sprites.tex_data.img_data.addr)
						[sprites->tex_data.width * render->tex_y + render->tex_x];
					if((render->color & 0x00FFFFFF) != 9961608)
					  my_mlx_pixel_put(&game_data->img_data, render->stripe, render->y, render->color);

					render->y++;
				}
			}

			render->stripe++;
		}
		i++;
	}
}
