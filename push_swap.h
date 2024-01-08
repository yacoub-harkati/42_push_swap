/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:40:11 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/08 23:26:44 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1
# define BUFFER_SIZE 1

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "libft/libft.h"

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

typedef struct s_bigsort_data 
{
	int	*sort_array;
	int	**chunks;
	int *chucks_count;
	int stack_size;
}						t_bigsort_data;

void	print_chunks(t_bigsort_data *bs_data);
void	init_chunks(t_bigsort_data *bs_data);
void	add_to_chunk(int **chunks, int *chunk_count, int chunk_index, int value);
int		**get_chunks(t_bigsort_data *bs_data);
int		*sort_array(int *unsorted_arr, int size);
int		*get_sorted_num_buffer(t_stack_node *a);
void	init_bs_data(t_bigsort_data *bs_data, t_stack_node *a);
bool	is_inside_chunk(int *chunk, int value, int size);
t_stack_node *find_inside_chunk(t_stack_node *a, t_bigsort_data *bs_data, int *chunk);
t_stack_node *find_rv_inside_chunk(t_stack_node *a, t_bigsort_data *bs_data, int *chunk);


bool					check_digit(char *av);
void					init_stack(t_stack_node **a, char **av, bool av_flag);
void					free_matrix(char **av);
bool					check_error(t_stack_node **a, char *av, long number);
bool					check_duplicate(t_stack_node *a, int number);
bool					check_int(long number);
t_stack_node			*new_stack(int value);
t_stack_node			*last_stack(t_stack_node *lst);
void					add_back_stack(t_stack_node **lst, t_stack_node *new);
size_t					stack_size(t_stack_node *lst);
void					free_stack(t_stack_node **lst);
bool					is_stack_sorted(t_stack_node *lst);
void					add_front_stack(t_stack_node **lst, t_stack_node *new);
void					rrr(t_stack_node **a, t_stack_node **b, bool checker);
void					rra(t_stack_node **a, bool checker);
void					rrb(t_stack_node **b, bool checker);
void					rr(t_stack_node **a, t_stack_node **b, bool checker);
void					ra(t_stack_node **a, bool checker);
void					rb(t_stack_node **b, bool checker);
void					sa(t_stack_node **a, bool checker);
void					sb(t_stack_node **b, bool checker);
void					ss(t_stack_node **a, t_stack_node **b, bool checker);
void					pa(t_stack_node **a, t_stack_node **b, bool checker);
void					pb(t_stack_node **a, t_stack_node **b, bool checker);
void					swap(t_stack_node **lst);
void					rotate(t_stack_node **lst);
void					reverse_rotate(t_stack_node **lst);
void					push(t_stack_node **dest, t_stack_node **src);
t_stack_node			*find_highest(t_stack_node *lst);
t_stack_node			*find_smallest(t_stack_node *lst);
void					push_swap(t_stack_node **a, t_stack_node **b,
							bool checker);
void					set_cheapest_node(t_stack_node *b);
void					set_price(t_stack_node *a, t_stack_node *b);
void					set_current_position(t_stack_node *lst);
void					set_target_node(t_stack_node *a, t_stack_node *b);
void					init_nodes(t_stack_node **a, t_stack_node **b);
t_stack_node			*find_cheapest(t_stack_node *b);
void					rboth(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest_node, bool checker);
void					rrboth(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest_node, bool checker);
void					finish_rotation(t_stack_node **lst,
							t_stack_node *target_node, char stack,
							bool checker);
void					sort_five(t_stack_node **a, t_stack_node **b,
							bool checker);
void					sort_three(t_stack_node **lst, bool checker);
void					sort_two_fifty(t_stack_node **a, t_stack_node **b, bool checker);
void					sort_big(t_stack_node **a, t_stack_node **b, bool checker);
void					move_nodes(t_stack_node **a, t_stack_node **b, bool checker);
#endif