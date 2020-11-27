NAME = cub3d
SRCDIR = src/

SRC = ${SRCDIR}main.c

OBJ = ${SRC:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLD = includes/

.c.o:
	${CC} ${CFLAGS} -I${INCLD} -c $< -o ${<:.c=.o}

${NAME}:	${OBJ}
	${CC} -o ${NAME} ${OBJ}

all:		${NAME}

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re:	fclean	all