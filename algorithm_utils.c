/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:10:43 by yaharkat          #+#    #+#             */
/*   Updated: 2023/12/21 13:31:46 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rboth(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node, bool checker)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rr(a, b, checker);
	set_current_position(*a);
	set_current_position(*b);
}

void rrboth(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node, bool checker)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rrr(a, b, checker);
	set_current_position(*a);
	set_current_position(*b);
}

void finish_rotation(t_stack_node **lst, t_stack_node *target_node, char stack, bool checker)
{
	while (*lst != target_node)
	{
		if (target_node->above_median)
		{	
		if (stack == 'a')
			ra(lst, checker);
		else
			rb(lst, checker);
		}
		else
		{
			if (stack == 'a')
				rra(lst, checker);
			else
				rrb(lst, checker);
		}
	}
}
