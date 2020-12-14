/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:08:09 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/14 19:02:29 by gdrive           ###   ########.fr       */
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
	** Проверить обработку ошибок.
	** Сделать вывод ошибок во 2-ой поток !
	** Убрать printf в функции print(parse_map).
	** ИСПРАВИТЬ ПАРС:     1
	**                   101
	**                    1
	*/

	if (argc < 2)
	{
		write(2, "no arguments!\n", 14);
		exit(0);
	}

	/*
	** Создание карты.
	*/

	t_game_data		game_data;

	new_map(&game_data.map);
	game_data.map.parse_file(argv[1], &game_data.map);

	//map.print(&map);
	//maze = game_data.map.map;
	start_game(&game_data);
	game_data.map.clear(&game_data.map);
	return (0);
}
