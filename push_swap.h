#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

char					**ft_split(char const *s, char c);

#endif