SRCS	=			main.c

OBJS	=			$(SRCS:.c=.o)

CC		=			gcc

RM		=			rm -f

CFLAGS	=			-Wall -Werror -Wextra

NAME	=			minitalk

PRINTF	=			libftprintf.a

all: $(PRINTF) $(NAME)
$(PRINTF):
	make -C ft_printf
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(RM) $(OBJS) $(OBJSBONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re