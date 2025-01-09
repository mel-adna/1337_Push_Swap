SRCS = ft_printf.c found_s.c found_c.c found_d_i_u.c found_x.c found_p.c 
OBJC = $(SRCS:.c=.o)
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJC)
	ar rcs $(NAME) $(OBJC)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJC)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean