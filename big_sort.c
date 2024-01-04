/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:26:09 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/04 20:37:57 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_big(t_stack_node **a, t_stack_node **b, bool checker)
{
	t_bigsort_data *bs_data;
	(void)b;
	(void)checker;	
	bs_data = malloc(sizeof(t_bigsort_data));
	if (!bs_data)
	{
		//To do: handle error
		return;
	}
	init_bs_data(bs_data, *a);
	
}