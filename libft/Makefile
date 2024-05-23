CC = gcc -Wall -Wextra -Werror
NAME = libft.a
SRCS = get_next_line_utils.c get_next_line.c ft_printf.c ft_print_format.c ft_print_format2.c ft_itoax.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJECT = $(SRCS:.c=.o)
BONUS_OBJECT = $(BONUS_SRCS:.c=.o)

ifdef WITH_BONUS
	OBJECTS = $(OBJECT) $(BONUS_OBJECT)
else
	OBJECTS = $(OBJECT)
endif

all: $(NAME)

bonus:
	sleep 1
	make WITH_BONUS=1 all

clean:
	rm -f $(OBJECT) $(BONUS_OBJECT)
fclean: clean
	rm -f $(NAME)
re: fclean all

$(NAME): $(OBJECTS)
	ar rc $@ $^

%.o: %.c
	$(CC) -c $< -o $@

.PHONY: all clean fclean re bonus
