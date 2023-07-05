/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:51:11 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/05 13:52:39 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static int	partition(int *array, size_t array_len);

void	quick_sort_int(int *array, size_t array_len)
{
	size_t	pivot_index;

	if (array == NULL || array_len < 2
		|| (array_len == 2 && array[0] <= array[1]))
		return ;
	if (array_len != 2)
	{
		pivot_index = partition(array, array_len);
		quick_sort_int(array, pivot_index);
		quick_sort_int(array + (pivot_index + 1),
			array_len - (pivot_index + 1));
	}
	else
		swap_int(&array[0], &array[1]);
}

static int	partition(int *array, size_t array_len)
{
	int		pivot_value;
	size_t	i;
	size_t	j;

	pivot_value = array[array_len - 1];
	i = 0;
	j = 0;
	while (j < (array_len - 1))
	{
		if (array[j] <= pivot_value)
		{
			swap_int(&array[i], &array[j]);
			i++;
		}
		j++;
	}
	swap_int(&array[i], &array[array_len - 1]);
	return (i);
}
