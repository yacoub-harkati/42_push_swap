/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_commands.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:05:57 by yaharkat          #+#    #+#             */
/*   Updated: 2023/12/19 15:50:31 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_stack_node **a, bool checker)
{
	reverse_rotate(a);
	if (!checker)
		ft_putstr_fd("rra\n", 1);
}

void rrb(t_stack_node **b, bool checker)
{
	reverse_rotate(b);
	if (!checker)
		ft_putstr_fd("rrb\n", 1);
}

void rrr(t_stack_node **a, t_stack_node **b, bool checker)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!checker)
		ft_putstr_fd("rrr\n", 1);
}