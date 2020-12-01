/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 15:42:06 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/30 15:42:06 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_map.h"
#include "get_next_line.h"
#include "libft.h"

static int		scan_for_other_c(t_str *line)
{
	size_t			i;

	if (line == NULL || line->s == NULL)
		return (ERROR);
	i = 0;
	while (line->s[i] != '\0')
	{
		if (ft_strchr(" 012NSEW", line->s[i]) == NULL)
			return (ERROR);
		i++;
	}
	return (TRUE);
}

int				parse_map(t_str *line, t_map *map)
{
	if (scan_for_other_c(line) == ERROR)
		return (ERROR);
	if (ft_arrstrs_addback(&(map->map), ft_strdup(line->s)) == NULL)
		return (ERROR);
	return (TRUE);
}
