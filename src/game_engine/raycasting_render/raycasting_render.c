/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_render.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:49:20 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/15 18:55:21 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "new_map.h"
#include "game_engine.h"
#include "mlx.h"
#include <stdio.h>

static void	print_double_arr(double *arr, size_t len)
{
	for (int i = 0; i < len; i++)
	{
		if (i + 1 < len)
			printf("%f ", arr[i]);
		else
			printf("%f\n", arr[i]);
	}
}
static void	print_int_arr(int *arr, size_t len)
{
	for (int i = 0; i < len; i++)
	{
		if (i + 1 < len)
			printf("%d ", arr[i]);
		else
			printf("%d\n", arr[i]);
	}
}

void	sort_sprites(int *sprite_order, double *sprite_distance, size_t len)
{
	/*
	printf("before sort\nsprite_order: ");
	print_int_arr(sprite_order, len);
	printf("sprite_distance: ");
	print_double_arr(sprite_distance, len);
	*/

	if (len == 0)
		return ;

	size_t	i = 0;
	size_t	j = 0;
	int		save_order;
	double	save_double;

	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (sprite_distance[i] < sprite_distance[j])
			{
				save_double = sprite_distance[i];
				sprite_distance[i] = sprite_distance[j];
				sprite_distance[j] = save_double;

				save_order = sprite_order[i];
				sprite_order[i] = sprite_order[j];
				sprite_order[j] = save_order;
			}
			j++;
		}
		i++;
	}

	/*
	printf("after sort\nsprite_order: ");
	print_int_arr(sprite_order, len);
	printf("sprite_distance: ");
	print_double_arr(sprite_distance, len);
	*/

	//sleep(30);
}

int		raycasting_render(t_game_data *game_data)
{
	t_ray				*ray;
	static size_t		x;

	draw_sky(game_data);
	draw_land(game_data);

	ray = &game_data->ray;

	player_move(game_data);

	x = 0;
	double		ZBuffer[game_data->map.r[0]];
	while (x < game_data->map.r[0])
	{
		init_ray(game_data, x);
		calculate_draw_start_end(game_data);
		draw_textures(game_data, x);
		ZBuffer[x] = ray->perp_wall_dist;
		x++;
	}


	int			numSprites = game_data->sprites.num_sprites;
	static char	numSpritesFlag = 0;
	/*
	if (numSpritesFlag == 0)
	{
		printf("numSprites = %d\n", numSprites);
		numSpritesFlag = 1;
	}
	*/

	int			spriteOrder[numSprites];
	double		spriteDistance[numSprites];

	t_sprite	**sprite = game_data->sprites.sprites;

	double		posX = game_data->player.pos.x;
	double		posY = game_data->player.pos.y;

	static char	texXY = 0;
	/*
	if (texXY < 2)
	{
		for (int z = 0; z < numSprites; z++)
			printf("sprite[%d]: x = %f, y = %f\n", z, sprite[z]->x, sprite[z]->y);
		texXY++;
	}
	*/

	for(int i = 0; i < numSprites; i++)
    {
      spriteOrder[i] = i;
      spriteDistance[i] = ((posX - sprite[i]->x) * (posX - sprite[i]->x) + (posY - sprite[i]->y) * (posY - sprite[i]->y));
    }
	static char	numSpritesOrderFlag = 0;
	if (numSpritesOrderFlag == 0)
	{
		printf("before sort:\n");
		print_double_arr(spriteDistance, numSprites);
		print_int_arr(spriteOrder, numSprites);
		numSpritesOrderFlag = 1;
	}
    sort_sprites(spriteOrder, spriteDistance, numSprites);
	if (numSpritesOrderFlag == 1)
	{
		printf("after sort:\n");
		print_double_arr(spriteDistance, numSprites);
		print_int_arr(spriteOrder, numSprites);
		numSpritesOrderFlag = 2;
	}



	double	planeX = game_data->ray.plane.x;
	double	planeY = game_data->ray.plane.y;
	static char	planeXY = 0;
	if (planeXY < 2)
	{
		printf("planeX = %f, planeY = %f\n", planeX, planeY);
		if (planeXY != 2)
			planeXY++;
	}

	double	dirX = game_data->player.dir.x;
	double	dirY = game_data->player.dir.y;
	static char	dirXY = 0;
	if (dirXY < 2)
	{
		printf("dirX = %f, dirY = %f\n", dirX, dirY);
		if (dirXY != 2)
			dirXY++;
	}

	size_t	w = game_data->map.r[0];
	size_t	h = game_data->map.r[1];

	int		texHeight = game_data->sprites.tex_data.height;
	int		texWidth = game_data->sprites.tex_data.width;
	static char	texHW = 0;
	if (texHW < 1)
	{
		printf("texHeight = %d, texWidth = %d\n", texHeight, texWidth);
		if (texHW != 2)
			texHW++;
	}


	for(int i = 0; i < numSprites; i++)
    {
      //translate sprite position to relative to camera
      double spriteX = sprite[spriteOrder[i]]->x - posX;
      double spriteY = sprite[spriteOrder[i]]->y - posY;

      //transform sprite with the inverse camera matrix
      // [ planeX   dirX ] -1                                       [ dirY      -dirX ]
      // [               ]       =  1/(planeX*dirY-dirX*planeY) *   [                 ]
      // [ planeY   dirY ]                                          [ -planeY  planeX ]

      double invDet = 1.0 / (planeX * dirY - dirX * planeY); //required for correct matrix multiplication

      double transformX = invDet * (dirY * spriteX - dirX * spriteY);
      double transformY = invDet * (-planeY * spriteX + planeX * spriteY); //this is actually the depth inside the screen, that what Z is in 3D

      int spriteScreenX = (int)(w - w / 2 * (1 + transformX / transformY));

      //calculate height of the sprite on screen
      int spriteHeight = abs((int)(h / (transformY))); //using 'transformY' instead of the real distance prevents fisheye
      //calculate lowest and highest pixel to fill in current stripe
      int drawStartY = -spriteHeight / 2 + h / 2;
      if(drawStartY < 0) drawStartY = 0;
      int drawEndY = spriteHeight / 2 + h / 2;
      if(drawEndY >= h) drawEndY = h - 1;

      //calculate width of the sprite
      int spriteWidth = abs((int)(h / (transformY)));
      int drawStartX = -spriteWidth / 2 + spriteScreenX;
      if(drawStartX < 0)
		  drawStartX = 0;
      int drawEndX = spriteWidth / 2 + spriteScreenX;
	  /*
      if(drawEndX >= w)
	  {
		  printf("!!!\n");
		  drawEndX = w - 1;
	  }
	  */

      //loop through every vertical stripe of the sprite on screen
      for(int stripe = drawStartX; stripe < drawEndX; stripe++)
      {
        int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * texWidth / spriteWidth) / 256;
        //the conditions in the if are:
        //1) it's in front of camera plane so you don't see things behind you
        //2) it's on the screen (left)
        //3) it's on the screen (right)
        //4) ZBuffer, with perpendicular distance
        if(transformY > 0 && stripe > 0 && stripe < w && transformY < ZBuffer[stripe])
		{
			for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
			{
				int d = (y) * 256 - h * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
				int texY = ((d * texHeight) / spriteHeight) / 256;
				uint32_t color = ((int*)game_data->sprites.tex_data.img_data.addr)
				  [texWidth * texY + texX]; //get current color from the texture
				if((color & 0x00FFFFFF) != 9961608)
				  my_mlx_pixel_put(&game_data->img_data, stripe, y, color);
			}
		}
      }
    }


















	mlx_put_image_to_window(game_data->mlx_data.mlx, game_data->mlx_data.win, game_data->img_data.img, 0, 0);
	return (0);
}
