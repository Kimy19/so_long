CC = gcc -Wall -Wextra -Werror
NAME = so_long
BONUS_NAME = checker
SRCS = so_long.c move_character.c
OBJS = $(SRCS:.c=.o)
BONUS_SRCS = ./bonus/bonus.c ./bonus/bonus_command1.c ./bonus/bonus_command2.c ./bonus/bonus_command3.c ./bonus/bonus_parse_args1.c ./bonus/bonus_parse_args2.c ./bonus/bonus_utils.c ./bonus/bonus_lst_utils.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

bonus: $(BONUS_NAME)
	
clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C libft clean
fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	make -C libft fclean
re: fclean all

$(BONUS_NAME): $(BONUS_OBJS)
	make -C libft
	$(CC) -o $@ $^ libft/libft.a

$(NAME): $(OBJS)
	make -C libft 
	# $(CC) $(OBJS) libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	$(CC) $(OBJS) libft/libft.a minilibx_opengl_20191021/libmlx.a -framework OpenGL -framework AppKit -o $(NAME)


%.o: %.c
	$(CC) -Imlx -c $< -o $@

.PHONY: all clean fclean re
