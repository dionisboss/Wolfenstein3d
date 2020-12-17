/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 08:17:36 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/17 16:51:39 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "mlx.h"
#include "game_engine.h"
#include "libft.h"

void		print_arr_sprites(t_sprite **sprites)
{
	size_t	k1 = 0;

	while (sprites[k1] != NULL)
	{
		printf("sprites[%zu]: ", k1);
		printf("x = %f y = %f\n", sprites[k1]->x, sprites[k1]->y);
		k1++;
	}
}
void		init_sprites(t_game *game_data)
{
	t_map		*map;
	char		**maze;
	t_sprites	*sprites;
	t_tex_data	*s;
	t_img_data	*s_img;

	map = &game_data->map;
	maze = game_data->map.map;
	init_arr_sprites(game_data);
	sprites = &game_data->sprites;
	//print_arr_sprites(sprites->sprites); // УБРАТЬ
	check_dot_xpm(map->s);
	s = &sprites->tex_data;;
	s_img = &s->img_data;
	s->relative_path = map->s;
	s_img->img = mlx_xpm_file_to_image(game_data->mlx_data.mlx,
			s->relative_path, &s->width, &s->height);

	s_img->addr = mlx_get_data_addr(s_img->img,
			&s_img->bits_per_pixel, &s_img->line_lenght, &s_img->endian);

	if (s_img->img == NULL)
	{
		write(1, "ERROR: mlx cant open sprite texture\n", 36);
		exit(-1);
	}
}
