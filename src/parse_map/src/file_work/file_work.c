/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 19:08:13 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/29 19:08:18 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "parse_map_config.h"

int		ft_read_open(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		return (ERROR);
	}
	return (fd);
}

int		ft_close(int fd, char *file)
{
	if (close(fd) < 0)
	{
		perror(file);
		return (ERROR);
	}
	return (TRUE);
}
