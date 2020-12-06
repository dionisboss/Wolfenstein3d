#include "new_map.h"

int	main(void)
{
	t_map	map;

	new_map(&map);
	map.parse_file("maps/subjectMap.cub", &map);
	map.print(&map);
	map.clear(&map);
	return (0);
}
