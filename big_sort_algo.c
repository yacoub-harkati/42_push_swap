/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:26:09 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/11 15:20:29 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_big(t_stack_node **a, t_stack_node **b, bool checker)
{
	int		i;

	if (stack_size(*a) == 2)
		sa(a, checker);
	else
	{
		b = sort_b(a, b, checker);
		a = sort_a(a, b, checker);
		i = find_index(*a, find_min_node(*a)->value);
		if (i < (int)stack_size(*a) - i)
		{
			while ((*a)->value != find_min_node(*a)->value)
				ra(a, checker);
		}
		else
		{
			while ((*a)->value != find_min_node(*a)->value)
				rra(a, checker);
		}			
	}	
}
