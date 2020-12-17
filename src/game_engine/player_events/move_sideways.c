/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_sideways.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 15:23:05 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/17 16:51:41 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_engine.h"

int	move_sideways(t_game *game_data)
{
	t_player	*player;
	char		**maze;

	player = &game_data->player;
	maze = game_data->map.map;
	if (game_data->keys.a == 1)
	{
		if (a_strafe_next_y_is_not_wall(game_data))
			player->pos.y += game_data->ray.plane.y * MOVE_SPEED;
		if (a_strafe_next_x_is_not_wall(game_data))
			player->pos.x += game_data->ray.plane.x * MOVE_SPEED;
	}
	if (game_data->keys.d == 1)
	{
		if (d_strafe_next_y_is_not_wall(game_data))
			player->pos.y -= game_data->ray.plane.y * MOVE_SPEED;
		if (d_strafe_next_x_is_not_wall(game_data))
			player->pos.x -= game_data->ray.plane.x * MOVE_SPEED;
	}
	return (0);
}
