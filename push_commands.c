/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:52:02 by yaharkat          #+#    #+#             */
/*   Updated: 2023/12/19 19:03:20 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_stack_node **a, t_stack_node **b, bool checker)
{
	push(a, b);
	if (!checker)
		ft_putstr_fd("pa\n", 1);
}

void pb(t_stack_node **a, t_stack_node **b, bool checker)
{
	push(b, a);
	if (!checker)
		ft_putstr_fd("pb\n", 1);
}