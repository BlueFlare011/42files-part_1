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

ifeq ($(shell uname), Linux)
	MLX	= 			mlx_linux/

	MLXNAME	=		mlx_linux/libmlx.a

	FRAMEWORK	=	-lXext -lX11 -lm

else
	MLX		=		mlx/

#	//MLXNAME	=		libmlx.dylib

	FRAMEWORK	=	$(addprefix -framework , \
					OpenGL \
					AppKit) \
					-lmlx
endif

all: $(NAME)
$(NAME): $(OBJS)
	@make -C Libft
	$(CC) $(CFLAGS) $(OBJS) $(MLXNAME) $(FRAMEWORK) Libft/libft.a -o $(NAME) -fsanitize=address

clean:
	@$(RM) $(OBJS) $(OBJSBONUS)
	@make clean -sC Libft

fclean: clean
	@$(RM) $(NAME)
	@make fclean -sC Libft

re: fclean all

.PHONY: all clean fclean re