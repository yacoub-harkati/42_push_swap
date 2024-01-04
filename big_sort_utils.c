/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:13:15 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/04 22:49:21 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_chunks(t_bigsort_data *bs_data)
{
	for (int i = 0; i < 11; i++)
	{
		printf("Chunk %d: ", i);
		for (int j = 0; j < bs_data->chucks_count[i]; j++)
		{
			printf("%d ", bs_data->chunks[i][j]);
		}
		printf("\n");
	}
}

void init_chunks(t_bigsort_data *bs_data)
{
	int chunk_index;

	chunk_index = 0;
	bs_data->chunks = malloc(sizeof(int *) * 11);
	bs_data->chucks_count = malloc(sizeof(int) * 11);
	while (chunk_index < 11)
	{
		bs_data->chunks[chunk_index] = malloc(sizeof(int) * 1000);
		bs_data->chucks_count[chunk_index] = 0;
		chunk_index++;
	}
}
void add_to_chunk(int **chunks, int *chunk_count, int chunk_index, int value)
{
	if (chunk_index >= 11)
		chunk_index = 10;
	else if (chunk_index < 0)
		chunk_index = 0;
	chunks[chunk_index][chunk_count[chunk_index]] = value;
	chunk_count[chunk_index]++;
}

int **get_chunks(t_bigsort_data *bs_data)
{
	int remainder;
	int elements_per_chunk;
	int chunk_index;
	int total_count;

	init_chunks(bs_data);
	elements_per_chunk = bs_data->stack_size / 11;
	remainder = bs_data->stack_size % 11;
	total_count = 0;

	while (total_count < bs_data->stack_size)
	{
		if (total_count < (elements_per_chunk + 1) * remainder)
			chunk_index = total_count / (elements_per_chunk + 1);
		else
			chunk_index = remainder + (total_count - (elements_per_chunk + 1) * remainder) / elements_per_chunk;
		add_to_chunk(bs_data->chunks, bs_data->chucks_count, chunk_index, bs_data->sort_array[total_count]);
		total_count++;
	}

	return (bs_data->chunks);
}

int *sort_array(int *unsorted_arr, int size)
{
	int tmp;
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (unsorted_arr[j] > unsorted_arr[j + 1])
			{
				tmp = unsorted_arr[j];
				unsorted_arr[j] = unsorted_arr[j + 1];
				unsorted_arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return unsorted_arr;
}

int *get_sorted_num_buffer(t_stack_node *a)
{
	int *returned_arr;
	int size;
	int i;

	i = 0;
	size = stack_size(a);
	returned_arr = malloc(sizeof(int) * size);
	while (a)
	{
		returned_arr[i++] = a->value;
		a = a->next;
	}
	return (sort_array(returned_arr, size));
}

void init_bs_data(t_bigsort_data *bs_data, t_stack_node *a)
{
	bs_data->stack_size = stack_size(a);
	bs_data->sort_array = get_sorted_num_buffer(a);
	bs_data->chunks = get_chunks(bs_data);
	print_chunks(bs_data);
}