NAME = cub3d
SRCDIR = src/

SRC =	$(SRCDIR)main.c \
		$(GAME_INITIATION) \
		$(GAME_ENGINE) \
		$(PLAYER_EVENTS) \
		$(RAYCASTING_RENDER) \
		$(DRAWING)

#####################     LIBS     ##########################

LIBS =	$(LIBNEWMAP) \
		$(LIBMLX) \
		$(LIBFT)

LIBNEWMAPDIR = $(SRCDIR)parse_map/
LIBNEWMAP = $(LIBNEWMAPDIR)new_map.a \

LIBMLXDIR = $(SRCDIR)minilibx_opengl_20191021/
LIBMLX = $(LIBMLXDIR)libmlx.a
MLXFLAGS = -framework OpenGL -framework AppKit

LIBFTDIR =	$(SRCDIR)libft/
LIBFT =		$(LIBFTDIR)libft.a

#############################################################

###################     game_engine     #####################

GAME_ENGINE_DIR = $(SRCDIR)game_engine/
GAME_ENGINE =	$(GAME_ENGINE_DIR)keyboard_handler.c \
				$(GAME_ENGINE_DIR)game_control.c \

#------------------   game_initiation   #--------------------

GAME_INITIATION_DIR =	$(GAME_ENGINE_DIR)game_initiation/
GAME_INITIATION =		$(GAME_INITIATION_DIR)init_game_space.c \
						$(GAME_INITIATION_DIR)init_wall_textures.c \
						$(GAME_INITIATION_DIR)init_wall_textures_utils.c \
						$(GAME_INITIATION_DIR)init_sprites.c \
						$(GAME_INITIATION_DIR)init_arr_of_sprites.c

#------------------------------------------------------------
#------------------    player_events    #--------------------

PLAYER_EVENTS_DIR =	$(GAME_ENGINE_DIR)player_events/
PLAYER_EVENTS =		$(PLAYER_EVENTS_DIR)init_player.c \
					$(PLAYER_EVENTS_DIR)player_moving.c \
					$(PLAYER_EVENTS_DIR)move_forward_backward.c \
					$(PLAYER_EVENTS_DIR)move_forward_backward_utils.c \
					$(PLAYER_EVENTS_DIR)move_sideways.c \
					$(PLAYER_EVENTS_DIR)move_sideways_utils.c \
					$(PLAYER_EVENTS_DIR)turn_player.c

#------------------------------------------------------------

#------------------  raycasting_render  #--------------------

RAYCASTING_RENDER_DIR =	$(GAME_ENGINE_DIR)raycasting_render/
RAYCASTING_RENDER =		$(RAYCASTING_RENDER_DIR)raycasting_render.c \
						$(RAYCASTING_RENDER_DIR)init_ray.c \
						$(RAYCASTING_RENDER_DIR)calculate_draw_start_end.c \
						$(SPRITES_RENDERING)

#//// sprites_rendering

SPRITES_RENDERING_DIR =	$(RAYCASTING_RENDER_DIR)sprites_rendering/
SPRITES_RENDERING =		$(SPRITES_RENDERING_DIR)sprites_rendering.c

#//////////////////////

#------------------------------------------------------------

#------------------       drawing       #--------------------

DRAWING_DIR =	$(GAME_ENGINE_DIR)drawing/
DRAWING =		$(DRAWING_DIR)drawing_img.c \
				$(DRAWING_DIR)drawing_textures.c

#------------------------------------------------------------

#############################################################

######################     OBJ     ##########################

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLD = includes/

.c.o:
	$(CC) -I$(INCLD) -c $< -o $(<:.c=.o)

#############################################################

$(NAME):	$(OBJ)
	make -C src/minilibx_opengl_20191021/
	make -C src/parse_map/
	$(CC) $(MLXFLAGS) $(LIBS) $(OBJ) -o $(NAME)

all:		$(NAME)

clean:
	make clean -C src/minilibx_opengl_20191021/
	make clean -C src/parse_map/
	rm -rf $(OBJ)

fclean: clean
	make clean -C src/minilibx_opengl_20191021/
	make fclean -C src/parse_map/
	rm -rf $(NAME)

re:	fclean	all
