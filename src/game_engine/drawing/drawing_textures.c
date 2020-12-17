/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 19:35:32 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/17 19:58:08 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "game_engine.h"
#include "drawing_textures.h"

static t_texture	*init_tex(t_game *game)
{
	t_ray	*ray;

	ray = &game->ray;
	if (ray->side == 1)
	{
		if (ray->step.y > 0)
			return (&game->texture.no);
		if (ray->step.y < 0)
			return (&game->texture.so);
	}
	if (ray->side == 0)
	{
		if (ray->step.x > 0)
			return (&game->texture.we);
		if (ray->step.x < 0)
			return (&game->texture.ea);
	}
	return (NULL);
}

static void			init_vars(t_game *game, t_tex_draw_vars *vars)
{
	t_ray				*ray;
	t_player			*player;

	ray = &game->ray;
	player = &game->player;
	if (ray->side == 0)
		vars->wall_x = player->pos.y + ray->perp_wall_dist * ray->dir.y;
	else
		vars->wall_x = player->pos.x + ray->perp_wall_dist * ray->dir.x;
	vars->wall_x = 1 - (vars->wall_x - floor((vars->wall_x)));
	vars->tex_x = (int)(vars->wall_x * (double)(vars->tex->width));
	if (ray->side == 0 && ray->dir.x > 0)
		vars->tex_x = vars->tex->width - vars->tex_x - 1;
	if (ray->side == 1 && ray->dir.y < 0)
		vars->tex_x = vars->tex->width - vars->tex_x - 1;
	vars->step = 1.0 * vars->tex->height / ray->line_h;
	vars->tex_pos = (ray->draw_start - game->map.r[1] / 2 + ray->line_h / 2) *
		vars->step;
	vars->tex_num = game->map.map[ray->map.y][ray->map.x] - 1;
}

void				draw_textures(t_game *game, size_t i)
{
	t_tex_draw_vars		vars;
	t_ray				*ray;
	t_player			*player;
	int					y;

	ray = &game->ray;
	player = &game->player;
	vars.tex = init_tex(game);
	init_vars(game, &vars);
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		vars.tex_y = (int)vars.tex_pos & (64 - 1);
		vars.tex_pos += vars.step;
		vars.color = ((int*)vars.tex->img.addr)[64 * vars.tex_y + vars.tex_x];
		my_mlx_pixel_put(&game->img, i, y, vars.color);
		y++;
	}
}
