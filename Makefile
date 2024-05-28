CC = gcc -Wall -Wextra -Werror
NAME = so_long
BONUS_NAME = so_long_bonus
SRCS = ./src/init_info.c ./src/init_img.c ./src/so_long.c ./src/move_character1.c ./src/move_character2.c ./src/check_path.c ./src/parse_args1.c ./src/parse_args2.c ./src/utils.c
OBJS = $(SRCS:.c=.o)
BONUS_SRCS = ./bonus/init_info_bonus.c ./bonus/init_img1_bonus.c ./bonus/init_img2_bonus.c ./bonus/so_long_bonus.c ./bonus/move_character1_bonus.c ./bonus/move_character2_bonus.c ./bonus/check_path_bonus.c ./bonus/parse_args1_bonus.c ./bonus/parse_args2_bonus.c ./bonus/utils_bonus.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME) $(BONUS_NAME)

bonus: $(BONUS_NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C libft clean
	make -C minilibx_opengl clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	make -C libft fclean
	make -C minilibx_opengl clean

re: fclean all

$(BONUS_NAME): $(BONUS_OBJS)
	make -C libft
	make -C minilibx_opengl
	$(CC) $(BONUS_OBJS) libft/libft.a minilibx_opengl/libmlx.a -framework OpenGL -framework AppKit -o $(BONUS_NAME)

$(NAME): $(OBJS)
	make -C libft 
	make -C minilibx_opengl
	$(CC) $(OBJS) libft/libft.a minilibx_opengl/libmlx.a -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -Imlx -c $< -o $@

.PHONY: all clean fclean re
