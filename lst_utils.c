/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:30:16 by yaharkat          #+#    #+#             */
/*   Updated: 2023/12/21 13:18:30 by yaharkat         ###   ########.fr       */
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

t_stack_node *last_stack(t_stack_node *head)
{
	t_stack_node *tmp;

	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void add_back_stack(t_stack_node **head, t_stack_node *new)
{
	t_stack_node *tmp;

	if (!*head)
	{
		*head = new;
		return;
	}
	tmp = last_stack(*head);
	tmp->next = new;
	new->prev = tmp;
	new->next = NULL;
}

void add_front_stack(t_stack_node **head, t_stack_node *new)
{
	if (!*head)
	{
		*head = new;
		return;
	}
	new->next = *head;
	(*head)->prev = new;
	new->prev = NULL;
	*head = new;
}

size_t stack_size(t_stack_node *head)
{
	size_t i;

	if (!head)
		return (0);
	i = 0;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}
