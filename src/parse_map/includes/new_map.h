/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:00:19 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/27 19:00:20 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEW_MAP_H
# define NEW_MAP_H

# include <stdlib.h>
# include <stdint.h>

# ifndef ERROR
#  define ERROR -1
# endif

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
# define FALSE 0
# endif

typedef struct			s_arrstrs
{
	char			**arr;
	size_t			len;
}				t_arrstrs;

/*
** Struct s_map has all needs configurations and  maze.
** 
** r - resolution of dispaly (r[0] = x, r[1] = y).
** no - way for north texture.
** so - way for south texture.
** ea - way for east texture.
** we - way for west texture.
** f - color for floor.
** c - color for ceiling.

** parse_file - takes configurations from file.cub and checks errors.
** clear - free all, that was allocated.
** scan_error - check the map for errors.
*/

typedef	struct			s_map
{
	size_t				r[2];
	char				*no;
	char				*so;
	char				*ea;
	char				*we;
	char				*s;
	int64_t				f;
	int64_t				c;
	char				**map;
	int				(*parse_file)(char *file, struct s_map *map);
	int				(*clear)(struct s_map *map);
	int				(*scan_error)(struct s_map *map);
	void				(*print)(struct s_map *map);
}					t_map;

void					new_map(t_map *map);
int					parse_map_config(char *file, t_map *map);
void					init_zero_map(t_map *map);
int					free_map(t_map *map);

#endif
