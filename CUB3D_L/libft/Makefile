# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbenaoui <mbenaoui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 16:37:24 by mbenaoui          #+#    #+#              #
#    Updated: 2021/11/27 14:30:14 by mbenaoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILE = ft_memcmp.c ft_memcpy.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
ft_itoa.c ft_memchr.c  ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_split.c \
ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_putstr_fd.c  ft_putnbr_fd.c


NAME = libft.a
OBJ_FILE = $(SRC_FILE:%.c=%.o)
CFLAGS = -Wall -Werror -Wextra
all : $(NAME)

$(NAME) : $(OBJ_FILE) libft.h
	ar rc $(NAME) $(OBJ_FILE)
%.o: %.c  
	cc $(CFLAGS) -o $@ -c $<
	
clean :
	rm -f $(OBJ_FILE)

fclean :    clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re 
