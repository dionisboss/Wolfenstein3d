/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_rendering_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 12:52:54 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/17 17:38:16 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_engine.h"

void	sort_double_vectors(int *order, double *distance, size_t len)
{
	size_t	i;
	size_t	j;
	double	save;

	if (len == 0)
		return ;
	i = -1;
	while (i++ < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (distance[i] < distance[j])
			{
				save = distance[i];
				distance[i] = distance[j];
				distance[j] = save;
				save = (double)order[i];
				order[i] = order[j];
				order[j] = (int)save;
			}
			j++;
		}
	}
}

void	init_order(t_game *game)
{
	t_player_pos			*pos;
	t_double_vector				**sprite;
	size_t					i;
	static int				order[2048];
	static double			distance[2048];

	pos = &game->player.pos;
	sprite = game->sprites.sprites;
	i = 0;
	while (i < game->sprites.num_sprites)
	{
		order[i] = i;
		distance[i] = ((pos->x - sprite[i]->x) * (pos->x - sprite[i]->x) +
				(pos->y - sprite[i]->y) * (pos->y - sprite[i]->y));
		i++;
	}
	game->sprites.render.sprite_order = order;
	game->sprites.render.sprite_distance = distance;
}

void	init_double_vector(t_game *game, size_t i)
{
	t_player		*player;
	t_ray			*ray;
	t_spr_render	*render;
	t_double_vector		**sprite;
	int				*sprite_order;

	player = &game->player;
	ray = &game->ray;
	render = &game->sprites.render;
	sprite = game->sprites.sprites;
	sprite_order = render->sprite_order;
	render->sprite_x = sprite[sprite_order[i]]->x - player->pos.x;
	render->sprite_y = sprite[sprite_order[i]]->y - player->pos.y;
	render->inv_det = 1.0 /
		(ray->plane.x * player->dir.y - player->dir.x * ray->plane.y);
	render->transform_x = render->inv_det *
		(player->dir.y * render->sprite_x - player->dir.x * render->sprite_y);
	render->transform_y = render->inv_det *
		(-ray->plane.y * render->sprite_x + ray->plane.x * render->sprite_y);
	render->sprite_screen_x = (int)(game->map.r[0] - game->map.r[0] / 2 *
			(1 + render->transform_x / render->transform_y));
}

void	calculate_drawstart_end(t_game *game)
{
	t_spr_render	*render;

	render = &game->sprites.render;
	render->sprite_height = abs((int)(game->map.r[1] / render->transform_y));
	render->sprite_width = abs((int)(game->map.r[1] / render->transform_y));
	render->draw_start_y = -render->sprite_height / 2 + game->map.r[1] / 2;
	if (render->draw_start_y < 0)
		render->draw_start_y = 0;
	render->draw_end_y = render->sprite_height / 2 + game->map.r[1] / 2;
	if (render->draw_end_y >= game->map.r[1])
		render->draw_end_y = game->map.r[1] - 1;
	render->draw_start_x = -render->sprite_width / 2 + render->sprite_screen_x;
	if (render->draw_start_x < 0)
		render->draw_start_x = 0;
	render->draw_end_x = render->sprite_width / 2 + render->sprite_screen_x;
}
