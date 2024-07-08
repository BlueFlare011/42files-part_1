SRCS	=	so_long.c\
			window_settings.c\
			move_control.c\
			so_long_utils.c\
			map_validator.c\
			map_validator_utils.c\
			get_next_line/get_next_line.c\
			get_next_line/get_next_line_utils.c\
			libutils/ft_strncmp.c\
			libutils/ft_split.c\
			libutils/ft_strjoin.c\

OBJS	=			$(SRCS:.c=.o)

CC		=			gcc

RM		=			rm -f

CFLAGS	=			-Wall -Werror -Wextra

NAME	=			so_long


all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) libmlx.a -lXext -lX11 -lm -o $(NAME)

clean:
	$(RM) $(OBJS) $(OBJSBONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re