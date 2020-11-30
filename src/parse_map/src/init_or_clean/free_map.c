/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 21:01:16 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/27 21:01:17 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map_config.h"
#include "libft.h"

static void		free_textures(t_map *map)
{
	if (map->no != NULL)
	{
		free(map->no);
		map->no = NULL;
	}
	if (map->so != NULL)
	{
		free(map->so);
		map->so = NULL;
	}
	if (map->we != NULL)
	{
		free(map->we);
		map->we = NULL;
	}
	if (map->ea != NULL)
	{
		free(map->ea);
		map->ea = NULL;
	}
	if (map->s != NULL)
	{
		free(map->s);
		map->s = NULL;
	}
}

static void		zero_technical(t_map *map)
{
	map->r[0] = 0;
	map->r[1] = 0;
	map->f = -1;
	map->c = -1;
}

int				free_map(t_map *map)
{
	zero_technical(map);
	free_textures(map);
	free_arrstrs(&(map->map));
	return (TRUE);
}
