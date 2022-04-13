SRCS	=	so_long.c\
			window_settings.c\
			move_control.c\
			images_settings.c\
			map_validator.c\
			get_next_line/get_next_line.c\
			get_next_line/get_next_line_utils.c\
			libutils/ft_strncmp.c\
			libutils/ft_split.c\
			libutils/ft_strjoin.c\

OBJS	=			$(SRCS:.c=.o)

CC		=			gcc

RM		=			rm -f

AR		=			ar rcs

CFLAGS	=			-Wall -Werror -Wextra -g

NAME	=			so_long


all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(RM) $(OBJS) $(OBJSBONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean bonus re