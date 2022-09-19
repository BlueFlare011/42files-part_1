SRCS	=	error.c\
			args_manager.c\
			stacks_utils.c\
			stack_moves.c\
			stack_moves2.c\
			algorithms/normal_sort.c\
			algorithms/algorithm_utils.c\
			algorithms/by_chunks.c\
			push_swap.c\

BNS_SRC	=	bonus/my_checker.c\
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

CFLAGS	=	-Wall -Werror -Wextra

NAME	=	push_swap

BONUS	=	my_checker

all: $(NAME) $(BONUS)

$(NAME): $(OBJS) $(BNS_OBJ)
	@make -C libft
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

$(BONUS): $(BNS_OBJ)
	$(CC) $(CFLAGS) $(BNS_OBJ) libft/libft.a -o $(BONUS)

clean:
	@$(RM) $(OBJS)
	@$(RM) $(BNS_OBJ)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(BONUS)
	@make fclean -sC libft

re: fclean all

.PHONY: all clean fclean re bonus
