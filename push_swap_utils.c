/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:40:22 by yaharkat          #+#    #+#             */
/*   Updated: 2023/12/19 18:57:14 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack_node **lst)
{
	t_stack_node *tmp;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	(*lst)->prev = NULL;
	tmp->next = (*lst)->next;
	if (tmp->next)
		tmp->next->prev = tmp;
	(*lst)->next = tmp;
}

void rotate(t_stack_node **lst)
{
	t_stack_node *tmp;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	(*lst)->prev = NULL;
	tmp->next = NULL;
	add_back_stack(lst, tmp);
}

void reverse_rotate(t_stack_node **lst)
{
	t_stack_node *tmp;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = last_stack(*lst);
	if (tmp->prev)
		tmp->prev->next = NULL;
	tmp->prev = NULL;
	tmp->next = *lst;
	(*lst)->prev = tmp;
	*lst = tmp;
}

void push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node *tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->next = NULL;
	add_front_stack(dest, tmp);
}
