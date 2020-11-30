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

#include "parse_map_config.h"
#include "parse_identifier.h"
#include "libft.h"

static int		parse_technical(t_arrstrs params, t_map *map)
{
	if (params.len == 3 && is_resolution(params.arr[0]))
	{
		if (map->r[0] != 0 || map->r[1] != 0)
			return (ERROR);
		if ((parse_resolution(params, map)) == ERROR)
			return (ERROR);
		return (TRUE);
	}
	if (params.len == 2 && is_floor_color(params.arr[0]))
	{
		if (map->f != -1)
			return (ERROR);
		if ((parse_floor_color(params, map)) == ERROR)
			return (ERROR);
		return (TRUE);
	}
	if (params.len == 2 && is_ceiling_color(params.arr[0]))
	{
		if (map->c != -1)
			return (ERROR);
		if ((parse_ceiling_color(params, map)) == ERROR)
			return (ERROR);
		return (TRUE);
	}
	return (FALSE);
}

static int		parse_textures_part1(t_arrstrs params, t_map *map)
{
	if (params.len == 2 && is_north(params.arr[0]))
	{
		if (map->no != NULL)
			return (ERROR);
		if ((map->no = ft_strdup(params.arr[1])) == NULL)
			return (ERROR);
		return (TRUE);
	}
	if (params.len == 2 && is_south(params.arr[0]))
	{
		if (map->so != NULL)
			return (ERROR);
		if ((map->so = ft_strdup(params.arr[1])) == NULL)
			return (ERROR);
		return (TRUE);
	}
	if (params.len == 2 && is_west(params.arr[0]))
	{
		if (map->we != NULL)
			return (ERROR);
		if ((map->we = ft_strdup(params.arr[1])) == NULL)
			return (ERROR);
		return (TRUE);
	}
	return (FALSE);
}

static int		parse_textures_part2(t_arrstrs params, t_map *map)
{
	if (params.len == 2 && is_east(params.arr[0]))
	{
		if (map->ea != NULL)
			return (ERROR);
		if ((map->ea = ft_strdup(params.arr[1])) == NULL)
			return (ERROR);
		return (TRUE);
	}
	if (params.len == 2 && is_sprite(params.arr[0]))
	{
		if (map->s != NULL)
			return (ERROR);
		if ((map->s = ft_strdup(params.arr[1])) == NULL)
			return (ERROR);
		return (TRUE);
	}
	return (FALSE);
}

int				parse_identifier(t_arrstrs params, t_map *map)
{
	int		status;

	status = parse_technical(params, map);
	if (status == FALSE)
		status = parse_textures_part1(params, map);
	if (status == FALSE)
		status = parse_textures_part2(params, map);
	return (status);
}
