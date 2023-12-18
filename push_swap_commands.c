/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:31:32 by yaharkat          #+#    #+#             */
/*   Updated: 2023/12/18 20:38:15 by yaharkat         ###   ########.fr       */
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

void push(t_stack_node **lst1, t_stack_node **lst2)
{
	t_stack_node *tmp;

	if (!*lst2 || !lst2)
		return ;
	tmp = *lst2;
	*lst2 = (*lst2)->next;
	if (*lst2)
		(*lst2)->prev = NULL;
	tmp->next = *lst1;
	if (*lst1)
		(*lst1)->prev = tmp;
	*lst1 = tmp;
}