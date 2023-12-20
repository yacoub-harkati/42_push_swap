/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:10:43 by yaharkat          #+#    #+#             */
/*   Updated: 2023/12/20 19:09:48 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_nodes(t_stack_node **a, t_stack_node **b)
{
	set_current_position(*a);
	set_current_position(*b);
	set_target_node(*a, *b);
	set_price(*a, *b);
	set_cheapest_node(*b);
}

void move_nodes(t_stack_node **a, t_stack_node **b, bool checker)
{
	t_stack_node *cheapest_node;

	cheapest_node = find_cheapest(*b);
	if (cheapest_node->above_median)
		rotate_both(a, b, cheapest_node, checker);
	else 
		reverse_rotate_both(a, b, cheapest_node, checker);
	finish_rotation(a, cheapest_node->target_node, 'a', checker);
	finish_rotation(b, cheapest_node, 'b', checker);
	pa(a, b, checker);
}

void push_swap(t_stack_node **a, t_stack_node **b, bool checker)
{
	int len_a;
	t_stack_node *smallest_node;
	
	len_a = stack_size(*a);
	while (len_a-- > 3)
		pb(a, b, checker);
	sort_tree(a, checker);
	while (*b)
	{
		init_nodes(a, b);
		move_nodes(a, b, checker);
	}
	set_current_position(*a);
	smallest_node = find_smallest(*a);
	while (*a != smallest_node)
	{
		if (smallest_node->above_median)
			ra(a, checker);
		else
			rra(a, checker);
	}
}
