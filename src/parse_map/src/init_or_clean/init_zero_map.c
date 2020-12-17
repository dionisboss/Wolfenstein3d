/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_zero_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 21:06:59 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/17 17:59:44 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map_config.h"
#include "check_config_error.h"
#include "for_tests.h"

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
	map->parse_file = &parse_map_config;
	map->clear = &free_map;
	map->scan_error = &scan_map_error;
	return ;
}
