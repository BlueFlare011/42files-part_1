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
			algorithms/normal_sort.c\
			algorithms/algorithm_utils.c\
			algorithms/mirror.c\
			push_swap.c\

BNS_SRC	=	Libft/ft_atoi.c\
			Libft/ft_strlen.c\
			Libft/ft_strdup.c\
			Libft/ft_split.c\
			Libft/ft_strjoin.c\
			Libft/ft_strncmp.c\
			Libft/ft_isdigit.c\
			bonus/my_checker.c\
			bonus/args_manager.c\
			bonus/error.c\
			bonus/stacks_utils.c\
			bonus/sort_stack.c\
			bonus/stack_moves.c\
			bonus/stack_moves2.c\

RM		=	rm -f

CC		=	gcc

OBJS	=	$(SRCS:.c=.o)

BNS_OBJ	=	$(BNS_SRC:.c=.o)

FLAGS	=	-Wall -Werror -Wextra

NAME	=	push_swap

BONUS	=	bonus/checker

all: $(NAME)
$(NAME): $(OBJS) 
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS)
$(BONUS): $(BNS_OBJ)
	$(CC) $(FLAGS) $(BNS_OBJ) -o $(BONUS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

fclean_bonus: 
	$(RM) $(BNS_OBJ) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus fclean_bonus