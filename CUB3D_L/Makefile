NAME	=	cub3d
SRC		=	main.c \
			get_next_line/get_next_line.c\
			get_next_line/get_next_line_utils.c \
			parsing/parsing_map.c parsing/parsing_utils_1.c\
			parsing/parsing_utils_2.c\
			parsing/handling_texture.c\
			parsing/parsing_map_1.c\
			cub_util/cub_util_1.c



OBJ = ${SRC:.c=.o}
CC = gcc 
#CFLAGS = -Wall -Werror -Wextra
HEADERS = cub3d.h
LIBFT = libft/libft.a
GREEN  = \033[1;32m
YELLOW = \033[1;33m

all : $(NAME)

%.o:%.c  $(HEADERS)
	@gcc -g -c $< -o $@

$(NAME) : $(OBJ)
	@$(CC)  -lmlx -framework openGL -framework AppKit  $(OBJ) $(LIBFT) -g -o $(NAME)
	@echo "$(GREEN)---> success!"
clean :
	@rm -f $(OBJ)
	@echo "${YELLOW}---> object files deleted!"

fclean : clean
	@rm -f $(NAME)
	@echo "${YELLOW}---> all deleted!"
re : fclean all