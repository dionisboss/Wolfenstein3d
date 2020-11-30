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

#include "parse_map_config.h"
#include "libft.h"

int			is_resolution(const char *s)
{
	if (s == NULL)
		return (FALSE);
	return (!ft_strcmp(s, "R"));
}

int			is_floor_color(const char *s)
{
	if (s == NULL)
		return (FALSE);
	return (!ft_strcmp(s, "F"));
}

int			is_ceiling_color(const char *s)
{
	if (s == NULL)
		return (FALSE);
	return (!ft_strcmp(s, "C"));
}
