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

#include <stdio.h>
#include <unistd.h>
#include "mlx.h"

typedef	struct			s_data
{
	void				*img;
	void				*addr;
	int					bits_per_pixel;
	int					line_lenght;
	int					endian;
}						t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		main(void)
{
	void	*mlx;
	void	*win;

	t_data	img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 600, 600, "Gdrive!");

	img.img = mlx_new_image(mlx, 600, 600);

	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);

	size_t	i = 0;
	size_t	j = 0;
	while (i < 300)
	{
		j = 0;
		while (j < 300)
		{
			my_mlx_pixel_put(&img, i, j, 0x00FF0000);
			j++;
		}
		i++;
	}

	mlx_put_image_to_window(mlx, win, img.img, 149, 149);

	mlx_loop(mlx);



	return (0);
}
