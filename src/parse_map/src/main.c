//
// Created by Gueren Drive on 11/27/20.
//

#include <unistd.h>
#include "parse_map.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "ERROR: no arguments\n", 21);
			return (-1);
    }

	t_map	map;

	parse_map(argv[1], &map);

	return (0);
}
