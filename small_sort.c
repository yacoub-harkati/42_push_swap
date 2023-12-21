/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:11:02 by yaharkat          #+#    #+#             */
/*   Updated: 2023/12/21 13:40:38 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **lst, bool checker)
{
	t_stack_node	*highest_node;

	highest_node = find_highest(*lst);
	if (*lst == highest_node)
		ra(lst, checker);
	else if ((*lst)->next == highest_node)
		rra(lst, checker);
	if ((*lst)->value > (*lst)->next->value)
		sa(lst, checker);
}

void	sort_five(t_stack_node **a, t_stack_node **b, bool checker)
{
	t_stack_node	*smallest;

	init_nodes(a, b);
	while (stack_size(*a) > 3)
	{
		smallest = find_smallest(*a);
		while (*a != smallest)
		{
			if (smallest->above_median)
				ra(a, checker);
			else
				rra(a, checker);
		}
		pb(a, b, checker);
	}
	sort_three(a, checker);
	while (*b != NULL)
		pa(a, b, checker);
}
