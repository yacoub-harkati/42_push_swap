#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct s_stack_node
{
	int value;
	int current_position;
	int price;
	bool above_median;
	bool cheapest;
	struct s_stack_node *target_node;
	struct s_stack_node *next;
	struct s_stack_node *prev;
} t_stack_node;

char **ft_split(char const *s, char c);
long ft_atol(const char *nptr);
int ft_isdigit(int c);
size_t ft_strlcpy(char *dst, const char *src, size_t size);
char *ft_substr(char const *s, unsigned int start, size_t len);
size_t ft_strlen(const char *s);
bool check_digit(char *av);
void init_stack(t_stack_node **a, char **av, bool av_flag);
void free_matrix(char **av);
bool check_error(t_stack_node **a, char *av, long number);
bool check_duplicate(t_stack_node *a, int number);
bool check_int(long number);
t_stack_node *new_stack(int value);
t_stack_node *last_stack(t_stack_node *lst);
void add_back_stack(t_stack_node **lst, t_stack_node *new);
size_t stack_size(t_stack_node *lst);
void ft_putstr_fd(char *s, int fd);
char *ft_strdup(const char *s);
void free_stack(t_stack_node **lst);
bool is_stack_sorted(t_stack_node *lst);
void add_front_stack(t_stack_node **lst, t_stack_node *new);
void rrr(t_stack_node **a, t_stack_node **b, bool checker);
void rra(t_stack_node **a, bool checker);
void rrb(t_stack_node **b, bool checker);
void rr(t_stack_node **a, t_stack_node **b, bool checker);
void ra(t_stack_node **a, bool checker);
void rb(t_stack_node **b, bool checker);
void sa(t_stack_node **a, bool checker);
void sb(t_stack_node **b, bool checker);
void ss(t_stack_node **a, t_stack_node **b, bool checker);
void pa(t_stack_node **a, t_stack_node **b, bool checker);
void pb(t_stack_node **a, t_stack_node **b, bool checker);
void swap(t_stack_node **lst);
void rotate(t_stack_node **lst);
void reverse_rotate(t_stack_node **lst);
void push(t_stack_node **dest, t_stack_node **src);
t_stack_node *find_highest(t_stack_node *lst);
t_stack_node *find_smallest(t_stack_node *lst);
void sort_tree(t_stack_node **lst, bool checker);
void push_swap(t_stack_node **a, t_stack_node **b, bool checker);
void set_cheapest_node(t_stack_node *b);
void set_price(t_stack_node *a, t_stack_node *b);
void set_current_position(t_stack_node *lst);
void set_target_node(t_stack_node *a, t_stack_node *b);
void init_nodes(t_stack_node **a, t_stack_node **b);
t_stack_node *find_cheapest(t_stack_node *b);

#endif