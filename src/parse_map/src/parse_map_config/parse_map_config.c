/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_config.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:10:40 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/01 14:10:41 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdio.h>
#include "new_map.h"
#include "file_work.h"
#include "get_next_line.h"
#include "parse_identifier.h"
#include "parse_map.h"
#include "check_config_error.h"
#include "libft.h"

static void			cut_firsts_empty_lines(t_map *map)
{
	t_arrstrs	res;
	char		**tmp;

	tmp = map->map;
	while(check_map_empty_line(*tmp) == TRUE)
	{
		free(*tmp);
		tmp++;
	}
	res.len = ft_arrstrs_len(tmp);
	res.arr = (char**)malloc(sizeof(char*) * (res.len + 1));
	res.arr[res.len] = NULL;
	while (res.len-- != 0)
		res.arr[res.len] = tmp[res.len];
	free(map->map);
	map->map = res.arr;
}

static int			parse_line(t_str *line, t_map *map)
{
	t_arrstrs 	params;
	int 		status;

	if ((params.arr = ft_split((const char*)line->s, ' ')) == NULL)
		return (ERROR);

	params.len = ft_arrstrs_len(params.arr);
	status = parse_identifier(params, map);

	if (status == FALSE && is_full_config(map) == TRUE)
		status = parse_map(line, map);

	if (status == FALSE && params.len > 0)
		status = ERROR;

	free_arrstrs(&params.arr);
	return (status);
}

int					parse_map_config(char *file, t_map *map)
{
	//СДЕЛАТЬ ТЕСТ НА .cub !!!
	t_str	line;
	int		fd;
	int		status;

	status = (fd = ft_read_open(file));
	while (status != ERROR && ((status = get_next_line(fd, &line.s)) > 0))
	{
		if (status == ERROR)
			break ;
		status = parse_line(&line, map);
		free(line.s);
		line.s = NULL;
	}
	if (status != ERROR)
	{
		free(line.s);
		cut_firsts_empty_lines(map);
		status = map->scan_error(map);

	}
	if (ft_close(fd, file) == ERROR || status == ERROR)
	{
		map->clear(map);
		write(1, "Error: not valid map.\n", 22);
		return (ERROR);
	}
	return (TRUE);
}
