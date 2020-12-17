/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:08:09 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/17 17:52:41 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include "mlx.h"
#include "libft.h"
#include "new_map.h"
#include "cub3D.h"

#include "game_engine.h"

int		main(int argc, char **argv)
{
	/*
	** Убрать printf в функции print(parse_map).
	*/

	t_game		game;

	if (argc < 2)
	{
		write(2, "ERROR: no arguments!\n", 21);
		exit(0);
	}
	new_map(&game.map);
	if (game.map.parse_file(argv[1], &game.map) == ERROR)
		exit(-1);
	start_game(&game);
	game.map.clear(&game.map);
	return (0);
}
