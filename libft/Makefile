# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skaren <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 16:28:02 by skaren            #+#    #+#              #
#    Updated: 2019/09/25 01:33:52 by skaren           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

SOURCEFILES	= ft_bzero.c ft_memset.c ft_putstr_fd.c ft_striter.c ft_strncpy.c\
			ft_memalloc.c ft_putchar.c ft_strcat.c ft_striteri.c ft_strnequ.c\
			ft_memccpy.c ft_putchar_fd.c ft_strchr.c ft_strjoin.c ft_strnew.c\
			ft_memchr.c ft_putendl.c ft_strclr.c ft_strlcat.c ft_strrchr.c\
			ft_memcmp.c ft_putendl_fd.c ft_strcpy.c ft_strlen.c ft_strstr.c\
			ft_memcpy.c ft_putnbr.c ft_strdel.c ft_strmap.c ft_strsub.c\
			ft_memdel.c ft_putnbr_fd.c ft_strdup.c ft_strmapi.c ft_memmove.c\
			ft_putstr.c ft_strequ.c ft_strncat.c ft_strnstr.c ft_strnlen.c\
			ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c\
			ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c\
			ft_strtrim.c ft_strsplit.c ft_itoa.c get_next_line.c

CFLAGS = -Wall -Werror -Wextra

SOURCESFOLD = ./srcs
HEADERSFOLD = ./includes
OBJECTSFOLD = ./objs

SOURCES 	= $(patsubst %.c, $(SOURCESFOLD)/%.c, $(SOURCEFILES))
OBJECTFILES = $(SOURCEFILES:.c=.o)
OBJECTS 	= $(patsubst %.o, $(OBJECTSFOLD)/%.o, $(OBJECTFILES))

all: obj $(NAME)

obj:
	mkdir -p $(OBJECTSFOLD)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

$(OBJECTSFOLD)/%.o: $(SOURCESFOLD)/%.c
	gcc -c $^ -I$(HEADERSFOLD) -o $@

clean:
	rm -f $(OBJECTS)
	rm -Rf $(OBJECTSFOLD)

fclean:
	rm -f $(NAME)
	rm -f $(OBJECTS)
	rm -Rf $(OBJECTSFOLD)

re: fclean all
