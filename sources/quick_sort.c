/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:58:53 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/05 14:32:39 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static int	partition(void *array, size_t array_len, size_t el_size,
				t_bool (*diff)(void *a, void *b));

void	quick_sort(void *array, size_t array_len, size_t el_size,
				t_bool (*diff)(void *a, void *b))
{
	size_t	pivot_index;

	if (array == NULL || array_len < 2 || diff == NULL)
		return ;
	if (array_len == 2 && diff(array, array + (1 * el_size)) == true)
		return ;
	if (array_len != 2)
	{
		pivot_index = partition(array, array_len, el_size, diff);
		quick_sort(array, pivot_index, el_size, diff);
		quick_sort(array + ((pivot_index + 1) * el_size),
			array_len - (pivot_index + 1), el_size, diff);
	}
	else
		swap(array, array + (1 * el_size), el_size);
}

static int	partition(void *array, size_t array_len, size_t el_size,
				t_bool (*diff)(void *a, void *b))
{
	void	*pivot_value;
	size_t	i;
	size_t	j;

	pivot_value = array + ((array_len - 1) * el_size);
	i = 0;
	j = 0;
	while (j < (array_len - 1))
	{
		if (diff(array + (j * el_size), pivot_value) == true)
		{
			swap(array + (i * el_size), array + (j * el_size), el_size);
			i++;
		}
		j++;
	}
	swap(array + (i * el_size), array + ((array_len - 1) * el_size), el_size);
	return (i);
}
