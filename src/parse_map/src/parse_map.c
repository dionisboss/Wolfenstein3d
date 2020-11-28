/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:02:36 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/27 18:02:37 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"
#include "get_next_line.h"
#include "libft.h"
#include "for_tests.h"
#include "parse_identifier.h"

int			parse_line(t_str line, t_map *map)
{
	t_arrstrs 	params;
	int 		status;

	if ((params.arr = ft_split((const char*)line.s, ' ')) == NULL)
		return (ERROR);
	params.len = ft_arrstrs_len(params.arr);
	status = OK;
	if ((status = parse_identifier(params, map)) == OK && status != ERROR)
		return (free_split(&params));
	if (status == ERROR)
	{
		free_split(&params);
		return (status);
	}
	return (free_split(&params));
}

int			parse_map(char *file, t_map *map)
{
	t_str	line;
	int		fd;
	int		status;

	if ((fd = ft_read_open(file)) == ERROR)
		return (ERROR);

	status = OK;
	init_zero_map(map);
	while (status != ERROR && ((status = get_next_line(fd, &line.s)) > 0))
	{
		if (parse_line(line, map) == ERROR)
			status = ERROR;
		free(line.s);
		line.s = NULL;
	}

	if (ft_close(fd, file) == ERROR || status == ERROR)
	{
		free_map(map);
		return (ERROR);
	}

	free(line.s);
	print_map(map);
	free_map(map);
	return (OK);
}
