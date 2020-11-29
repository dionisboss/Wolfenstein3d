/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:15:30 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/27 19:15:31 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"

int		free_arrstrs(char **arrstrs)
{
	size_t	i;

	if (arrstrs == NULL)
		return (OK);
	i = 0;
	while (arrstrs[i] != NULL)
	{
		free(arrstrs[i]);
		arrstrs[i] = NULL;
		i++;
	}
	free(arrstrs);
	arrstrs = NULL;
	return (OK);
}
