/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util_cammands.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:40:22 by yaharkat          #+#    #+#             */
/*   Updated: 2023/12/18 20:44:18 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_stack_node **a, t_stack_node **b, bool checker)
{
	t_stack_node *tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	tmp->next = NULL;
	add_front_stack(a, tmp);
	if (checker)
		ft_putstr_fd("pa\n", 1);
}

void pb(t_stack_node **a, t_stack_node **b, bool checker)
{
	t_stack_node *tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	tmp->next = NULL;
	add_front_stack(b, tmp);
	if (checker)
		ft_putstr_fd("pb\n", 1);
}

void sa(t_stack_node **a, bool checker)
{
	swap(a);
	if (checker)
		ft_putstr_fd("sa\n", 1);
}

void sb(t_stack_node **b, bool checker)
{
	swap(b);
	if (checker)
		ft_putstr_fd("sb\n", 1);
}

void ss(t_stack_node **a, t_stack_node **b, bool checker)
{
	swap(a);
	swap(b);
	if (checker)
		ft_putstr_fd("ss\n", 1);
}

void ra(t_stack_node **a, bool checker)
{
	rotate(a);
	if (checker)
		ft_putstr_fd("ra\n", 1);
}

void rb(t_stack_node **b, bool checker)
{
	rotate(b);
	if (checker)
		ft_putstr_fd("rb\n", 1);
}
void rr(t_stack_node **a, t_stack_node **b, bool checker)
{
	rotate(a);
	rotate(b);
	if (checker)
		ft_putstr_fd("rr\n", 1);
}