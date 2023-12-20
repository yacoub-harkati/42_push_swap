/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:10:43 by yaharkat          #+#    #+#             */
/*   Updated: 2023/12/20 19:10:17 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node, bool checker)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rr(a, b, checker);
	set_current_position(*a);
	set_current_position(*b);
}

void reverse_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node, bool checker)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rrr(a, b, checker);
	set_current_position(*a);
	set_current_position(*b);
}

void finish_rotation(t_stack_node **lst, t_stack_node *target_node, char stack, bool checker)
{
	if (stack == 'a')
	{
		if (target_node->above_median)
		{
			while (*lst != target_node)
				ra(lst, checker);
		}
		else
		{
			while (*lst != target_node)
				rra(lst, checker);
		}
	}
	else if (stack == 'b')
	{
		if (target_node->above_median)
		{
			while (*lst != target_node)
				rb(lst, checker);
		}
		else
		{
			while (*lst != target_node)
				rrb(lst, checker);
		}
	}
}