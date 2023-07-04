SOURCES	=	ft_printf.c\
			converter.c\
			ft_strlen.c \
			pointerhandle.c\
			string_handle.c \
			ft_putchar.c


NAME 	=	libftprintf.a
OBJECTS	=	$(SOURCES:.c=.o)
GCCW	=	gcc	-Wall -Wextra -Werror -I./


.c.o:
	$(GCCW) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJECTS)
			ar rcs $(NAME) $(OBJECTS)

clean:		
			rm -f $(OBJECTS)

fclean:		clean
			rm -f $(NAME)

re:			fclean $(NAME)

.PHONY:	all clean fclean re