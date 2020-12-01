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
	char	symbol_status;

	if (s == NULL)
		return (TRUE);
	if (*s == '\0')
		return (TRUE);
	symbol_status = TRUE;
	while (*s != '\0')
	{
		if (ft_strchr("012NSEW", *s) != NULL)
			symbol_status = FALSE;
		s++;
	}
	return (symbol_status);
}

static int	scan_map_empty_lines(char **maze)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (maze[y] != NULL)
	{
		if (check_map_empty_line(maze[y]) == TRUE)
			return (TRUE);
		y++;
	}
	return (FALSE);
}

int			scan_map_error(t_map *map)
{
	if (map == NULL)
		return (TRUE);
	if ((scan_map_empty_lines(map->map)) == TRUE)
		return (ERROR);
	if (is_closed_map(map->map) != TRUE)
		return (ERROR);
	return (TRUE);
}
