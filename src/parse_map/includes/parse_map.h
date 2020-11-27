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

#ifndef PARSE_MAP_H
#define PARSE_MAP_H

# include <stdlib.h>
# include <stdint.h>

# define ERROR -1
# define OK 1
# define NO 0

typedef struct          s_map
{
    size_t              r[2];
    char                *no;
    char                *so;
    char                *we;
    char                *ea;
	char                *s;
	char                **map;
}                       t_map;

typedef struct			s_arrstrs
{
	char 				**arr;
	size_t 				len;
}						t_arrstrs;

int                     parse_map(char *file, t_map *map);

void					init_zero_map(t_map *map);
int 					free_split(t_arrstrs *arrstrs);
int						free_map(t_map *map);

int						is_north(char *s);
int						is_south(char *s);
int						is_west(char *s);
int						is_east(char *s);
int						is_sprite(char *s);
int						is_resolution(char *s);
int						is_floorcolor(char *s);
int						is_ceilingcolor(char *s);

int						ft_read_open(char *file);
int 					ft_close(int fd, char *file);

int 					parse_identifier(t_arrstrs params, t_map *map);

#endif
