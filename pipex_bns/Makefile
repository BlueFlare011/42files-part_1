SRCS	=	main.c\
			error.c\
			forking.c\
			utils.c\
			commands.c\

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

OBJS	=	$(SRCS:.c=.o)

NAME	=	pipex

RM		=	rm -f

all: $(NAME)
$(NAME): $(OBJS)
	@make -C Libft
	$(CC) $(CFLAGS) $(OBJS) Libft/libft.a -o $(NAME)

clean:
	@$(RM) $(OBJS)
	@make clean -sC Libft

fclean: clean
	@$(RM) $(NAME)
	@make fclean -sC Libft

re: fclean all

.PHONY: all clean fclean re