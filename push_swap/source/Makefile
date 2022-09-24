INC_DIR	=	../include

LIB_DIR	=	../libft

BONUS_DIR=	../bonus

OBJ_DIR	=	../objects

SRCS	=	error.c\
			args_manager.c\
			stacks_utils.c\
			stack_moves.c\
			stack_moves2.c\
			normal_sort.c\
			algorithm_utils.c\
			by_chunks.c\
			push_swap.c\

RM		=	rm -f

CC		=	gcc

OBJS	=	$(OBJ_DIR)/error.o\
			$(OBJ_DIR)/args_manager.o\
			$(OBJ_DIR)/stacks_utils.o\
			$(OBJ_DIR)/stack_moves.o\
			$(OBJ_DIR)/stack_moves2.o\
			$(OBJ_DIR)/normal_sort.o\
			$(OBJ_DIR)/algorithm_utils.o\
			$(OBJ_DIR)/by_chunks.o\
			$(OBJ_DIR)/push_swap.o\


CFLAGS	=	-Wall -Werror -Wextra -I$(INC_DIR)

NAME	=	push_swap

all: $(NAME) 

$(NAME): $(OBJS)
	make -C $(LIB_DIR)
	$(CC) $(CFLAGS) $(OBJ_DIR)/$(OBJS) $(LIB_DIR)/libft.a -o $(NAME)
	make -C $(BONUS_DIR)

$(OBJ_DIR)/%.o : %.c
	mkdir -p $(OBJ_DIR)
	$(CC) -c -MD $(CFLAGS) $< -o $@

-include $(OBJ_DIR)/*.d

clean:
	@$(RM) -r $(OBJ_DIR)
	@make clean -sC $(LIB_DIR)
	@make clean -sC $(BONUS_DIR)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -sC $(LIB_DIR)
	@make fclean -sC $(BONUS_DIR)

re: fclean all

.PHONY: all clean fclean re
