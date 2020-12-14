/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:09:47 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/14 18:29:50 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mlx.h"
#include "game_engine.h"

void	init_img_north_texture(void *mlx, t_textures *tex_data)
{
	t_tex_data		*no;
	t_img_data		*no_img;

	no = &tex_data->no;
	no_img = &no->img_data;
	no_img->img = mlx_xpm_file_to_image(mlx,
			no->relative_path, &no->width, &no->height);
	if (no_img->img == NULL)
	{
		write(1, "ERROR: mlx cant open norh texture\n", 34);
		exit(-1);
	}
	no_img->addr = mlx_get_data_addr(no_img->img,
			&no_img->bits_per_pixel, &no_img->line_lenght, &no_img->endian);
}

void	init_img_south_texture(void *mlx, t_textures *tex_data)
{
	t_tex_data		*so;
	t_img_data		*so_img;

	so = &tex_data->so;
	so_img = &so->img_data;
	so_img->img = mlx_xpm_file_to_image(mlx,
			so->relative_path, &so->width, &so->height);
	if (so_img->img == NULL)
	{
		write(1, "ERROR: mlx cant open south texture\n", 35);
		exit(-1);
	}
	so_img->addr = mlx_get_data_addr(so_img->img,
			&so_img->bits_per_pixel, &so_img->line_lenght, &so_img->endian);
}

void	init_img_west_texture(void *mlx, t_textures *tex_data)
{
	t_tex_data		*we;
	t_img_data		*we_img;

	we = &tex_data->we;
	we_img = &we->img_data;
	we_img->img = mlx_xpm_file_to_image(mlx,
			we->relative_path, &we->width, &we->height);
	if (we_img->img == NULL)
	{
		write(1, "ERROR: mlx cant open west texture\n", 34);
		exit(-1);
	}
	we_img->addr = mlx_get_data_addr(we_img->img,
			&we_img->bits_per_pixel, &we_img->line_lenght, &we_img->endian);
}

void	init_img_east_texture(void *mlx, t_textures *tex_data)
{
	t_tex_data		*ea;
	t_img_data		*ea_img;

	ea = &tex_data->ea;
	ea_img = &ea->img_data;
	ea_img->img = mlx_xpm_file_to_image(mlx,
			ea->relative_path, &ea->width, &ea->height);
	if (ea_img->img == NULL)
	{
		write(1, "ERROR: mlx cant open east texture\n", 34);
		exit(-1);
	}
	ea_img->addr = mlx_get_data_addr(ea_img->img,
			&ea_img->bits_per_pixel, &ea_img->line_lenght, &ea_img->endian);
}
