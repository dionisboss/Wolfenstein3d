//
// Created by Gueren Drive on 11/27/20.
//

#include <unistd.h>
#include "new_map.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "ERROR: no arguments\n", 21);
			return (-1);
    }

	t_map	map;

	new_map(&map);
	if ((map.parse_file(argv[1], &map)) == ERROR)
	{
		write(1, "ERROR: can't parse file\n", 24);
		return (0);
	}
	map.print(&map);
	map.clear(&map);

	return (0);
}
