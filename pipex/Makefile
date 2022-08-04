SRCS	=	main.c\
			error.c\
			forking.c\
			commands.c\

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

OBJS	=	$(SRCS:.c=.o)

NAME	=	pipex

RM		=	rm -f

all: $(NAME)
$(NAME): $(OBJS)
	@make -C Libft
	$(CC) $(CFLAGS) -g $(OBJS) Libft/libft.a -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	make fclean -sC Libft

re: fclean all

.PHONY: all clean fclean re