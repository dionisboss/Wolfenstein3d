NAME = parseMap

######################     SRC     ##########################

SRCDIR = src/
SRC =	$(SRCDIR)main.c \
		$(SRCDIR)parse_map.c \
		$(FORTEST) \
		$(INITORCLEAN) \
		$(GNL) \
		$(PARSEIDENTIFIER) \
		$(FILEWORK)

#for_test
FORTESTDIR = $(SRCDIR)for_tests/
FORTEST = $(FORTESTDIR)print_map.c

#init_or_clean
INITORCLEANDIR = $(SRCDIR)init_or_clean/
INITORCLEAN =	$(INITORCLEANDIR)init_zero_map.c \
				$(INITORCLEANDIR)free_arrstrs.c \
				$(INITORCLEANDIR)free_map.c

#get_next_line
GNLDIR = $(SRCDIR)gnl/
GNL = $(GNLDIR)get_next_line.c $(GNLDIR)get_next_line_utils.c

#file_work
FILEWORKDIR = $(SRCDIR)file_work/
FILEWORK = $(FILEWORKDIR)file_work.c

#parse_identifier
PARSEIDENTIFIERDIR = $(SRCDIR)parse_identifier/
PARSEIDENTIFIER =	$(PARSEIDENTIFIERDIR)parse_identifier.c \
					$(PARSEIDENTIFIERDIR)is_texture_identifier.c \
					$(PARSEIDENTIFIERDIR)is_technical_identifier.c \
					$(PARSEIDENTIFIERDIR)parse_technical_utils.c

#############################################################


#####################     LIBS     ##########################

LIBSDIR = libs/
LIBS = $(LIBFT)

LIBFTDIR = $(LIBSDIR)libft/
LIBFT = $(LIBFTDIR)libft.a

#############################################################


######################     OBJ     ##########################

OBJ = ${SRC:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLD = includes/

.c.o:
	$(CC) -I$(INCLD) -c $< -o $(<:.c=.o)

#############################################################


$(NAME):	$(OBJ)
	make -C $(LIBFTDIR)
	$(CC) $(LIBS) ${OBJ} -o ${NAME}

all:		$(NAME)

clean:
	make clean -C $(LIBFTDIR)
	rm -rf $(OBJ)

fclean: clean
	make fclean -C $(LIBFTDIR)
	rm -rf $(NAME)

re:	fclean	all