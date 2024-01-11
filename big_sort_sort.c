/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:13:15 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/11 15:41:46 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b_till_3(t_stack_node **a, t_stack_node **b)
{
	int				i;
	t_stack_node	*tmp;

	while (stack_size(*a) > 3 && !is_stack_sorted(*a))
	{
		tmp = *a;
		i = calc_rotate_type(*a, *b);
		while (i >= 0)
		{
			if (i == calc_rarb(*a, *b, tmp->value))
				i = apply_rarb(a, b, tmp->value, 'a');
			else if (i == calc_rrarrb(*a, *b, tmp->value))
				i = apply_rrarrb(a, b, tmp->value, 'a');
			else if (i == calc_rarrb(*a, *b, tmp->value))
				i = apply_rarrb(a, b, tmp->value, 'a');
			else if (i == calc_rrarb(*a, *b, tmp->value))
				i = apply_rrarb(a, b, tmp->value, 'a');
			else
				tmp = tmp->next;
		}
	}
}

t_stack_node	**sort_a(t_stack_node **a, t_stack_node **b)
{
	int				i;
	t_stack_node	*tmp;

	while (*b)
	{
		tmp = *b;
		i = ft_rotate_type_ba(*a, *b);
		while (i >= 0)
		{
			if (i == calc_rarb_a(*a, *b, tmp->value))
				i = apply_rarb(a, b, tmp->value, 'b');
			else if (i == calc_rarrb_a(*a, *b, tmp->value))
				i = apply_rarrb(a, b, tmp->value, 'b');
			else if (i == calc_rrarrb_a(*a, *b, tmp->value))
				i = apply_rrarrb(a, b, tmp->value, 'b');
			else if (i == calc_rrarb_a(*a, *b, tmp->value))
				i = apply_rrarb(a, b, tmp->value, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (a);
}

t_stack_node	**sort_b(t_stack_node **a, t_stack_node **b, bool checker)
{
	if (stack_size(*a) > 3 && !is_stack_sorted(*a))
		pb(a, b, checker);
	if (stack_size(*a) > 3 && !is_stack_sorted(*a))
		pb(a, b, checker);
	if (stack_size(*a) > 3 && !is_stack_sorted(*a))
		sort_b_till_3(a, b);
	if (!is_stack_sorted(*a))
		sort_three(a, checker);
	return (b);
}
