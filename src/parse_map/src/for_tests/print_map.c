#include <stdio.h>
#include "parse_map_config.h"

void 	print_map(t_map *map)
{
	printf("\n~~~~~~~~~~~~~~~~~ MAP CONFIG ~~~~~~~~~~~~~~~~~\n\n");

	printf("r: %zu	%zu\n", map->r[0], map->r[1]);
	printf("\nno: %s\n", map->no);
	printf("so: %s\n", map->so);
	printf("we: %s\n", map->we);
	printf("ea: %s\n", map->ea);
	printf("s: %s\n", map->s);
	printf("f: %lld\n", map->f);
	printf("c: %lld\n", map->c);

	printf("\n.................... MAP .....................\n\n");

	size_t	i = 0;
	while(map->map[i] != NULL)
	{
		printf("|%s|\n", map->map[i]);
		i++;
	}

	printf("\n..............................................\n\n");
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
}
