CC=gcc
C_FLAGS=-Wall -Werror -Wextra
NAME=fdf
BONUS_NAME=fdf_bonus.c
SRC_DIR=./sources/
SRC_LIST=fdf_create_point_3d.c \
	fdf_create_point_2d.c \
	fdf_create_new_matrix.c \
	fdf_delete_matrix.c \
	fdf_errors.c \
	\
	fdf_mod_matrix.c \
	fdf_rotate_point.c \
	\
	fdf_draw_screen.c \
	fdf_project_orto.c \
	fdf_bresenham.c \
	\
	fdf_init_fdf.c\
	fdf_file_to_matrix.c \
	fdf_init_matrix.c \
	fdf_read_file.c\
	fdf_check_lines.c \
	fdf_create_new_window.c \
	fdf_clean_fdf.c\
	\
	\

SRC= $(addprefix $(SRC_DIR), $(SRC_LIST))
MAIN_KEY=./sources/fdf_keyboard.c \
	./sources/fdf.c \
	./sources/fdf_instructions.c
BONUS_KEY= ./sources/fdf_keyboard_bonus.c \
	./sources/fdf_bonus.c \
	./sources/fdf_instructions_bonus.c

LIB_PATH= ./minilibx_macos
FRAMEWORKS=-framework OpenGL -framework AppKit

GNL=get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c -D BUFFER_SIZE=42

all:$(NAME)

$(NAME): $(SRC) $(MAIN_KEY)
	make -C $(LIB_PATH)
	make -C libft
	$(CC) $(C_FLAGS) libft/libft.a -L $(LIB_PATH) -lmlx $(FRAMEWORKS) $(GNL) $^ -o $@

clean:
	make -C $(LIB_PATH) clean
	make -C libft clean

fclean:
	make -C $(LIB_PATH) clean
	make -C libft fclean
	rm -f $(NAME) fdf_bonus

re:
	make fclean
	make $(NAME)

bonus: $(SRC) $(BONUS_KEY)
	make -C $(LIB_PATH)
	make -C libft
	$(CC) $(C_FLAGS) libft/libft.a -L $(LIB_PATH) -lmlx $(FRAMEWORKS) $(GNL) $^ -o fdf_bonus
