NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

SRC_DIR = src
LIBFT_DIR = libft
BONUS_DIR = bonus

SRC = push_swap.c stack_check.c stack_utils.c algo_sorting.c sort_stacks.c \
	swap.c rotate.c reverse_rotate.c stack_utils01.c push.c \


OBJ = $(SRC:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a

BONUS = $(BONUS_DIR)/checker

all: $(LIBFT) $(NAME)

bonus: $(LIBFT) $(BONUS)

$(BONUS):
	@$(MAKE) -C $(BONUS_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(BONUS_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(BONUS_DIR) fclean

re: fclean all

.PHONY: all clean fclean re