/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_engine.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:50:35 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/08 20:04:44 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_ENGINE_H
# define GAME_ENGINE_H
# include "new_map.h"

/*
** For s_game_data.
** MLX-data.
*/

typedef struct			s_mlx_data
{
	void				*mlx;
	void				*win;
}						t_mlx_data;

/*
** For s_game_data.
** IMG-data.
*/

typedef struct			s_img_data
{
	void				*img;
	void				*addr;
	int					bits_per_pixel;
	int					line_lenght;
	int					endian;
}						t_img_data;

/*
** For s_game_data.
** Information about player.
*/

typedef struct			s_player
{
	double				pos_x;
	double				pos_y;
	double				dir_x;
	double				dir_y;
	char				start_view;
}						t_player;

/*
** Keycodes.
*/

# define ESC 53
# define W 13
# define S 1
# define A 0
# define D 2

typedef struct			s_key_f
{
	char				w;
	char				s;
	char				a;
	char				d;
}						t_keys_f;


/*
** Game-data.
*/

typedef struct			s_game_data
{
	t_mlx_data			mlx_data;
	t_img_data			img_data;
	t_player			player;
	t_keys_f			keys;
	t_map				map;
}						t_game_data;

/*
** For s_ray_data.
*/

typedef struct			s_plane
{
	double				x;
	double				y;
}						t_plane;

typedef struct			s_direction
{
	double				x;
	double				y;
}						t_direction;

typedef struct			s_map_pos
{
	int					x;
	int					y;
}						t_map_pos;

typedef struct			s_side_dist
{
	double				x;
	double				y;
	double				delta_x;
	double				delta_y;
}						t_side_dist;

typedef struct			s_step
{
	int					x;
	int					y;
}						t_step;

/*
** Ray-data.
*/

typedef struct			s_ray_dir
{
	t_plane				plane;
	double				camera_x;
	t_direction			dir;
	t_map_pos			map;
	t_side_dist			side_d;
	double				perp_wall_dist;
	t_step				step;
	int					hit;
	int					side;
	int					line_h;
	int					draw_start;
	int					draw_end;
}						t_ray_dir;

/*
** Public functions.
*/

int		init_game_space(t_game_data *game_data);
int		init_player(t_player *player, char **maze);
int		raycasting_render(t_game_data *game_data);

#endif
