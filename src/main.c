/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:08:09 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/21 20:10:23 by gdrive           ###   ########.fr       */
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
	return (argc > 1);
}

static int		check_save_flag(int argc, char **argv)
{
	int		diff;

	if (argc < 3)
		return (false);
	else
		diff = ft_strcmp(argv[2], "--save");
	if (diff == 0)
		return (true);
	else
		return (false);
}

static void		args_error_exit(void)
{
	write(2, "ERROR: no arguments!\n", 21);
	exit(-1);
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
