/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_forward_backward_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 15:14:57 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/11 15:19:01 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_engine.h"

int	next_y_is_not_wall(char **maze, t_player *player)
{
	return (maze[(int)(player->pos.y + (player->dir.y * MOVE_SPEED))]
			[(int)player->pos.x] == '0' ||
			is_player(maze[(int)(player->pos.y + player->dir.y * MOVE_SPEED)]
			[(int)player->pos.x]));
}

int	next_x_is_not_wall(char **maze, t_player *player)
{
	return (maze[(int)player->pos.y]
			[(int)(player->pos.x + player->dir.x * MOVE_SPEED)] == '0' ||
			is_player(maze[(int)player->pos.y]
			[(int)(player->pos.x + player->dir.x * MOVE_SPEED)]));
}

int	previous_y_is_not_wall(char **maze, t_player *player)
{
	return (maze[(int)(player->pos.y - player->dir.y * MOVE_SPEED)]
			[(int)player->pos.x] == '0' ||
			is_player(maze[(int)(player->pos.y - player->dir.y * MOVE_SPEED)]
			[(int)player->pos.x]));
}

int	previous_x_is_not_wall(char **maze, t_player *player)
{
	return (maze[(int)player->pos.y]
			[(int)(player->pos.x - player->dir.x * MOVE_SPEED)] == '0' ||
			is_player(maze[(int)player->pos.y]
			[(int)(player->pos.x - player->dir.x * MOVE_SPEED)]));
}
