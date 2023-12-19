/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:19:56 by yaharkat          #+#    #+#             */
/*   Updated: 2023/12/19 18:34:28 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node *current_a;
	t_stack_node *target_node;
	long best_match_index;

	current_a = a;
	best_match_index = INT_MAX;
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
		if (best_match_index == INT_MAX)
			b->target_node = find_smallest(a);
		else 
			b->target_node = target_node;
		b = b->next;
	}
}

void set_current_position(t_stack_node *lst)
{
	int i;
	int median;

	median = stack_size(lst) / 2;
	i = 0;
	while (lst)
	{
		lst->current_position = i;
		if (i <= median)
			lst->above_median = true;
		else
			lst->above_median = false;
		i++;
		lst = lst->next;
	}
}

void set_price(t_stack_node *a, t_stack_node *b)
{
	int len_a;
	int len_b;

	len_a = stack_size(a);
	len_b = stack_size(b);
	while (b)
	{
		b->price = b->current_position;
		if (!(b->above_median))
			b->price += len_b - b->current_position;
		if (b->target_node->above_median)
			b->price += b->target_node->current_position;
		else
			b->price += len_a - b->target_node->current_position;
		b = b->next;
	}
}

void set_cheapest_node(t_stack_node *b)
{
	t_stack_node *tmp;
	int cheapest_price;

	tmp = b;
	cheapest_price = INT_MAX;
	while (b)
	{
		if (b->price < cheapest_price)
			cheapest_price = b->price;
		b = b->next;
	}
	b = tmp;
	while (b)
	{
		if (b->price == cheapest_price)
			b->cheapest = true;
		else
			b->cheapest = false;
		b = b->next;
	}
}