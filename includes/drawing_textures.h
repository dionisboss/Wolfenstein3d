/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_textures.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 19:42:04 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/17 18:34:06 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWING_TEXTURES_H
# define DRAWING_TEXTURES_H
# include <stdint.h>
# include "game_engine.h"

typedef struct		s_tex_draw_vars
{
	t_texture		*tex;
	int				tex_num;
	double			wall_x;
	int				tex_x;
	double			step;
	double			tex_pos;
	uint32_t		color;
	int				tex_y;
}					t_tex_draw_vars;

#endif
