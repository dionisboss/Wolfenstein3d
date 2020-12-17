/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:48:26 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/17 17:38:16 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "game_engine.h"
#include "mlx.h"

static int	init_window(t_mlx_data *mlx_data, t_map *map)
{
	if ((mlx_data->mlx = mlx_init()) == NULL)
	{
		map->clear(map);
		write(2, "ERROR: can't init mlx\n", 22);
		exit(-1);
	}
	mlx_data->win = mlx_new_window(mlx_data->mlx, map->r[0], map->r[1], "CUB3D");
	if (mlx_data->win == NULL)
	{
		map->clear(map);
		write(2, "ERROR: can't create window\n", 27);
		exit(-1);
	}
	return (0);
}

static int	init_img(t_img_data *img_data, t_mlx_data *mlx_data, t_map *map)
{
	img_data->img = mlx_new_image(mlx_data->mlx, map->r[0], map->r[1]);
	img_data->addr = mlx_get_data_addr(img_data->img, &img_data->bits_per_pixel, &img_data->line_lenght, &img_data->endian);
	return (0);
}

int			init_game_space(t_game *game_data)
{
	init_player(&game_data->player, &game_data->ray.plane, game_data->map.map);
	init_window(&game_data->mlx_data, &game_data->map);
	init_img(&game_data->img_data, &game_data->mlx_data, &game_data->map);
	init_wall_textures(game_data);
	init_double_vectors(game_data);
	return (0);
}
