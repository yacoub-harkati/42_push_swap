/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:13:15 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/11 15:20:43 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node *find_min_node(t_stack_node *node)
{
	t_stack_node *target_node;
	int min_value;


	min_value = INT_MAX;
	target_node = node;
	while(node)
	{
		if (node->value < min_value)
		{
			min_value = node->value;
			target_node = node;
		}
		node = node->next;
	}
	return (target_node);
}

t_stack_node *find_max_node(t_stack_node *node)
{
	t_stack_node *target_node;
	int min_value;

	min_value = INT_MIN;
	target_node = node;
	while(node)
	{
		if (node->value > min_value)
		{
			min_value = node->value;
			target_node = node;
		}
		node = node->next;
	}
	return (target_node);
}
