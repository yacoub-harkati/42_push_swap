/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:10:43 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/02 12:42:47 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_nodes(t_stack_node **a, t_stack_node **b)
{
	set_current_position(*a);
	set_current_position(*b);
	set_target_node(*a, *b);
	set_price(*a, *b);
	set_cheapest_node(*b);
}

void	move_nodes(t_stack_node **a, t_stack_node **b, bool checker)
{
	t_stack_node	*cheapest_node;

	cheapest_node = find_cheapest(*b);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rboth(a, b, cheapest_node, checker);
	else if (!cheapest_node->above_median
		&& !cheapest_node->target_node->above_median)
		rrboth(a, b, cheapest_node, checker);
	finish_rotation(a, cheapest_node->target_node, 'a', checker);
	finish_rotation(b, cheapest_node, 'b', checker);
	pa(a, b, checker);
}

void	push_swap(t_stack_node **a, t_stack_node **b, bool checker)
{
	int len_a;

	len_a = stack_size(*a);
	if (len_a <= 250)
		sort_two_fifty(a, b, checker);
	else
		sort_big(a, b, checker);
}

void sort_big(t_stack_node **a, t_stack_node **b, bool checker)
{
	(void)a;
	(void)b;
	(void)checker;
	
	printf("To do: sort bigger numbers more than 250");
}