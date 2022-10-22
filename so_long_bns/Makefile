SRCS	=	so_long.c\
			window_settings.c\
			move_control.c\
			so_long_utils.c\
			map_validator.c\
			map_validator_utils.c\
			get_next_line/get_next_line.c\
			get_next_line/get_next_line_utils.c\

OBJS	=			$(SRCS:.c=.o)

CC		=			gcc

RM		=			rm -f

CFLAGS	=			-Wall -Werror -Wextra

NAME	=			so_long


all: $(NAME)
$(NAME): $(OBJS)
	@make -C Libft
	$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit Libft/libft.a -o $(NAME)

clean:
	@$(RM) $(OBJS) $(OBJSBONUS)
	@make clean -sC Libft

fclean: clean
	@$(RM) $(NAME)
	@make fclean -sC Libft

re: fclean all

.PHONY: all clean fclean re