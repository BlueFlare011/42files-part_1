SRCS	=	main.c

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

OBJS	=	$(SRCS:.c=.o)

NAME	=	pipex

RM		=	rm -f

all: $(NAME)
$(NAME): $(OBJS) 
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re