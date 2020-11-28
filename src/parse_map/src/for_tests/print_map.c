#include <stdio.h>
#include "parse_map.h"

void 	print_map(t_map *map)
{
	printf("\n~~~~~~~~~~~~~~~~~ MAP ~~~~~~~~~~~~~~~~~\n\n");

	printf("r: %zu	%zu\n", map->r[0], map->r[1]);
	printf("\nno: %s\n", map->no);
	printf("so: %s\n", map->so);
	printf("we: %s\n", map->we);
	printf("ea: %s\n", map->ea);
	printf("s: %s\n", map->s);
	printf("f: %llu\n", map->f);
	printf("c: %llu\n", map->c);



	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
}
