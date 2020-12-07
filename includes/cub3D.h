/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:45:09 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/05 19:45:11 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

# define ESC 53

/*
**	Необходимые данные для построки изображения.
*/

typedef	struct			s_img_data
{
	void				*img;
	void				*addr;
	int					bits_per_pixel;
	int					line_lenght;
	int					endian;
}						t_img_data;

/*
**	Необходимы данные для рабты с окном.
*/

typedef struct			s_mlx_vars
{
	void				*mlx;
	void				*win;
}						t_mlx_vars;

/*
**	Местоположение игрока.
*/

typedef struct			s_player
{
	double				pos_x;
	double 				pos_y;
	double				dir_x;
	double				dir_y;
	char				view;
}						t_player;

/*
**	Флаги клавишь клавиатуры. Значение 1 - нажата, 0 - нет.
*/

typedef struct			s_keys_flags
{
	char				esc_f;
}						t_keys_flags;

#endif
