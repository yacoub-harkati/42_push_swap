/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_finders.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:48:18 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/11 15:25:07 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(t_stack_node *a, int value)
{
	int		i;

	i = 0;
	while (a->value != value)
	{
		i++;
		a = a->next;
	}
	a->index = 0;
	return (i);
}

int	get_pos_a(t_stack_node *stack_a, int nbr_push)
{
	int		i;
	t_stack_node	*tmp;

	i = 1;
	if (nbr_push < stack_a->value && nbr_push > last_stack(stack_a)->value)
		i = 0;
	else if (nbr_push > find_max_node(stack_a)->value || nbr_push < find_min_node(stack_a)->value)
		i = find_index(stack_a, find_min_node(stack_a)->value);
	else
	{
		tmp = stack_a->next;
		while (stack_a->value > nbr_push || tmp->value < nbr_push)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}

int get_pos_b(t_stack_node *b, int value_push)
{
	int i;
	t_stack_node *tmp;

	i = 1;
	if (value_push > b->value && value_push < last_stack(b)->value)
		i = 0;
	else if (value_push > find_max_node(b)->value || value_push < find_min_node(b)->value)
		i = find_index(b, find_max_node(b)->value);
	else
	{
		tmp = b->next;
		while (b->value < value_push || tmp->value > value_push)
		{
			b = b->next;
			tmp = b->next;
			i++;
		}
	}
	return (i);
}