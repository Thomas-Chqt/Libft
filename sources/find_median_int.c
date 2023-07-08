/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:57:51 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/07 17:12:07 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static t_bool	diff_func(void *a, void *b);

int	find_median_int(int *array, size_t array_len)
{
	void	*median_ptr;
	int		ret;

	median_ptr = find_median((t_array){array, array_len, sizeof(int)},
			&diff_func);
	if (median_ptr == NULL)
		return (0);
	ret = *((int *)median_ptr);
	free(median_ptr);
	return (ret);
}

static t_bool	diff_func(void *a, void *b)
{
	int	ia;
	int	ib;

	ia = *((int *)a);
	ib = *((int *)b);
	return (ia <= ib);
}
