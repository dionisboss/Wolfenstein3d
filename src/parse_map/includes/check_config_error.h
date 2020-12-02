/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_config_error.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:57:36 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/30 14:57:37 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_CONFIG_ERROR_H
# define CHECK_CONFIG_ERROR_H
# include "new_map.h"

int		is_full_config(t_map *map);

int		scan_map_error(t_map *map);
int		check_map_empty_line(char *s);

int		is_closed_map(char **maze);

#endif
