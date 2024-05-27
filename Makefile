CC = gcc -Wall -Wextra -Werror
NAME = so_long
SRCS = ./src/init_info.c ./src/init_img1.c ./src/init_img2.c ./src/so_long.c ./src/move_character1.c ./src/move_character2.c ./src/check_path.c ./src/parse_args1.c ./src/parse_args2.c ./src/utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

clean:
	rm -f $(OBJS)
	make -C libft clean
fclean: clean
	rm -f $(NAME)
	make -C libft fclean
re: fclean all

$(NAME): $(OBJS)
	make -C libft 
	# $(CC) $(OBJS) libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	$(CC) $(OBJS) libft/libft.a minilibx_opengl_20191021/libmlx.a -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -Imlx -c $< -o $@

.PHONY: all clean fclean re
