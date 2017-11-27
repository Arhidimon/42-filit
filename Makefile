NAME = fillit
FLAGS = -Wall -Werror -Wextra
CFILES = main.c validate_file.c ft_map_size.c save_tetramino.c get_solution.c printout.c
HFILES = fillit.h
LIB = /libft/

all: $(NAME)
$(NAME): $(CFILES)
	gcc ${FLAGS} ${CFILES} -L.${LIB} -lft -o ${NAME}
clean:
	rm -f $(OFILES)
fclean: clean
	rm -f $(NAME)
re: fclean all