# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vshkykav <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/24 20:11:39 by vshkykav          #+#    #+#              #
#    Updated: 2017/10/25 18:33:45 by vshkykav         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Werror -Wextra
OFILES = ft_strstr.o ft_strmap.o ft_lstadd.o ft_strdel.o ft_memccpy.o ft_strlen.o ft_putchar_fd.o \
			ft_strchr.o ft_tolower.o ft_strequ.o ft_isalnum.o ft_memmove.o ft_strdup.o ft_isalpha.o \
			ft_memset.o ft_strtrim.o ft_putendl.o ft_strncmp.o ft_memalloc.o ft_strnequ.o ft_lstdelone.o \
			ft_memchr.o ft_striter.o ft_bzero.o ft_memcpy.o ft_isdigit.o ft_memcmp.o ft_strsub.o ft_memdel.o \
			ft_strjoin.o ft_strcmp.o ft_strcpy.o ft_lstnew.o ft_putnbr.o ft_strncat.o ft_isascii.o \
			ft_itoa.o ft_lstmap.o ft_putstr.o ft_strlcat.o ft_putnbr_fd.o ft_strsplit.o ft_lstiter.o \
			ft_strcat.o ft_lstdel.o ft_putendl_fd.o ft_striteri.o ft_strnew.o ft_isprint.o ft_strnstr.o \
			ft_atoi.o ft_strclr.o ft_strncpy.o ft_putchar.o ft_putstr_fd.o ft_toupper.o ft_strmapi.o \
			ft_strrchr.o ft_str_tolower.o ft_str_toupper.o ft_printarr.o ft_isspace.o ft_lstsize.o
HFILES = libft.h

all: $(NAME)
$(NAME): $(OFILES)
	ar rc $(NAME) $(OFILES) $(HFILES)
	ranlib $(NAME)
%.o: %.c
	gcc -o $@ -c $< $(FLAGS)
clean:
	rm -f $(OFILES)
fclean: clean
	rm -f $(NAME)
<<<<<<< HEAD
re: fclean
=======
re: fclean all
>>>>>>> fcbba40177d6cd0b4ed842a8137e275e60ac949c
