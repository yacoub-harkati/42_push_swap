/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:40:22 by yaharkat          #+#    #+#             */
/*   Updated: 2023/12/19 16:21:00 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node *find_highest(t_stack_node *lst)
{
	t_stack_node *tmp;

	tmp = lst;
	while (lst)
	{
		if (lst->value > tmp->value)
			tmp = lst;
		lst = lst->next;
	}
	return tmp;
}

t_stack_node *find_smallest(t_stack_node *lst)
{
	t_stack_node *tmp;

	tmp = lst;
	while (lst)
	{
		if (lst->value < tmp->value)
			tmp = lst;
		lst = lst->next;
	}
	return tmp;
}

void set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node *current_a;
	t_stack_node *target_node;
	long best_match_index;

	current_a = a;
	best_match_index = LONG_MAX;
	while(b)
	{
		while (current_a)
		{
			if (current_a->value > b->value && current_a->value < best_match_index)
			{
				target_node = current_a;
				best_match_index = current_a->value;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = find_smallest(a);
		else 
			b->target_node = target_node;
		b = b->next;
	}
}