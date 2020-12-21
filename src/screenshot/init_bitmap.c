/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bitmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:48:01 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/21 19:56:57 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_engine.h"

static void		set_zero_byts(void *dest, size_t len)
{
	unsigned char	*cdest;

	cdest = (unsigned char*)dest;
	while (len--)
	{
		*cdest = 0;
		cdest += 1;
	}
}

void			*init_bitmap54(t_game *game)
{
	static char		bitmap[54];

	set_zero_byts(bitmap, 54);
	bitmap[0] = 'B';
	bitmap[1] = 'M';
	*((int*)(bitmap + 2)) = game->map.r[0] * game->map.r[1] * 4 + 54;
	*(int*)(bitmap + 10) = 54;
	*(int*)(bitmap + 14) = 40;
	*(int*)(bitmap + 18) = (int)game->map.r[0];
	*(int*)(bitmap + 22) = (int)game->map.r[1];
	*(bitmap + 26) = 1;
	*(bitmap + 28) = 32;
	return ((void*)bitmap);
}
