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

#include "parse_map_config.h"
#include "libft.h"

int					parse_resolution(t_arrstrs params, t_map *map)
{
	if (!ft_is_digitsn(params.arr[1], 0) || !ft_is_digitsn(params.arr[2], 0))
		return (ERROR);
	if (ft_nbcmp(params.arr[1], "5120") >= 0)
		map->r[0] = 5120;
	if (ft_nbcmp(params.arr[2], "2880") >= 0)
		map->r[1] = 2880;
	if (map->r[0] == 0)
		map->r[0] = ft_atoi(params.arr[1]);
	if (map->r[1] == 0)
		map->r[1] = ft_atoi(params.arr[2]);
	return (TRUE);
}

static int			check_color_error(t_arrstrs *colors)
{
	char	*nb1;
	char	*nb2;
	char	*nb3;

	if ((colors->len = ft_arrstrs_len(colors->arr)) != 3)
		return (free_arrstrs(&colors->arr) - 1);
	nb1 = colors->arr[0];
	nb2 = colors->arr[1];
	nb3 = colors->arr[2];
	if (!ft_is_digitsn(nb1, 0) || !ft_is_digitsn(nb2, 0))
		return (free_arrstrs(&colors->arr) - 1);
	if (!ft_is_digitsn(nb3, 0))
		return (free_arrstrs(&colors->arr) - 1);
	if (ft_nbcmp(nb1, "255") > 0 || ft_nbcmp(nb2, "255") > 0)
		return (free_arrstrs(&colors->arr) - 1);
	if (ft_nbcmp(nb3, "255") > 0)
		return (free_arrstrs(&colors->arr) - 1);
	return (TRUE);
}

static uint64_t		rgb_to_dec(char *nb1, char *nb2, char *nb3)
{
	size_t	n1;
	size_t	n2;
	size_t	n3;

	n1 = ft_atoi(nb1);
	n2 = ft_atoi(nb2);
	n3 = ft_atoi(nb3);
	return (n1 * 65536 + n2 * 256 + n3);
}

int					parse_floor_color(t_arrstrs params, t_map *map)
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
	map->f = rgb_to_dec(colors.arr[0], colors.arr[1], colors.arr[2]);
	free_arrstrs(&colors.arr);
	return (TRUE);
}

int					parse_ceiling_color(t_arrstrs params, t_map *map)
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
		return (free_arrstrs(&colors.arr) - 1);
	map->c = rgb_to_dec(colors.arr[0], colors.arr[1], colors.arr[2]);
	free_arrstrs(&colors.arr);
	return (TRUE);
}
