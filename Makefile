NAME = libftprintf.a

SRCS = ft_allput.c ft_printf.c ft_printadd.c ft_ltoa.c

# Objects
OBJS = $(SRCS:.c=.o)
AR = ar
# Compiler
CC = cc
CFLAGS = -Wall \
		 -Wextra \
		 -Werror \
		 -I ./


# CFLAGS = -I ./

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) -rcs $@ $?

%.o: %.c
	$(CC) -c $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
