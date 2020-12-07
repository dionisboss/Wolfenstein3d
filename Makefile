NAME = cub3d
SRCDIR = src/

SRC = $(SRCDIR)main.c

#####################     LIBS     ##########################

LIBS =	$(LIBNEWMAP) \
		$(LIBMLX) \
		$(LIBFT)

LIBNEWMAPDIR = $(SRCDIR)parse_map/
LIBNEWMAP = $(LIBNEWMAPDIR)new_map.a

LIBMLXDIR = $(SRCDIR)minilibx_opengl_20191021/
LIBMLX = $(LIBMLXDIR)libmlx.a
MLXFLAGS = -framework OpenGL -framework AppKit

LIBFTDIR =	$(SRCDIR)libft/
LIBFT =		$(LIBFTDIR)libft.a

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