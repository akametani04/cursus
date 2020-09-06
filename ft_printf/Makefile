NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBS = ar -rc
RM = rm -f
SRCS = format.c ft_printf.c libft.c putint.c int.c putnum.c putstr.c ui_hex.c
OBJS = ${SRCS:.c=.o}

$(NAME): $(OBJS)
	$(LIBS) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY	: all clean fclean re
