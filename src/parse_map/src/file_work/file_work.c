#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "parse_map.h"

int		ft_read_open(char *file)
{
	int	fd;

	fd  = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		return (ERROR);
	}
	return (fd);
}

int 	ft_close(int fd, char *file)
{
	if (close(fd) < 0)
	{
		perror(file);
		return (ERROR);
	}
	return (OK);
}
