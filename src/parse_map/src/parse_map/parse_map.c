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

#include "parse_map_config.h"
#include "get_next_line.h"
#include "libft.h"

int		parse_map(t_str *line, t_map *map)
{
	//NEED SCAN
	if (ft_arrstrs_addback(&(map->map), ft_strdup(line->s)) == NULL)
		return (ERROR);
	return (TRUE);
}
