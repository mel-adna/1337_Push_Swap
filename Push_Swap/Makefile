NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC_DIR = src
LIBFT_DIR = libft
PRINTF_DIR = ft_printf
GNL_DIR = get_next_line

SRC = $(SRC_DIR)/main.c \
      $(SRC_DIR)/swap.c \
      $(SRC_DIR)/parse.c \
      $(SRC_DIR)/rotate.c \
      $(SRC_DIR)/reverse_rotate.c \
      $(SRC_DIR)/push.c

OBJ = $(SRC:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
GNL = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c

all: $(LIBFT) $(PRINTF) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(GNL) $(LIBFT) $(PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
