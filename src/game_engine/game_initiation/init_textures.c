/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:47:54 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/14 18:33:01 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "game_engine.h"
#include "libft.h"

static void	check_dot_xpm(char *s)
{
	size_t	i;

	i = ft_strlen(s) - 1;
	while (i >= 0)
	{
		if (s[i] == '.')
		{
			if (ft_strcmp(s + i, ".xpm") == 0)
				return ;
		}
		i--;
	}
	write(1, "ERROR: invalid textures\n", 24);
	exit(-1);
}

void		init_relative_path(t_textures *tex_data, t_map *map)
{
	tex_data->no.relative_path = map->no;
	tex_data->so.relative_path = map->so;
	tex_data->we.relative_path = map->we;
	tex_data->ea.relative_path = map->ea;
	check_dot_xpm(tex_data->no.relative_path);
	check_dot_xpm(tex_data->so.relative_path);
	check_dot_xpm(tex_data->we.relative_path);
	check_dot_xpm(tex_data->ea.relative_path);
}

void		init_textures(t_game_data *game_data)
{
	t_textures	*tex_data;
	t_map		*map;

	tex_data = &game_data->tex_data;
	map = &game_data->map;
	init_relative_path(&game_data->tex_data, &game_data->map);
	init_img_north_texture(game_data->mlx_data.mlx, &game_data->tex_data);
	init_img_south_texture(game_data->mlx_data.mlx, &game_data->tex_data);
	init_img_west_texture(game_data->mlx_data.mlx, &game_data->tex_data);
	init_img_east_texture(game_data->mlx_data.mlx, &game_data->tex_data);
}
