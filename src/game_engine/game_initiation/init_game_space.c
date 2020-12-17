/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:48:26 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/17 19:58:11 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "game_engine.h"
#include "mlx.h"

static int	init_window(t_mlx *mlx, t_map *map)
{
	if ((mlx->mlx = mlx_init()) == NULL)
	{
		map->clear(map);
		write(2, "ERROR: can't init mlx\n", 22);
		exit(-1);
	}
	mlx->win = mlx_new_window(mlx->mlx, map->r[0], map->r[1], "CUB3D");
	if (mlx->win == NULL)
	{
		map->clear(map);
		write(2, "ERROR: can't create window\n", 27);
		exit(-1);
	}
	return (0);
}

static int	init_img(t_img *img, t_mlx *mlx, t_map *map)
{
	img->img = mlx_new_image(mlx->mlx, map->r[0], map->r[1]);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_lenght, &img->endian);
	return (0);
}

int			init_game_space(t_game *game)
{
	init_player(&game->player, &game->ray.plane, game->map.map);
	init_window(&game->mlx, &game->map);
	init_img(&game->img, &game->mlx, &game->map);
	init_wall_textures(game);
	init_double_vectors(game);
	return (0);
}
