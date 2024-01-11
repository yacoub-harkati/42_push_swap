/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_calc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:13:15 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/11 15:25:07 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int calc_rarb(t_stack_node *a, t_stack_node *b, int c)
{
	int i;

	i = get_pos_b(b, c);
	if (i < find_index(a, c))
		i = find_index(a, c);
	return (i);
}

int calc_rrarrb(t_stack_node *a, t_stack_node *b, int c)
{
	int i;

	i = 0;
	if (get_pos_b(b, c))
		i = stack_size(b) - get_pos_b(b, c);
	if ((i < (stack_size(a) - find_index(a, c))) && find_index(a, c))
		i = stack_size(a) - find_index(a, c);
	return (i);
}

int calc_rrarb(t_stack_node *a, t_stack_node *b, int c)
{
	int i;

	i = 0;
	if (find_index(a, c))
		i = stack_size(a) - find_index(a, c);
	i = get_pos_b(b, c) + i;
	return (i);
}

int calc_rarrb(t_stack_node *a, t_stack_node *b, int c)
{
	int i;

	i = 0;
	if (get_pos_b(b, c))
		i = stack_size(b) - get_pos_b(b, c);
	i = find_index(a, c) + i;
	return (i);
}
int calc_rotate_type(t_stack_node *a, t_stack_node *b)
{
	int i;
	t_stack_node *tmp;

	tmp = a;
	i = calc_rrarrb(a, b, a->value);
	while (tmp)
	{
		if (i > calc_rarb(a, b, tmp->value))
			i = calc_rarb(a, b, tmp->value);
		if (i > calc_rrarrb(a, b, tmp->value))
			i = calc_rrarrb(a, b, tmp->value);
		if (i > calc_rarrb(a, b, tmp->value))
			i = calc_rarrb(a, b, tmp->value);
		if (i > calc_rrarb(a, b, tmp->value))
			i = calc_rrarb(a, b, tmp->value);
		tmp = tmp->next;
	}
	return (i);
}

int calc_rarb_a(t_stack_node *a, t_stack_node *b, int c)
{
	int i;

	i = get_pos_a(a, c);
	if (i < find_index(b, c))
		i = find_index(b, c);
	return (i);
}

int calc_rrarrb_a(t_stack_node *a, t_stack_node *b, int c)
{
	int i;

	i = 0;
	if (get_pos_a(a, c))
		i = stack_size(a) - get_pos_a(a, c);
	if ((i < (stack_size(b) - find_index(b, c))) && find_index(b, c))
		i = stack_size(b) - find_index(b, c);
	return (i);
}

int calc_rarrb_a(t_stack_node *a, t_stack_node *b, int c)
{
	int i;

	i = 0;
	if (find_index(b, c))
		i = stack_size(b) - find_index(b, c);
	i = get_pos_a(a, c) + i;
	return (i);
}

int calc_rrarb_a(t_stack_node *a, t_stack_node *b, int c)
{
	int i;

	i = 0;
	if (get_pos_a(a, c))
		i = stack_size(a) - get_pos_a(a, c);
	i = find_index(b, c) + i;
	return (i);
}

int ft_rotate_type_ba(t_stack_node *a, t_stack_node *b)
{
	int i;
	t_stack_node *tmp;

	tmp = b;
	i = calc_rrarrb_a(a, b, b->value);
	while (tmp)
	{
		if (i > calc_rarb_a(a, b, tmp->value))
			i = calc_rarb_a(a, b, tmp->value);
		if (i > calc_rrarrb_a(a, b, tmp->value))
			i = calc_rrarrb_a(a, b, tmp->value);
		if (i > calc_rarrb_a(a, b, tmp->value))
			i = calc_rarrb_a(a, b, tmp->value);
		if (i > calc_rrarb_a(a, b, tmp->value))
			i = calc_rrarb_a(a, b, tmp->value);
		tmp = tmp->next;
	}
	return (i);
}