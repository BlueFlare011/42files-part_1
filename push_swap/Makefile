SRCS	=	Libft/ft_atoi.c\
			Libft/ft_strlen.c\
			Libft/ft_strdup.c\
			Libft/ft_split.c\
			Libft/ft_strjoin.c\
			Libft/ft_strncmp.c\
			Libft/ft_isdigit.c\
			error.c\
			args_manager.c\
			stacks_utils.c\
			stack_moves.c\
			push_swap_utils.c\
			push_swap.c\

RM		=	rm -f

CC		=	gcc

OBJS	=	$(SRCS:.c=.o)

FLAGS	=	-Wall -Werror -Wextra

NAME	=	push_swap

all: $(NAME)
$(NAME): $(OBJS) 
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re