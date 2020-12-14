/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_forward_backward.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 15:06:37 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/11 18:26:49 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_engine.h"

int		move_forward_backward(t_game_data *game_data)
{
	t_player	*player;
	char		**maze;

	player = &game_data->player;
	maze = game_data->map.map;
	if (game_data->keys.w == 1)
	{
		if (next_y_is_not_wall(maze, player))
			player->pos.y += player->dir.y * MOVE_SPEED;
		if (next_x_is_not_wall(maze, player))
			player->pos.x += player->dir.x * MOVE_SPEED;
	}
	if (game_data->keys.s == 1)
	{
		if (previous_y_is_not_wall(maze, player))
			player->pos.y -= player->dir.y * MOVE_SPEED;
		if (previous_x_is_not_wall(maze, player))
			player->pos.x -= player->dir.x * MOVE_SPEED;
	}
	return (0);
}