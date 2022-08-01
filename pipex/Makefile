SRCS	=	main.c\
			error.c\
			forking.c\
			commands.c\
			Libft/ft_strlen.c\
			Libft/ft_strlcpy.c\
			Libft/ft_strjoin.c\
			Libft/ft_strncmp.c\
			Libft/ft_substr.c\
			Libft/ft_split.c\

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

OBJS	=	$(SRCS:.c=.o)

NAME	=	pipex

RM		=	rm -f

all: $(NAME)
$(NAME): $(OBJS) 
	$(CC) $(FLAGS) -g $(OBJS) -o $(NAME) 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re