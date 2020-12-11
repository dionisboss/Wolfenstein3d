/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 13:39:02 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/10 15:07:09 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_engine.h"

int			is_player(char c)
{
	return (c == 'N' || c == 'S' ||c == 'E' ||c == 'W');
}

static int	take_position(t_player *player, char **maze)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (maze[i] != NULL)
	{
		j = 0;
		while (maze[i][j] != '\0')
		{
			if (is_player(maze[i][j]) == TRUE)
			{
				player->pos.x = j + 0.5;
				player->pos.y = i + 0.5;
				player->start_view = maze[i][j];
				return (TRUE);
			}
			j++;
		}
		i++;
	}
	return (FALSE);
}

static int	take_direction(t_player *player, t_plane *plane)
{
	if (player->start_view == 'N')
	{
		player->dir.x = 0;
		player->dir.y = -1;
		plane->x = -0.66;
		plane->y = 0;
	}
	if (player->start_view == 'S')
	{
		player->dir.x = 0;
		player->dir.y = 1;
		plane->x = 0.66;
		plane->y = 0;
	}
	if (player->start_view == 'W')
	{
		player->dir.x = -1;
		player->dir.y = 0;
		plane->x = 0;
		plane->y = 0.66;
	}
	if (player->start_view == 'E')
	{
		player->dir.x = 1;
		player->dir.y = 0;
		plane->x = 0;
		plane->y = -0.66;
	}
	return (0);
}

int			init_player(t_player *player, t_plane *plane, char **maze)
{
	take_position(player, maze);
	take_direction(player, plane);
	return (TRUE);
}
