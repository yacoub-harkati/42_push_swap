/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:02:02 by yaharkat          #+#    #+#             */
/*   Updated: 2023/12/18 21:06:09 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
