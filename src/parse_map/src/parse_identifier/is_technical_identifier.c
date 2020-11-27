/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_technical_identifier.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:45:41 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/27 22:45:42 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"
#include "libft.h"

int			is_resolution(char *s)
{
	if (ft_strlen(s) != 1)
		return (NO);
	return (!ft_memcmp(s, "R", 1));
}

int			is_floorcolor(char *s)
{
	if (ft_strlen(s) != 1)
		return (NO);
	return (!ft_memcmp(s, "F", 1));
}

int			is_ceilingcolor(char *s)
{
	if (ft_strlen(s) != 1)
		return (NO);
	return (!ft_memcmp(s, "C", 1));
}
