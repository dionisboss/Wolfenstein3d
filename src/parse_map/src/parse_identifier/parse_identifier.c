/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:51:44 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/27 18:51:45 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "parse_map.h"
#include "libft.h"
#include "parse_identifier.h"

static int 		parse_technical(t_arrstrs params, t_map *map)
{
	if (params.len == 3 && is_resolution(params.arr[0]))
	{
		if ((parse_resolution(params, map)) == ERROR)
			return (ERROR);
		return (OK);
	}
	if (params.len == 2 && is_floor_color(params.arr[0]))
	{
		if ((parse_floor_color(params, map)) == ERROR)
			return (ERROR);
		return (OK);
	}
	if (params.len == 2 && is_ceiling_color(params.arr[0]))
	{
		//map->c =
		return (OK);
	}
	return (NO);
}

static int		parse_textures(t_arrstrs params, t_map *map)
{
	if (params.len == 2 && is_north(params.arr[0]))
	{
		if ((map->no = ft_strdup(params.arr[1])) == NULL)
			return (ERROR);
		return (OK);
	}
	if (params.len == 2 && is_south(params.arr[0]))
	{
		if ((map->so = ft_strdup(params.arr[1])) == NULL)
			return (ERROR);
		return (OK);
	}
	if (params.len == 2 && is_west(params.arr[0]))
	{
		if ((map->we = ft_strdup(params.arr[1])) == NULL)
			return (ERROR);
		return (OK);
	}
	if (params.len == 2 && is_east(params.arr[0]))
	{
		if ((map->ea = ft_strdup(params.arr[1])) == NULL)
			return (ERROR);
		return (OK);
	}
	if (params.len == 2 && is_sprite(params.arr[0]))
	{
		if ((map->s = ft_strdup(params.arr[1])) == NULL)
			return (ERROR);
		return (OK);
	}
	return (NO);
}

int				parse_identifier(t_arrstrs params, t_map *map)
{
	int		status;

	status = parse_technical(params, map);
	if (status == NO)
		status = parse_textures(params, map);

	return (status);
}
