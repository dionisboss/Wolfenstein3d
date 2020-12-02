/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_closed_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:33:27 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/01 13:33:28 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_map.h"
#include "check_config_error.h"
#include "libft.h"

static int	is_not_wall_or_space(char c)
{
	if (ft_strchr("0NSEW2", c) != NULL && c != '\0')
		return (TRUE);
	else
		return (FALSE);
}

static int	is_edge(char **maze, size_t i, size_t j)
{
	if (i == 0 || j == 0 || maze[i][j + 1] == '\0' || maze[i + 1] == NULL)
		return (TRUE);
	return (FALSE);
}

static int	check_walls(char **maze, size_t i, size_t j)
{
	size_t	len_bottom_line;

	len_bottom_line = ft_strlen(maze[i + 1]);
	if (len_bottom_line == 0 || len_bottom_line - 1 < j)
		return (FALSE);
	if (maze[i][j + 1] == '\0' || maze[i][j + 1] == ' ')
		return (FALSE);
	if (maze[i + 1][j] == '\0' || maze[i + 1][j] == ' ')
		return (FALSE);
	return (TRUE);
}

static int	check_walls_or_space(char **maze, size_t i, size_t j)
{
	size_t	len_bottom_line;

	if (is_edge(maze, i , j) == TRUE)
	{
		if (is_not_wall_or_space(maze[i][j + 1]) == TRUE)
			return (FALSE);
		return (TRUE);
	}
	len_bottom_line = ft_strlen(maze[i + 1]);
	if (len_bottom_line == 0 || len_bottom_line - 1 < j)
	{
		if (is_not_wall_or_space(maze[i][j + 1]))
			return (FALSE);
		return (TRUE);
	}
	if (is_not_wall_or_space(maze[i + 1][j])
	|| is_not_wall_or_space(maze[i][j + 1]))
		return (FALSE);
	return (TRUE);
}

int			is_closed_map(char **maze)
{
	size_t		j;
	size_t		i;

	if (maze == NULL)
		return (ERROR);
	i = 0;
	while (maze[i] != NULL)
	{
		j = 0;
		while (maze[i][j] != '\0')
		{
			if (is_not_wall_or_space(maze[i][j]) == TRUE)
			{
				if (is_edge(maze, i, j))
					return (FALSE);
				if (check_walls(maze, i, j) != TRUE)
					return (FALSE);
			}
			if (ft_isspace(maze[i][j]) == TRUE)
			{
				if (check_walls_or_space(maze, i, j) == FALSE)
					return (FALSE);
			}
			j++;
		}
		i++;
	}
	return (TRUE);
}
