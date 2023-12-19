/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:10:43 by yaharkat          #+#    #+#             */
/*   Updated: 2023/12/19 19:04:39 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_nodes(t_stack_node **a, t_stack_node **b)
{
	set_current_position(*a);
	set_current_position(*b);
	set_target_node(*a, *b);
	set_price(*a, *b);
	set_cheapest_node(*b);
}
void push_swap(t_stack_node **a, t_stack_node **b, bool checker)
{
	int len_a;
	t_stack_node *tmp;
	int i = 1;
	
	len_a = stack_size(*a);
	while (len_a-- > 3)
		pb(a, b, !checker);
	sort_tree(a, !checker);
	while (*b)
	{
		init_nodes(a, b);
		tmp = find_cheapest(*b);
		printf("%d - cheapest node: %d\n", i, tmp->value);
		i++;
		break;
	}
}
