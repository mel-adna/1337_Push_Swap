NAME = ../checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
RM = rm -f

SRC_DIR = src
LIBFT_DIR = ../libft

SRC = checker.c  checker_utils.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
	../stack_utils.c ../algo_sorting.c ../sort_stacks.c ../push.c ../stack_utils01.c \
	../swap.c ../rotate.c ../reverse_rotate.c ../stack_check.c operation.c \

OBJ = $(SRC:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re