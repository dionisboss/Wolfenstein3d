/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arr_of_sprites.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 10:28:09 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/17 19:58:10 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game_engine.h"

int						free_sprites(t_double_vector ***sprites)
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

static size_t			count_sprites(char **maze)
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

static void				init_element(t_double_vector **sprites,
		double i, double j, size_t num_sprite)
{
	sprites[num_sprite] = (t_double_vector*)malloc(sizeof(t_double_vector));
	if (sprites[num_sprite] == NULL)
	{
		free_sprites(&sprites);
		exit(-1);
	}
	sprites[num_sprite]->y = (double)i + 0.5;
	sprites[num_sprite]->x = (double)j + 0.5;
}

static void				write_array(t_double_vector **sprites, char **maze)
{
	size_t	i;
	size_t	j;
	size_t	num_sprite;

	i = -1;
	j = 0;
	num_sprite = 0;
	while (maze[++i] != NULL)
	{
		j = 0;
		while (maze[i][j] != '\0')
		{
			if (maze[i][j] == '2')
			{
				init_element(sprites, i, j, num_sprite);
				num_sprite++;
			}
			j++;
		}
	}
}

void					init_arr_sprites(t_game *game)
{
	t_map			*map;
	char			**maze;
	t_double_vector	**sprites;
	size_t			num_sprites;

	map = &game->map;
	maze = game->map.map;
	num_sprites = count_sprites(map->map);
	sprites = (t_double_vector**)malloc(sizeof(t_double_vector*) *
			(num_sprites + 1));
	if (sprites == NULL)
		exit(-1);
	sprites[num_sprites] = NULL;
	write_array(sprites, maze);
	game->sprites.sprites = sprites;
	game->sprites.num_sprites = num_sprites;
}
