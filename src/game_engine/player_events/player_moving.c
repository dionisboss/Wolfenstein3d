/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moving.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:51:30 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/17 16:51:42 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_engine.h"

static int	is_zero(t_keys_f *keys)
{
	return (keys->w == 0 && keys->s == 0 && keys->a == 0 && keys->d == 0 &&
			keys->q == 0 && keys->e == 0);
}

void		player_move(t_game *game_data)
{
	t_player	*player;
	char		**maze;

	if (is_zero(&game_data->keys) == TRUE)
		return ;
	player = &game_data->player;
	maze = game_data->map.map;
	if (game_data->keys.w == 1 || game_data->keys.s == 1)
	{
		move_forward_backward(game_data);
	}
	if (game_data->keys.a == 1 || game_data->keys.d == 1)
	{
		move_sideways(game_data);
	}
	if (game_data->keys.q == 1 || game_data->keys.e == 1)
	{
		turn_player(game_data);
	}
}
