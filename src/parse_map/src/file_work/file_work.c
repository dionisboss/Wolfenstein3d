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
#include "new_map.h"
#include "libft.h"

static int		check_dot_cub(char *file)
{
	size_t	len;

	if (file == NULL)
		return (FALSE);
	len = ft_strlen(file);
	if (len < 4)
	{
		write(2, "ERROR: not valid map\n", 21);
		return (FALSE);
	}
	while (len-- != 0)
	{
		if (file[len] == '.')
		{
			if (ft_strcmp(file + len, ".cub") == 0)
				return (TRUE);
		}
	}
	write(2, "ERROR: not valid map\n", 21);
	return (FALSE);
}

int				ft_read_open(char *file)
{
	int	fd;

	if (check_dot_cub(file) == FALSE)
		return (ERROR);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		return (ERROR);
	}
	return (fd);
}

int				ft_close(int fd, char *file)
{
	if (close(fd) < 0)
	{
		perror(file);
		return (ERROR);
	}
	return (TRUE);
}
