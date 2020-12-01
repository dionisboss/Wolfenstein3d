/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_full_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:53:49 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/30 14:53:50 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_map.h"

int		is_full_config(t_map *map)
{
	int		status;

	status = TRUE;
	if (map->r[0] == 0 || map->r[1] == 0)
		status = FALSE;
	else if (map->no == NULL || map->so == NULL)
		status = FALSE;
	else if (map->ea == NULL || map->we == NULL)
		status = FALSE;
	else if ( map->s == NULL)
		status = FALSE;
	else if (map->r[0] == 0 || map->r[1] == 0)
		status = FALSE;
	else if (map->r[0] == 0 || map->r[1] == 0)
		status = FALSE;
	else if (map->r[0] == 0 || map->r[1] == 0)
		status = FALSE;
	return (status);
}
