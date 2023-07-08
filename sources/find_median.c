/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:50:45 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/07 15:29:21 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

void	*find_median(t_array array, t_bool (*diff)(void *a, void *b))
{
	t_array		use_array;
	t_uint64	median_index;
	void		*result;

	use_array = array_dup(array);
	if (use_array.buff == NULL)
		return (NULL);
	quick_sort(use_array, diff);
	median_index = array.len / 2;
	result = malloc(array.el_size);
	if (result != NULL)
		ft_memcpy(result, get_el(use_array, median_index), array.el_size);
	free(use_array.buff);
	return (result);
}
