/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_apply_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:56:37 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/11 15:25:07 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	apply_rarb(t_stack_node **a, t_stack_node **b, int c, char s, bool checker)
{
	if (s == 'a')
	{
		while ((*a)->value != c && get_pos_b(*b, c) > 0)
			rr(a, b, checker);
		while ((*a)->value != c)
			ra(a, checker);
		while (get_pos_b(*b, c) > 0)
			rb(b, checker);
		pb(a, b, checker);
	}
	else
	{
		while ((*b)->value != c && get_pos_a(*a, c) > 0)
			rr(a, b, checker);
		while ((*b)->value != c)
			rb(b, checker);
		while (get_pos_a(*a, c) > 0)
			ra(a, checker);
		pa(a, b, checker);
	}
	return (-1);
}

int	apply_rrarrb(t_stack_node **a, t_stack_node **b, int c, char s, bool checker)
{
	if (s == 'a')
	{
		while ((*a)->value != c && get_pos_b(*b, c) > 0)
			rrr(a, b, checker);
		while ((*a)->value != c)
			rra(a, checker);
		while (get_pos_b(*b, c) > 0)
			rrb(b, checker);
		pb(a, b, checker);
	}
	else
	{
		while ((*b)->value != c && get_pos_a(*a, c) > 0)
			rrr(a, b, checker);
		while ((*b)->value != c)
			rrb(b, checker);
		while (get_pos_a(*a, c) > 0)
			rra(a, checker);
		pa(a, b, checker);
	}
	return (-1);
}

int	apply_rrarb(t_stack_node **a, t_stack_node **b, int c, char s, bool checker)
{
	if (s == 'a')
	{
		while ((*a)->value != c)
			rra(a, checker);
		while (get_pos_b(*b, c) > 0)
			rb(b, checker);
		pb(a, b, checker);
	}
	else
	{
		while (get_pos_a(*a, c) > 0)
			rra(a, checker);
		while ((*b)->value != c)
			rb(b, checker);
		pa(a, b, checker);
	}
	return (-1);
}

int	apply_rarrb(t_stack_node **a, t_stack_node **b, int c, char s, bool checker)
{
	if (s == 'a')
	{
		while ((*a)->value != c)
			ra(a, checker);
		while (get_pos_b(*b, c) > 0)
			rrb(b, checker);
		pb(a, b, checker);
	}
	else
	{
		while (get_pos_a(*a, c) > 0)
			ra(a, checker);
		while ((*b)->value != c)
			rrb(b, checker);
		pa(a, b, checker);
	}
	return (-1);
}
