NAME	=	libftprintf.a

SRCS	=	ft_printf.c\
			ft_hexabase.c\
			ft_hexapointer.c

SRCH	=	ft_printf.h

RM		=	rm -f

AR		=	ar rcs

OBJS	=	$(SRCS:.c=.o)

FLAGS	=	-Wall -Werror -Wextra

all:	$(NAME)
$(NAME): $(OBJS) $(SRCH)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re