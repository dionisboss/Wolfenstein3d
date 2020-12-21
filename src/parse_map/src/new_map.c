/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:02:36 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/21 22:40:29 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Function inits struct s_map with default values.
** Function does not use malloc();
*/

#include "new_map.h"

int		new_map(t_map *map)
{
	init_zero_map(map);
	return (0);
}
