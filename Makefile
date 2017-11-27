NAME = fillit
FLAGS = -Wall -Werror -Wextra
OFILES = main.o validate_file.o ft_map_size.o save_tetramino.o get_solution.o printout.o ft_putstr.o
INCLUDES = fillit.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OFILES)
	gcc ${FLAGS} ${OFILES} -o ${NAME}
%.o : %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@ -I$(INCLUDES)
clean:
	rm -f $(OFILES)
fclean: clean
	rm -f $(NAME)
re: 
	make fclean
	make all