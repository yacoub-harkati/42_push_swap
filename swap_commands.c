/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:02:42 by yaharkat          #+#    #+#             */
/*   Updated: 2023/12/19 15:51:14 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_node **a, bool checker)
{
	swap(a);
	if (!checker)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack_node **b, bool checker)
{
	swap(b);
	if (!checker)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack_node **a, t_stack_node **b, bool checker)
{
	swap(a);
	swap(b);
	if (!checker)
		ft_putstr_fd("ss\n", 1);
}
