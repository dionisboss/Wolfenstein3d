/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_screenshot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 13:23:27 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/21 14:38:25 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "game_engine.h"

int		create_clean_file(const char *name)
{
	int		fd;

	fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (fd < 0)
		write(2, "ERROR: can't create file\n", 25);
	return (fd);
}

void	do_screenshot(t_game *game)
{
	int		fd;

	init_game_space(game);
	raycasting_render(game);
	fd = create_clean_file("screenshot.bmp");
	if (fd < 0)
		exit(-1);
	
	write(fd, "BM", 2);
}
