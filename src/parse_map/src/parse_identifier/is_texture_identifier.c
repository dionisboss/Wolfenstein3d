/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_identifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:03:04 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/27 18:03:05 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"
#include "libft.h"

int			is_north(char *s)
{
	if (ft_strlen(s) != 2)
		return (NO);
	return (!ft_memcmp(s, "NO", 2));
}

int			is_south(char *s)
{
	if (ft_strlen(s) != 2)
		return (NO);
	return (!ft_memcmp(s, "SO", 2));
}
int			is_west(char *s)
{
	if (ft_strlen(s) != 2)
		return (NO);
	return (!ft_memcmp(s, "WE", 2));
}
int			is_east(char *s)
{
	if (ft_strlen(s) != 2)
		return (NO);
	return (!ft_memcmp(s, "EA", 2));
}
int			is_sprite(char *s)
{
	if (ft_strlen(s) != 1)
		return (NO);
	return (!ft_memcmp(s, "S", 1));
}

