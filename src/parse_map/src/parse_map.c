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

#include <unistd.h>
#include "parse_map.h"
#include "parse_identifier.h"
#include "file_work.h"
#include "get_next_line.h"
#include "libft.h"
#include "for_tests.h"

int			parse_line(t_str line, t_map *map)
{
	t_arrstrs 	params;
	int 		status;

	// If is not map:
	// Norminette for libft
	if ((params.arr = ft_split((const char*)line.s, ' ')) == NULL)
		return (ERROR);

	params.len = ft_arrstrs_len(params.arr);
	status = parse_identifier(params, map);

	free_arrstrs(params.arr);
	return (status);
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
		write(1, "Error: not valid map.\n", 22);
		return (ERROR);
	}

	free(line.s);
	print_map(map);
	free_map(map);
	return (OK);
}
