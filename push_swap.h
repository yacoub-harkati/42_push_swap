#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

typedef s_stack_node
{
	int data;
	struct s_stack_node *next;
	struct s_stack_node *prev;
}
t_stack_node;

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

int	ft_atol(const char *nptr);

#endif