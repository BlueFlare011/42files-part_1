SRCS	=	main.c

OBJS	=			$(SRCS:.c=.o)

CC		=			gcc

RM		=			rm -f

AR		=			ar rcs

CFLAGS	=			-Wall -Werror -Wextra

NAME	=			so_long


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(RM) $(OBJS) $(OBJSBONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean bonus re