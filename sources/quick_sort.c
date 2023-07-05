/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:58:53 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/05 19:26:25 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static int	partition(t_array array, t_bool (*diff)(void *a, void *b));

void	quick_sort(t_array array, t_bool (*diff)(void *a, void *b))
{
	size_t	pivot_index;

	if (array.buff == NULL || array.len < 2 || diff == NULL)
		return ;
	if (array.len == 2 && diff(array.buff, get_el(array, 1)) == true)
		return ;
	if (array.len != 2)
	{
		pivot_index = partition(array, diff);
		quick_sort((t_array){array.buff, pivot_index, array.el_size}, diff);
		quick_sort((t_array){get_el(array, pivot_index + 1),
			array.len - (pivot_index + 1), array.el_size}, diff);
	}
	else
		swap(array.buff, get_el(array, 1), array.el_size);
}

static int	partition(t_array array, t_bool (*diff)(void *a, void *b))
{
	void	*pivot_value;
	size_t	i;
	size_t	j;

	pivot_value = get_el(array, array.len - 1);
	i = 0;
	j = 0;
	while (j < (array.len - 1))
	{
		if (diff(get_el(array, j), pivot_value) == true)
		{
			swap(get_el(array, i), get_el(array, j), array.el_size);
			i++;
		}
		j++;
	}
	swap(get_el(array, i), get_el(array, array.len - 1), array.el_size);
	return (i);
}
