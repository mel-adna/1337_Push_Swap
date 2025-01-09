#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

typedef struct	s_stack_node
{
	int					value;
	int					index;

	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack_node;



#endif
