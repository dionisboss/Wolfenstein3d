/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:17:47 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/17 18:20:01 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "mlx.h"
#include "game_engine.h"
#include "libft.h"

void		init_double_vectors(t_game *game)
{
	t_map				*map;
	t_double_vectors	*sprites;
	t_tex_data			*s;
	t_img				*s_img;

	map = &game->map;
	init_arr_sprites(game);
	sprites = &game->sprites;
	check_dot_xpm(map->s);
	s = &sprites->tex_data;
	s_img = &s->img;
	s->relative_path = map->s;
	s_img->img = mlx_xpm_file_to_image(game->mlx.mlx,
			s->relative_path, &s->width, &s->height);
	s_img->addr = mlx_get_data_addr(s_img->img,
			&s_img->bits_per_pixel, &s_img->line_lenght, &s_img->endian);
	if (s_img->img == NULL)
	{
		write(2, "ERROR: mlx cant open sprite texture\n", 36);
		exit(-1);
	}
}
