/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:40:22 by yaharkat          #+#    #+#             */
/*   Updated: 2023/12/21 13:31:15 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_node **lst)
{
	int				len;
	t_stack_node	*tmp;

	len = stack_size(*lst);
	if (!*lst || !lst || len == 1 || !len)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->prev = *lst;
	tmp->next = (*lst)->next;
	if (tmp->next)
		tmp->next->prev = (*lst)->prev;
	(*lst)->next = tmp;
	(*lst)->prev = NULL;
}

void	rotate(t_stack_node **head)
{
	t_stack_node	*tmp;
	int				len;

	len = stack_size(*head);
	if (!head || !*head || len == 1 || !len)
		return ;
	tmp = *head;
	(*head) = (*head)->next;
	(*head)->prev = NULL;
	add_back_stack(head, tmp);
}

void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	int				len;

	len = stack_size(*stack);
	if (!*stack || !stack || len == 1 || !len)
		return ;
	last = last_stack(*stack);
	last->prev->next = NULL;
	add_front_stack(stack, last);
}

void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*node_to_push;

	if (!*src)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (!*dest)
	{
		*dest = node_to_push;
		(*dest)->next = NULL;
		return ;
	}
	node_to_push->next = *dest;
	(*dest)->prev = node_to_push;
	*dest = node_to_push;
}
