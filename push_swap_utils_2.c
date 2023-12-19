/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:40:22 by yaharkat          #+#    #+#             */
/*   Updated: 2023/12/19 15:38:49 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node *find_highest(t_stack_node *lst)
{
	t_stack_node *tmp;

	tmp = lst;
	while (lst)
	{
		if (lst->value > tmp->value)
			tmp = lst;
		lst = lst->next;
	}
	return tmp;
}