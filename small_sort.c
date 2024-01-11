/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:11:02 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/11 15:18:32 by yaharkat         ###   ########.fr       */
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

void mini_sort(t_stack_node **a, t_stack_node **b, bool checker)
{
	int				len_a;
	t_stack_node	*smallest_node;

	len_a = stack_size(*a);
	while (len_a-- > 3 && !is_stack_sorted(*a))
		pb(a, b, checker);
	sort_three(a, checker);
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