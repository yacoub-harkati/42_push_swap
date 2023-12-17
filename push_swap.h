#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

typedef struct s_stack_node
{
	int value;
	struct s_stack_node *next;
	struct s_stack_node *prev;
} t_stack_node;

#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

char **ft_split(char const *s, char c);
long ft_atol(const char *nptr);
int ft_isdigit(int c);
size_t ft_strlcpy(char *dst, const char *src, size_t size);
char *ft_substr(char const *s, unsigned int start, size_t len);
size_t ft_strlen(const char *s);
bool check_digit(char *av);
void init_stack(t_stack_node **a, char **av, bool av_flag);
void free_matrix(char **av);
bool check_error(char *av);
bool check_duplicate(t_stack_node *a, int number);
t_stack_node *new_stack(int value);
t_stack_node *last_stack(t_stack_node *lst);
void add_back_stack(t_stack_node **lst, t_stack_node *new);
size_t stack_size(t_stack_node *lst);

#endif