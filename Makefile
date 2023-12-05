CC = cc
CFLAGS = -Wall -Wextra -Werror -I./header/
RM = rm -rf
NAME = libftprintf.a

SRCS = src/ft_printf.c utils/ft_digits_utils.c utils/ft_strings_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

