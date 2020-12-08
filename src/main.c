/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:08:09 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/08 20:38:28 by gdrive           ###   ########.fr       */
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


void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	finish_game(t_mlx_data *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

/*
** Обработчик клавиш.
*/


int		handle_key(int keycode, t_game_data *game_data)
{
	if (keycode == ESC)
		finish_game(&game_data->mlx_data);
	if (keycode == W)
		game_data->keys.w = 1;
	if (keycode == S)
		game_data->keys.s = 1;
	if (keycode == A)
		game_data->keys.a = 1;
	if (keycode == D)
		game_data->keys.d = 1;
	return (0);
}

int		handle_key_zero(int keycode, t_game_data *game_data)
{
	if (keycode == ESC)
		finish_game(&game_data->mlx_data);
	if (keycode == W)
		game_data->keys.w = 0;
	if (keycode == S)
		game_data->keys.s = 0;
	if (keycode == A)
		game_data->keys.a = 0;
	if (keycode == D)
		game_data->keys.d = 0;
	return (0);
}

/*
int		is_player(char c)
{
	return (c == 'N' || c == 'S' ||c == 'E' ||c == 'W');
}
*/

int		main(int argc, char **argv)
{
	/*
	** Сделать вывод ошибок во 2-ой поток !
	** Убрать printf в функции print(parse_map).
	*/

	if (argc < 2)
	{
		write(1, "no arguments!\n", 14);
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

	//t_player	player;
	//t_mlx_data	mlx_data;
	//t_img_data	img_data;

	init_game_space(&game_data);


	/*
	** =========================================================================
	**                            Бесконечный цикл
	** =========================================================================
	*/

	 //raycasting_render(&game_data);

	//mlx_key_hook(game_data.mlx_data.win, handle_key, &game_data);
	mlx_do_key_autorepeatoff(game_data.mlx_data.mlx);
	mlx_hook(game_data.mlx_data.win, 2, 0, handle_key, &game_data);
	mlx_hook(game_data.mlx_data.win, 3, 0, handle_key_zero, &game_data);
	mlx_loop_hook(game_data.mlx_data.mlx, raycasting_render, &game_data);
	mlx_loop(game_data.mlx_data.mlx);

	/*
	** =========================================================================
	** =========================================================================
	** =========================================================================
	*/



	game_data.map.clear(&game_data.map);
	return (0);
}
