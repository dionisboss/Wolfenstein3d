/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_sideways.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 15:23:05 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/17 19:58:19 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_engine.h"

int	move_sideways(t_game *game)
{
	t_player	*player;
	char		**maze;

	player = &game->player;
	maze = game->map.map;
	if (game->keys.a == 1)
	{
		if (a_strafe_next_y_is_not_wall(game))
			player->pos.y += game->ray.plane.y * MOVE_SPEED;
		if (a_strafe_next_x_is_not_wall(game))
			player->pos.x += game->ray.plane.x * MOVE_SPEED;
	}
	if (game->keys.d == 1)
	{
		if (d_strafe_next_y_is_not_wall(game))
			player->pos.y -= game->ray.plane.y * MOVE_SPEED;
		if (d_strafe_next_x_is_not_wall(game))
			player->pos.x -= game->ray.plane.x * MOVE_SPEED;
	}
	return (0);
}
