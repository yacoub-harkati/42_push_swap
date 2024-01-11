/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_apply_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:56:37 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/11 15:38:51 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	apply_rarb(t_stack_node **a, t_stack_node **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->value != c && get_pos_b(*b, c) > 0)
			rr(a, b, 0);
		while ((*a)->value != c)
			ra(a, 0);
		while (get_pos_b(*b, c) > 0)
			rb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while ((*b)->value != c && get_pos_a(*a, c) > 0)
			rr(a, b, 0);
		while ((*b)->value != c)
			rb(b, 0);
		while (get_pos_a(*a, c) > 0)
			ra(a, 0);
		pa(a, b, 0);
	}
	return (-1);
}

int	apply_rrarrb(t_stack_node **a, t_stack_node **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->value != c && get_pos_b(*b, c) > 0)
			rrr(a, b, 0);
		while ((*a)->value != c)
			rra(a, 0);
		while (get_pos_b(*b, c) > 0)
			rrb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while ((*b)->value != c && get_pos_a(*a, c) > 0)
			rrr(a, b, 0);
		while ((*b)->value != c)
			rrb(b, 0);
		while (get_pos_a(*a, c) > 0)
			rra(a, 0);
		pa(a, b, 0);
	}
	return (-1);
}

int	apply_rrarb(t_stack_node **a, t_stack_node **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->value != c)
			rra(a, 0);
		while (get_pos_b(*b, c) > 0)
			rb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while (get_pos_a(*a, c) > 0)
			rra(a, 0);
		while ((*b)->value != c)
			rb(b, 0);
		pa(a, b, 0);
	}
	return (-1);
}

int	apply_rarrb(t_stack_node **a, t_stack_node **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->value != c)
			ra(a, 0);
		while (get_pos_b(*b, c) > 0)
			rrb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while (get_pos_a(*a, c) > 0)
			ra(a, 0);
		while ((*b)->value != c)
			rrb(b, 0);
		pa(a, b, 0);
	}
	return (-1);
}
