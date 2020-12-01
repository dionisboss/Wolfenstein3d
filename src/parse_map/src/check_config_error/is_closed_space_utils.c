/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_closed_space_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:05:35 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/01 15:05:36 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_map.h"
#include "libft.h"

int		is_north_end(char **maze, size_t x, size_t y)
{
	static size_t	save_y;

	while (maze[y][x] != '\0')
	{
		if (ft_strchr("012NSEW", maze[y][x]))
		{
			save_y = y;
			return (TRUE);
		}
		x++;
	}
	return (TRUE);
}