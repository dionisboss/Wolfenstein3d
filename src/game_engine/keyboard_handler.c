/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:55:27 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/17 19:58:15 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_engine.h"

int	handle_pressed_key(int keycode, t_game *game)
{
	if (keycode == ESC)
		finish_game(game);
	if (keycode == KEY_W)
		game->keys.w = 1;
	if (keycode == KEY_S)
		game->keys.s = 1;
	if (keycode == KEY_A)
		game->keys.a = 1;
	if (keycode == KEY_D)
		game->keys.d = 1;
	if (keycode == KEY_LEFT || keycode == KEY_Q)
		game->keys.q = 1;
	if (keycode == KEY_RIGHT || keycode == KEY_E)
		game->keys.e = 1;
	return (0);
}

int	handle_unpressed_key(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->keys.w = 0;
	if (keycode == KEY_S)
		game->keys.s = 0;
	if (keycode == KEY_A)
		game->keys.a = 0;
	if (keycode == KEY_D)
		game->keys.d = 0;
	if (keycode == KEY_LEFT || keycode == KEY_Q)
		game->keys.q = 0;
	if (keycode == KEY_RIGHT || keycode == KEY_E)
		game->keys.e = 0;
	return (0);
}
