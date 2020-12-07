/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:08:09 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/04 18:43:16 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include "mlx.h"
#include "cub3D.h"
#include "new_map.h"
#include "libft.h"


void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	finish_game(t_mlx_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

/*
** Обработчик клавиш.
*/

#define ESC 53

int		handle_key(int keycode, t_mlx_vars *mlx_vars)
{
	if (keycode == ESC)
		finish_game(mlx_vars);
	return (0);
}

int		is_player(char c)
{
	return (c == 'N' || c == 'S' ||c == 'E' ||c == 'W');
}

/*
** Отрисовывание карты, вид сверху.
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

	t_map	map;
	char	**maze;

	new_map(&map);
	map.parse_file(argv[1], &map);
	//map.print(&map);
	maze = map.map;

	/*
	** Определение начальной позиции и направления взгяда игрока.
	** Определение плоскости камеры.
	*/
	t_player	player;

	size_t		i = 0;
	size_t		j = 0;

	char		status = FALSE;

	while (maze[i] != NULL)
	{
		j = 0;
		while (maze[i][j] != '\0')
		{
			if (is_player(maze[i][j]) == TRUE)
			{
				player.view = maze[i][j];
				status = TRUE;
				break ;
			}
			j++;
		}
		if (status == TRUE)
			break ;
		i++;
	}
	player.pos_y = i;
	player.pos_x = j;
	printf("start player position:\nplayer.x = %f	player.y = %f\n", player.pos_x, player.pos_y);

	// Пока по умалчанию смотрит на west.
	player.dir_x = -1;
	player.dir_y = 0;

	// Плоскость камеры

	double	plane_x = 0;
	double	plane_y = 0.66;

	/*
	** Создание окна.
	*/

	size_t		win_x;
	size_t		win_y;
	t_mlx_vars	mlx_vars;

	mlx_vars.mlx = mlx_init();
	if (mlx_vars.mlx == NULL)
	{
		write(1, "ERROR: can't init mlx\n", 22);
		exit(0);
	}
	win_x = map.r[0];
	win_y = map.r[1];
	mlx_vars.win = mlx_new_window(mlx_vars.mlx, win_x, win_y, "MyGame!");
	if (mlx_vars.win == NULL)
	{
		write(2, "ERROR: can't create window\n", 27);
		exit(0);
	}

	/*
	** Создание изображения.
	*/

	t_img_data		img_data;

	img_data.img = mlx_new_image(mlx_vars.mlx, map.r[0], map.r[1]);
	img_data.addr = mlx_get_data_addr(img_data.img, &img_data.bits_per_pixel, &img_data.line_lenght, &img_data.endian);

	/*
	** =========================================================================
	**                            Бесконечный цикл
	** =========================================================================
	*/
	i = 0;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	while (i < map.r[0])
	{
		// Вычисление местоположения луча.
		camera_x = 2 * (map.r[0] - i) / (double)(map.r[0]) - 1; // x координата на плоскости камеры
		ray_dir_x = player.dir_x + plane_x * camera_x;
		ray_dir_y = player.dir_y + plane_y * camera_x;

		// Изначальня позиция.
		int		map_x = (int)player.pos_x;
		int		map_y = (int)player.pos_y;

		// Длинна луча из текущей до ближайшей x или y-стороны.
		double	side_dist_x;
		double	side_dist_y;

		// Длина луча из одной x или y-стороны до следующей.
		double	delta_dist_x = fabs(1 / ray_dir_x);
		double	delta_dist_y = fabs(1 / ray_dir_y);
		double	perp_wall_dist;

		int		step_x;
		int		step_y;

		int		hit = 0;
		int		side;

		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (player.pos_x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - player.pos_x) * delta_dist_x;
		}

		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (player.pos_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - player.pos_y) * delta_dist_y;
		}
		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;

			}
			if (maze[map_y][map_x] == '1')
				hit = 1;
		}

		if (side == 0)
			perp_wall_dist = (map_x - player.pos_x + (1 - step_x) / 2) / ray_dir_x;
		else
			perp_wall_dist = (map_y - player.pos_y + (1 - step_y) / 2) / ray_dir_y;

		int		line_height = (int)(map.r[1] / perp_wall_dist);
		printf("line_height = %d\n", line_height);

		int		draw_start = -line_height / 2 + map.r[1] / 2;

		printf("draw_start = %d\n", draw_start);

		if (draw_start < 0)
			draw_start = 0;

		int		draw_end = line_height / 2 + map.r[1] / 2;
		printf("draw_end = %d\n", draw_end);

		if (draw_end >= map.r[1])
			draw_end = map.r[1] - 1;

		size_t	m = draw_start;
		while (m <= draw_end)
		{
			my_mlx_pixel_put(&img_data, i, m, 0xFF0000);
			m++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx_vars.mlx, mlx_vars.win, img_data.img, 0, 0);
	mlx_key_hook(mlx_vars.win, handle_key, &mlx_vars);
	mlx_loop(mlx_vars.mlx);
	/*
	** =========================================================================
	** =========================================================================
	** =========================================================================
	*/



	map.clear(&map);
	return (0);
}
