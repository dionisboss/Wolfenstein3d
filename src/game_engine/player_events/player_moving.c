/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moving.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:51:30 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/17 17:46:08 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_engine.h"

static int	is_zero(t_keys_f *keys)
{
	return (keys->w == 0 && keys->s == 0 && keys->a == 0 && keys->d == 0 &&
			keys->q == 0 && keys->e == 0);
}

void		player_move(t_game *game)
{
	t_player	*player;
	char		**maze;

	if (is_zero(&game->keys) == TRUE)
		return ;
	player = &game->player;
	maze = game->map.map;
	if (game->keys.w == 1 || game->keys.s == 1)
	{
		move_forward_backward(game);
	}
	if (game->keys.a == 1 || game->keys.d == 1)
	{
		move_sideways(game);
	}
	if (game->keys.q == 1 || game->keys.e == 1)
	{
		turn_player(game);
	}
}
