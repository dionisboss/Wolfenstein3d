/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_map_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:51:02 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/01 15:51:02 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_map.h"
#include "check_config_error.h"
#include "libft.h"

int			check_map_empty_line(char *s)
{
	char	empty_status;

	if (s == NULL)
		return (TRUE);
	if (*s == '\0')
		return (TRUE);
	empty_status = TRUE;
	while (*s != '\0')
	{
		if (ft_strchr("012NSEW", *s) != NULL)
			empty_status = FALSE;
		s++;
	}
	return (empty_status);
}

static int	scan_map_empty_lines(char **maze)
{
	size_t	y;

	y = 0;
	while (maze[y] != NULL)
	{
		if (maze[y][0] == '\0')
			return (TRUE);
		y++;
	}
	return (FALSE);
}

#include <stdio.h>
static int	check_position_player(char **maze)
{
	size_t	player_count;
	size_t	x;
	size_t	y;

	if (maze == NULL)
		return (FALSE);
	player_count = 0;
	y = 0;
	while (maze[y] != NULL)
	{
		x = 0;
		while (maze[y][x] != '\0')
		{
			if (ft_strchr("NSEW", maze[y][x]) != NULL)
				player_count++;
			x++;
		}
		y++;
	}
	if (player_count == 1)
		return (TRUE);
	return (FALSE);
}

int			scan_map_error(t_map *map)
{
	if (map == NULL)
		return (TRUE);
	if ((scan_map_empty_lines(map->map)) == TRUE)
		return (ERROR);
	if (check_position_player(map->map) != TRUE)
		return (ERROR);
	if (is_closed_map(map->map) != TRUE)
		return (ERROR);
	return (TRUE);
}
