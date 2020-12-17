/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 12:18:35 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/17 18:09:39 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "game_engine.h"

int		start_game(t_game *game)
{
	init_game_space(game);
	mlx_do_key_autorepeatoff(game->mlx.mlx);
	mlx_hook(game->mlx.win, 2, 0, handle_pressed_key, game);
	mlx_hook(game->mlx.win, 3, 0, handle_unpressed_key, game);
	mlx_loop_hook(game->mlx.mlx, raycasting_render, game);
	mlx_loop(game->mlx.mlx);
	return (0);
}

void	finish_game(t_game *game)
{
	mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	game->map.clear(&game->map);
	free_sprites(&game->sprites.sprites);
	exit(0);
}
