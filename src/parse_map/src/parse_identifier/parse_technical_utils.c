/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_technical_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:37:58 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/28 16:37:59 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"
#include "libft.h"

int 		parse_resolution(t_arrstrs params, t_map *map)
{
	size_t 		i;

	if (!ft_is_digitsn(params.arr[1],0) || !ft_is_digitsn(params.arr[2], 0))
		return (ERROR);
	i = 0;
	if (ft_nbcmp(params.arr[1], "5120") >= 0)
		map->r[0] = 5120;
	if (ft_nbcmp(params.arr[2], "2880") >= 0)
		map->r[1] = 2880;
	if (map->r[0] == 0)
		map->r[0] = ft_atoi(params.arr[1]);
	if (map->r[1] == 0)
		map->r[1] = ft_atoi(params.arr[2]);
	return (OK);
}

static int 	check_color_error(t_arrstrs *colors)
{
	if ((colors->len = ft_arrstrs_len(colors->arr)) != 3)
		return (free_split(colors) - 2);
	// NEED CONTINUE
	return (OK);
}

int 		parse_floor_color(t_arrstrs params, t_map *map)
{
	size_t		i;
	size_t		comma_count;
	t_arrstrs	colors;

	i = 0;
	comma_count = 0;
	while (params.arr[1][i] != '\0')
	{
		if (ft_strchr(",", params.arr[1][i++]))
			comma_count++;

	}
	if (comma_count != 2)
		return (ERROR);
	if ((colors.arr = ft_split(params.arr[1], ',')) == NULL)
		return (ERROR);
	if (check_color_error(&colors) == ERROR)
		return (ERROR);

	return (OK);
}
