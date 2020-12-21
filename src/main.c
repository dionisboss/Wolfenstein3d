/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:08:09 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/21 22:11:14 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include "mlx.h"
#include "libft.h"
#include "new_map.h"
#include "game_engine.h"

static int		check_args(int argc, char **argv)
{
	return (argc >= 2 && argc <= 3);
}

static void		args_error_exit(void)
{
	write(2, "ERROR: invalid arguments!\n", 26);
	exit(-1);
}

static int		check_save_flag(int argc, char **argv)
{
	int		diff;

	if (argc == 2)
		return (false);
	else
		diff = ft_strcmp(argv[2], "--save");
	if (diff == 0)
		return (true);
	else
		args_error_exit();
	return (false);
}

int				main(int argc, char **argv)
{
	t_game		game;

	if (check_args(argc, argv) == false)
		args_error_exit();
	else
		new_map(&game.map);
	if (game.map.parse_file(argv[1], &game.map) == ERROR)
		exit(-1);
	if (check_save_flag(argc, argv) == true)
		do_screenshot(&game);
	else
		start_game(&game);
	game.map.clear(&game.map);
	return (0);
}
