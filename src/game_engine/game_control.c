/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 12:18:35 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/15 11:13:03 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "game_engine.h"

int		start_game(t_game_data *game_data)
{
	init_game_space(game_data);
	mlx_do_key_autorepeatoff(game_data->mlx_data.mlx);
	mlx_hook(game_data->mlx_data.win, 2, 0, handle_pressed_key, game_data);
	mlx_hook(game_data->mlx_data.win, 3, 0, handle_unpressed_key, game_data);
	mlx_loop_hook(game_data->mlx_data.mlx, raycasting_render, game_data);
	mlx_loop(game_data->mlx_data.mlx);
	return (0);
}

void	finish_game(t_game_data *game_data)
{
	mlx_destroy_window(game_data->mlx_data.mlx, game_data->mlx_data.win);
	game_data->map.clear(&game_data->map);
	free_sprites(&game_data->sprites.sprites);
	exit(0);
}
