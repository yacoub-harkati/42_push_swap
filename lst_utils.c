/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:30:16 by yaharkat          #+#    #+#             */
/*   Updated: 2023/12/17 16:51:48 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node *new_stack(int value)
{
	t_stack_node *new;

	new = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack_node *last_stack(t_stack_node *lst)
{
	t_stack_node *tmp;

	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void add_back_stack(t_stack_node **lst, t_stack_node *new)
{
	t_stack_node *tmp;

	if (!*lst)
	{
		*lst = new;
		return;
	}
	tmp = last_stack(*lst);
	tmp->next = new;
	new->prev = tmp;
}

size_t stack_size(t_stack_node *lst)
{
	size_t i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
