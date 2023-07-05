/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:51:11 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/05 19:48:30 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static t_bool	diff_func(void *a, void *b);

void	quick_sort_int(int *array, size_t array_len)
{
	quick_sort((t_array){
		.buff = (void *)array,
		.len = array_len,
		.el_size = sizeof(int)
	}, &diff_func);
}

static t_bool	diff_func(void *a, void *b)
{
	int	ia;
	int	ib;

	ia = *((int *)a);
	ib = *((int *)b);
	return (ia <= ib);
}
