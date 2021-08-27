CC=gcc
C_FLAGS=-Wall -Werror -Wextra
NAME=fdf

SRC_DIR=./sources/
SRC_LIST=test.c\
	fdf_create_new_window.c \
	fdf_keyboard.c \
	fdf_bresenham.c \
	fdf_create_point.c
SRC= $(addprefix $(SRC_DIR), $(SRC_LIST))

LIB_PATH= ./minilibx_macos
FRAMEWORKS=-framework OpenGL -framework AppKit

GNL=get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c -D BUFFER_SIZE=42

all:$(NAME)

$(NAME): $(SRC)
	make -C $(LIB_PATH)
	make -C libft
	$(CC) $(C_FLAGS) libft/libft.a -L $(LIB_PATH) -lmlx $(FRAMEWORKS) $(GNL) $^ -o $@

clean:

fclean:
	make -C $(LIB_PATH) clean
	rm -f $(NAME)

re:
	make fclean
	make $(NAME)