/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arr_of_sprites.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 10:28:09 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/17 17:38:15 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game_engine.h"

int			free_sprites(t_double_vector ***sprites)
{
	size_t	i;

	if (sprites == NULL)
		return (0);
	if (*sprites == NULL)
		return (0);
	i = 0;
	while ((*sprites)[i] != NULL)
	{
		free((*sprites)[i]);
		(*sprites)[i] = NULL;
		i++;
	}
	free(*sprites);
	*sprites = NULL;
	return (0);
}

/*
** Counting number of sprites.
*/

static size_t		count_double_vectors(char **maze)
{
	size_t	i;
	size_t	j;
	size_t	num_sprites;

	i = 0;
	j = 0;
	num_sprites = 0;
	if (maze == NULL)
		return (num_sprites);
	while (maze[i] != NULL)
	{
		j = 0;
		while (maze[i][j] != '\0')
		{
			if (maze[i][j] == '2')
			{
				num_sprites++;
			}
			j++;
		}
		i++;
	}
	return (num_sprites);
}

/*
** Init array of sprites.
*/

static void		write_array(t_double_vector **sprites, char **maze)
{
	size_t	i;
	size_t	j;
	size_t	num_sprite;

	i = 0;
	j = 0;
	num_sprite = 0;;
	while (maze[i] != NULL)
	{
		j = 0;
		while (maze[i][j] != '\0')
		{
			if (maze[i][j] == '2')
			{
				sprites[num_sprite] = (t_double_vector*)malloc(sizeof(t_double_vector));
				if (sprites[num_sprite] == NULL)
				{
					free_sprites(&sprites);
					exit(-1);
				}
				sprites[num_sprite]->y = (double)i + 0.5;
				sprites[num_sprite]->x = (double)j + 0.5;
				num_sprite++;
			}
			j++;
		}
		i++;
	}
}

void			init_arr_sprites(t_game *game_data)
{
	t_map		*map;
	char		**maze;
	t_double_vector	**sprites;
	size_t		num_sprites;

	map = &game_data->map;
	maze = game_data->map.map;
	num_sprites = count_double_vectors(map->map);
	sprites = (t_double_vector**)malloc(sizeof(t_double_vector*) * (num_sprites + 1));
	if (sprites == NULL)
		exit(-1);
	sprites[num_sprites] = NULL;
	write_array(sprites, maze);
	game_data->sprites.sprites = sprites;
	game_data->sprites.num_sprites = num_sprites;
}
