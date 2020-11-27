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

int 		free_split(t_arrstrs *arrstrs)
{
	size_t	i;

	if (arrstrs == NULL)
		return (OK);
	i = 0;
	while (arrstrs->arr[i] != NULL)
	{
		free(arrstrs->arr[i]);
		arrstrs->arr[i] = NULL;
		i++;
	}
	free(arrstrs->arr);
	arrstrs->arr = NULL;
	return (OK);
}
