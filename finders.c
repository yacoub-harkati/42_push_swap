/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:40:22 by yaharkat          #+#    #+#             */
/*   Updated: 2023/12/21 13:47:43 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_highest(t_stack_node *lst)
{
	t_stack_node	*tmp;

	tmp = lst;
	while (lst)
	{
		if (lst->value > tmp->value)
			tmp = lst;
		lst = lst->next;
	}
	return (tmp);
}

t_stack_node	*find_smallest(t_stack_node *lst)
{
	t_stack_node	*tmp;

	tmp = lst;
	while (lst)
	{
		if (lst->value < tmp->value)
			tmp = lst;
		lst = lst->next;
	}
	return (tmp);
}

t_stack_node	*find_cheapest(t_stack_node *b)
{
	t_stack_node	*tmp;

	tmp = b;
	while (tmp)
	{
		if (tmp->cheapest == true)
			return (tmp);
		tmp = tmp->next;
	}
	return (b);
}
