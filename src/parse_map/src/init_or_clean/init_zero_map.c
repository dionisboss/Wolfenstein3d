/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_zero_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 21:06:59 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/27 21:07:00 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map_config.h"

void	init_zero_map(t_map *map)
{
	map->r[0] = 0;
	map->r[1] = 0;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->s = NULL;
	map->f = -1;
	map->c = -1;
	map->map = NULL;
	return ;
}
