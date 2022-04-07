NAME	=	push_swap

SRCS	=	main.c\
			error.c\
			stack_utils.c\
			stack_moves.c\
			push_swap.c

RM		=	rm -f

CC		=	gcc

OBJS	=	$(SRCS:.c=.o)

FLAGS	=	-Wall -Werror -Wextra

all:	$(NAME)
$(NAME): $(OBJS) 
	$(CC) $(FLAGS) $(OBJS) $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re