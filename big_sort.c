/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:26:09 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/08 23:43:19 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_big(t_stack_node **a, t_stack_node **b, bool checker)
{
	t_bigsort_data *bs_data;
	t_stack_node *hold_first;
	t_stack_node *hold_second;
	int i;

	i = 0;
	hold_first = NULL;
	hold_second = NULL;
	bs_data = malloc(sizeof(t_bigsort_data));
	if (!bs_data)
	{
		// To do: handle error
		return;
	}
	printf("\n\nvvvv Chunks vvvv\n\n");

	init_bs_data(bs_data, *a);
	hold_first = find_inside_chunk(*a, bs_data, bs_data->chunks[0]);
	hold_first = find_rv_inside_chunk(*a, bs_data, bs_data->chunks[0]);

	printf("\n\nvvvv is inside chunk test vvvv\n\n");

	printf("%d is inside chunk: %d\n", 0 , is_inside_chunk(bs_data->chunks[0], 0, bs_data->chucks_count[0]));
	printf("%d is inside chunk: %d\n", 17 , is_inside_chunk(bs_data->chunks[0], 17, bs_data->chucks_count[0]));
	
	printf("\n\nvvvv Holds vvvv\n\n");

	if (hold_first)
		printf("Hold first: %d\n", hold_first->value);
	else
		printf("Hold first: NULL\n");
	if (hold_second)
		printf("Hold second: %d\n", hold_second->value);
	else
		printf("Hold second: NULL\n");

	// to remove
	(void)b;
	(void)checker;
}