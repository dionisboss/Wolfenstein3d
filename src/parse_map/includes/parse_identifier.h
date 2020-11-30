/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifier.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:39:04 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/28 16:39:05 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_IDENTIFIER_H
# define PARSE_IDENTIFIER_H
# include <stdint.h>
# include "parse_map_config.h"

int				is_north(const char *s);
int				is_south(const char *s);
int				is_west(const char *s);
int				is_east(const char *s);
int				is_sprite(const char *s);
int				is_resolution(const char *s);
int				is_floor_color(const char *s);
int				is_ceiling_color(const char *s);
int				parse_identifier(t_arrstrs params, t_map *map);
int				parse_resolution(t_arrstrs params, t_map *map);
uint64_t		parse_floor_color(t_arrstrs params, t_map *map);
uint64_t		parse_ceiling_color(t_arrstrs params, t_map *map);

#endif
