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

#ifndef PARSE_MAP_CONFIG_H
# define PARSE_MAP_CONFIG_H

# include <stdlib.h>
# include <stdint.h>

# define ERROR -1
# define TRUE 1
# define FALSE 0

typedef	struct			s_map
{
	size_t				r[2];
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	char				*s;
	int64_t				f;
	int64_t				c;
	char				**map;
}						t_map;

typedef struct			s_arrstrs
{
	char				**arr;
	size_t				len;
}						t_arrstrs;

int						parse_map_config(char *file, t_map *map);

void					init_zero_map(t_map *map);
int						free_map(t_map *map);

#endif
