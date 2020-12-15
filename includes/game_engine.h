/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_engine.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:50:35 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/15 10:52:39 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_ENGINE_H
# define GAME_ENGINE_H
# include "new_map.h"

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
** For s_game_data.
** Ray-data.
*/

typedef struct			s_ray
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
}						t_ray;

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
** Texture-data.
*/

typedef struct			s_tex_data
{
	char				*relative_path;
	t_img_data			img_data;
	int					width;
	int					height;
}						t_tex_data;

/*
** For s_game_data.
** Textures-data:
**    n - north texture.
**    s - south texture.
**    w - west texture.
**    e - east texture.
*/

typedef struct			s_textures
{
	t_tex_data			no;
	t_tex_data			so;
	t_tex_data			we;
	t_tex_data			ea;
}						t_textures;

/*
** For s_sprites.
** Sprite position.
*/

typedef struct			s_sprite
{
	double				x;
	double				y;
}						t_sprite;

/*
** For s_game_data.
** Sprites-data.
*/

typedef struct			s_sprites
{
	t_sprite			**sprites;
	t_tex_data			tex_data;
}						t_sprites;


/*
** Keycodes.
*/

# define ESC 53
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_Q 12
# define KEY_E 14
# define KEY_LEFT 123
# define KEY_RIGHT 124

/*
** For s_game_data.
** Key-flags.
** 1 - key is pressed.
** 0 - key is unpressed.
*/

typedef struct			s_key_f
{
	char				w;
	char				s;
	char				a;
	char				d;
	char				q;
	char				e;
}						t_keys_f;


/*
** For s_player.
** Player position.
*/

# define MOVE_SPEED 0.1
# define ROT_SPEED 0.05

typedef struct			s_player_pos
{
	double				x;
	double				y;
}						t_player_pos;

/*
** For s_game_data.
** Information about player.
*/

typedef struct			s_player
{
	t_player_pos		pos;
	t_direction			dir;
	char				start_view;
}						t_player;

/*
** Game-data.
*/

typedef struct			s_game_data
{
	t_mlx_data			mlx_data;
	t_img_data			img_data;
	t_textures			tex_data;
	t_sprites			sprites;
	t_player			player;
	t_keys_f			keys;
	t_map				map;
	t_ray				ray;
}						t_game_data;

/*
** ============================================================================
**                             Public functions.
** ============================================================================
*/

/*
** Init game workspace.
*/

int						init_game_space(t_game_data *game_data);
int						init_player(t_player *player, t_plane *plane, char **maze);
void					init_wall_textures(t_game_data *game_data);
void					check_dot_xpm(char *s);
void					init_img_north_texture(void *mlx, t_textures *tex_data);
void					init_img_south_texture(void *mlx, t_textures *tex_data);
void					init_img_west_texture(void *mlx, t_textures *tex_data);
void					init_img_east_texture(void *mlx, t_textures *tex_data);
void					init_sprites(t_game_data *game_data);
void					init_arr_sprites(t_game_data *game_data);
int						free_sprites(t_sprite ***sprites);
int						is_player(char c);

/*
** Game control.
*/

int						start_game(t_game_data *game_data);
void					finish_game(t_game_data *game_data);

/*
** Render
*/

int						raycasting_render(t_game_data *game_data);

/*
** Drawing img.
*/

void					my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
void					draw_sky(t_game_data *game_data);
void					draw_land(t_game_data *game_data);
void					draw_textures(t_game_data *game_data, size_t i);

/*
** Keyboard hanlder.
*/

int						handle_pressed_key(int keycode, t_game_data *game_data);
int						handle_unpressed_key(int keycode, t_game_data *game_data);

/*
** ----------------------------------------------------------------------------
**                               Player moving.
** ----------------------------------------------------------------------------
*/

void					player_move(t_game_data *game_data);

int						move_forward_backward(t_game_data *game_data);
int						next_y_is_not_wall(char **maze, t_player *player);
int						next_x_is_not_wall(char **maze, t_player *player);
int						previous_y_is_not_wall(char **maze, t_player *player);
int						previous_x_is_not_wall(char **maze, t_player *player);

int						move_sideways(t_game_data *game_data);
int						a_strafe_next_y_is_not_wall(t_game_data *game_data);
int						a_strafe_next_x_is_not_wall(t_game_data *game_data);
int						d_strafe_next_y_is_not_wall(t_game_data *game_data);
int						d_strafe_next_x_is_not_wall(t_game_data *game_data);

int						turn_player(t_game_data *game_data);

/*
** ----------------------------------------------------------------------------
** ----------------------------------------------------------------------------
** ----------------------------------------------------------------------------
*/

/*
** ----------------------------------------------------------------------------
**                             Raycasting-render.
** ----------------------------------------------------------------------------
*/

int						init_ray(t_game_data *game_data, size_t i);
void					calculate_draw_start_end(t_game_data *game_data);

/*
** ----------------------------------------------------------------------------
** ----------------------------------------------------------------------------
** ----------------------------------------------------------------------------
*/

/*
** ============================================================================
** ============================================================================
** ============================================================================
*/

#endif
