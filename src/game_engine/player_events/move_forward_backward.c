/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_forward_backward.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 15:06:37 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/17 17:46:06 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_engine.h"

int		move_forward_backward(t_game *game)
{
	t_player	*player;
	char		**maze;

	player = &game->player;
	maze = game->map.map;
	if (game->keys.w == 1)
	{
		if (next_y_is_not_wall(maze, player))
			player->pos.y += player->dir.y * MOVE_SPEED;
		if (next_x_is_not_wall(maze, player))
			player->pos.x += player->dir.x * MOVE_SPEED;
	}
	if (game->keys.s == 1)
	{
		if (previous_y_is_not_wall(maze, player))
			player->pos.y -= player->dir.y * MOVE_SPEED;
		if (previous_x_is_not_wall(maze, player))
			player->pos.x -= player->dir.x * MOVE_SPEED;
	}
	return (0);
}
