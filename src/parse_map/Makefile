NAME = new_map.a

######################     SRC     ##########################

SRCDIR = src/
SRC =	$(SRCDIR)new_map.c \
	$(FORTEST) \
	$(INITORCLEAN) \
	$(FILEWORK) \
	$(GNL) \
	$(PARSEMAPCONFIG) \
	$(PARSEIDENTIFIER) \
	$(PARSEMAP) \
	$(CHECKCONFIGERROR) \
	#$(SRCDIR)main.c

#for_test
FORTESTDIR = $(SRCDIR)for_tests/
FORTEST = $(FORTESTDIR)print_map.c

#init_or_clean
INITORCLEANDIR = $(SRCDIR)init_or_clean/
INITORCLEAN =	$(INITORCLEANDIR)init_zero_map.c \
		$(INITORCLEANDIR)free_map.c

#file_work
FILEWORKDIR = $(SRCDIR)file_work/
FILEWORK = $(FILEWORKDIR)file_work.c

#get_next_line
GNLDIR = $(SRCDIR)gnl/
GNL =	$(GNLDIR)get_next_line.c \
	$(GNLDIR)get_next_line_utils.c

#parse_map_config
PARSEMAPCONFIGDIR = $(SRCDIR)parse_map_config/
PARSEMAPCONFIG =	$(PARSEMAPCONFIGDIR)parse_map_config.c

#parse_identifier
PARSEIDENTIFIERDIR = $(SRCDIR)parse_identifier/
PARSEIDENTIFIER =	$(PARSEIDENTIFIERDIR)parse_identifier.c \
			$(PARSEIDENTIFIERDIR)is_texture_identifier.c \
			$(PARSEIDENTIFIERDIR)is_technical_identifier.c \
			$(PARSEIDENTIFIERDIR)parse_technical_utils.c

#parse_map
PARSEMAPDIR = $(SRCDIR)parse_map/
PARSEMAP =	$(PARSEMAPDIR)parse_map.c

#check_config_error
CHECKCONFIGERRORDIR = $(SRCDIR)check_config_error/
CHECKCONFIGERROR =	$(CHECKCONFIGERRORDIR)is_full_config.c \
			$(CHECKCONFIGERRORDIR)scan_map_error.c \
			$(CHECKCONFIGERRORDIR)is_closed_map.c \

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
	#$(CC) $(LIBS) ${OBJ} -o ${NAME}
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all:		$(NAME)

clean:
	make clean -C $(LIBFTDIR)
	rm -rf $(OBJ)

fclean: clean
	make fclean -C $(LIBFTDIR)
	rm -rf $(NAME)

re:	fclean	all
