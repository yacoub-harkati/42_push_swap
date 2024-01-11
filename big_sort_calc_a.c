/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_calc_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:13:15 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/11 15:44:58 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_rarb_a(t_stack_node *a, t_stack_node *b, int c)
{
	int	i;

	i = get_pos_a(a, c);
	if (i < find_index(b, c))
		i = find_index(b, c);
	return (i);
}

int	calc_rrarrb_a(t_stack_node *a, t_stack_node *b, int c)
{
	int	i;

	i = 0;
	if (get_pos_a(a, c))
		i = stack_size(a) - get_pos_a(a, c);
	if ((i < (stack_size(b) - find_index(b, c))) && find_index(b, c))
		i = stack_size(b) - find_index(b, c);
	return (i);
}

int	calc_rarrb_a(t_stack_node *a, t_stack_node *b, int c)
{
	int	i;

	i = 0;
	if (find_index(b, c))
		i = stack_size(b) - find_index(b, c);
	i = get_pos_a(a, c) + i;
	return (i);
}

int	calc_rrarb_a(t_stack_node *a, t_stack_node *b, int c)
{
	int	i;

	i = 0;
	if (get_pos_a(a, c))
		i = stack_size(a) - get_pos_a(a, c);
	i = find_index(b, c) + i;
	return (i);
}

int	ft_rotate_type_ba(t_stack_node *a, t_stack_node *b)
{
	int				i;
	t_stack_node	*tmp;

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
