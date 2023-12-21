/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:19:56 by yaharkat          #+#    #+#             */
/*   Updated: 2023/12/21 13:33:40 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node *current;
	t_stack_node *target_node;
	int smallest_distance;

	while (b)
	{
		current = a;
		smallest_distance = INT_MAX;
		while (current)
		{
			if (current->value > b->value && current->value < smallest_distance)
			{
				target_node = current;
				smallest_distance = current->value;
			}
			current = current->next;
		}
		if (smallest_distance == INT_MAX)
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
		lst->index = i;
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
	int lenght_a;
	int lenght_b;

	lenght_a = stack_size(a);
	lenght_b = stack_size(b);
	while (b)
	{
		if (b->above_median)
			b->price = b->index;
		if (!(b->above_median))
			b->price = lenght_b - b->index;
		if (b->target_node->above_median)
			b->price += b->target_node->index;
		else
			b->price += lenght_a - b->target_node->index;
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