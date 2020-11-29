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

int			is_north(const char *s)
{
	if (s == NULL)
		return (NO);
	return (!ft_strcmp(s, "NO"));
}

int			is_south(const char *s)
{
	if (s == NULL)
		return (NO);
	return (!ft_strcmp(s, "SO"));
}

int			is_west(const char *s)
{
	if (s == NULL)
		return (NO);
	return (!ft_strcmp(s, "WE"));
}

int			is_east(const char *s)
{
	if (s == NULL)
		return (NO);
	return (!ft_strcmp(s, "EA"));
}

int			is_sprite(const char *s)
{
	if (s == NULL)
		return (NO);
	return (!ft_strcmp(s, "S"));
}
