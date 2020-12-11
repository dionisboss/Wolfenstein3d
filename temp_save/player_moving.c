/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moving.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:51:30 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/10 20:41:49 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "game_engine.h"

/*
** For moving to forward/backward.
*/

static int	is_zero(t_keys_f *keys)
{
	return (keys->w == 0 && keys->s == 0 && keys->a == 0 && keys->d == 0 &&
			keys->q == 0 && keys->e == 0);
}

static int	next_y_is_not_wall(char **maze, t_player *player)
{
	return (maze[(int)(player->pos.y + (player->dir.y * MOVE_SPEED))]
			[(int)player->pos.x] == '0' ||
			is_player(maze[(int)(player->pos.y + player->dir.y * MOVE_SPEED)]
			[(int)player->pos.x]));
}

static int	next_x_is_not_wall(char **maze, t_player *player)
{
	return (maze[(int)player->pos.y]
			[(int)(player->pos.x + player->dir.x * MOVE_SPEED)] == '0' ||
			is_player(maze[(int)player->pos.y]
			[(int)(player->pos.x + player->dir.x * MOVE_SPEED)]));
}

static int	previous_y_is_not_wall(char **maze, t_player *player)
{
	return (maze[(int)(player->pos.y - player->dir.y * MOVE_SPEED)]
			[(int)player->pos.x] == '0' ||
			is_player(maze[(int)(player->pos.y - player->dir.y * MOVE_SPEED)]
			[(int)player->pos.x]));
}

static int	previous_x_is_not_wall(char **maze, t_player *player)
{
	return (maze[(int)player->pos.y]
			[(int)(player->pos.x - player->dir.x * MOVE_SPEED)] == '0' ||
			is_player(maze[(int)player->pos.y]
			[(int)(player->pos.x - player->dir.x * MOVE_SPEED)]));
}

/*
** For strafe.
*/

static int	a_strafe_next_y_is_not_wall(char **maze, t_game_data *game_data)
{

	t_plane		*plane = &game_data->ray.plane;
	t_player	*player = &game_data->player;

	return (maze[(int)(player->pos.y + plane->y * MOVE_SPEED)]
			[(int)player->pos.x] == '0' ||
			is_player(maze[(int)(player->pos.y + plane->y * MOVE_SPEED)]
				[(int)player->pos.x]
			));
}

static int	a_strafe_next_x_is_not_wall(char **maze, t_game_data *game_data)
{

	t_plane		*plane = &game_data->ray.plane;
	t_player	*player = &game_data->player;

	return (maze[(int)player->pos.y]
			[(int)(player->pos.x + plane->x * MOVE_SPEED)] == '0' ||
			is_player(maze[(int)player->pos.y]
			[(int)(player->pos.x + plane->x * MOVE_SPEED)]));
}

static int	d_strafe_next_y_is_not_wall(char **maze, t_game_data *game_data)
{

	t_plane		*plane = &game_data->ray.plane;
	t_player	*player = &game_data->player;

	return (maze[(int)(player->pos.y - plane->y * MOVE_SPEED)]
			[(int)player->pos.x] == '0' ||
			is_player(maze[(int)(player->pos.y - plane->y * MOVE_SPEED)]
				[(int)player->pos.x]
			));
}

static int	d_strafe_next_x_is_not_wall(char **maze, t_game_data *game_data)
{

	t_plane		*plane = &game_data->ray.plane;
	t_player	*player = &game_data->player;

	return (maze[(int)player->pos.y]
			[(int)(player->pos.x - plane->x * MOVE_SPEED)] == '0' ||
			is_player(maze[(int)player->pos.y]
			[(int)(player->pos.x - plane->x * MOVE_SPEED)]));
}

void		player_move(t_game_data *game_data)
{
	t_player	*player;
	char		**maze;

	if (is_zero(&game_data->keys) == TRUE)
		return ;

	player = &game_data->player;
	maze = game_data->map.map;

	if (game_data->keys.w == 1)
	{
		if (next_y_is_not_wall(maze, player))
		{
			player->pos.y += player->dir.y * MOVE_SPEED;
		}
		if (next_x_is_not_wall(maze, player))
		{
			player->pos.x += player->dir.x * MOVE_SPEED;
		}
	}
	if (game_data->keys.s == 1)
	{
		if (previous_y_is_not_wall(maze, player))
		{
			player->pos.y -= player->dir.y * MOVE_SPEED;
		}
		if (previous_x_is_not_wall(maze, player))
		{
			player->pos.x -= player->dir.x * MOVE_SPEED;
		}
	}
	if (game_data->keys.a == 1)
	{
		if (a_strafe_next_y_is_not_wall(maze, game_data))
		{
			player->pos.y += game_data->ray.plane.y * MOVE_SPEED;
		}
		if (a_strafe_next_x_is_not_wall(maze, game_data))
		{
			player->pos.x += game_data->ray.plane.x * MOVE_SPEED;
		}
	}
	if (game_data->keys.d == 1)
	{
		if (d_strafe_next_y_is_not_wall(maze, game_data))
		{
			player->pos.y -= game_data->ray.plane.y * MOVE_SPEED;
		}
		if (d_strafe_next_x_is_not_wall(maze, game_data))
		{
			player->pos.x -= game_data->ray.plane.x * MOVE_SPEED;
		}
	}
	if (game_data->keys.q == 1)
	{
		double	old_dir_x = player->dir.x;
		player->dir.x = player->dir.x * cos(-ROT_SPEED) - player->dir.y * sin(-ROT_SPEED);
		player->dir.y = old_dir_x * sin(-ROT_SPEED) + player->dir.y * cos(-ROT_SPEED);
		double old_plane_x = game_data->ray.plane.x;
		game_data->ray.plane.x = game_data->ray.plane.x * cos(-ROT_SPEED) - game_data->ray.plane.y * sin(-ROT_SPEED);
		game_data->ray.plane.y = old_plane_x * sin(-ROT_SPEED) + game_data->ray.plane.y * cos(-ROT_SPEED);
	}
	if (game_data->keys.e == 1)
    {
      double old_dir_x = player->dir.x;
      player->dir.x = player->dir.x * cos(ROT_SPEED) - player->dir.y * sin(ROT_SPEED);
      player->dir.y = old_dir_x * sin(ROT_SPEED) + player->dir.y * cos(ROT_SPEED);
      double old_plane_x = game_data->ray.plane.x;
      game_data->ray.plane.x = game_data->ray.plane.x * cos(ROT_SPEED) - game_data->ray.plane.y * sin(ROT_SPEED);
      game_data->ray.plane.y = old_plane_x * sin(ROT_SPEED) + game_data->ray.plane.y * cos(ROT_SPEED);
    }
}
