/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_dupl_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:41:41 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/05 19:47:10 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static t_bool	is_equal_func(void *a, void *b);

t_bool	has_dupl_int(int *array, size_t array_len)
{
	return (has_dupl((t_array){
			.buff = (void *)array,
			.len = array_len,
			.el_size = sizeof(int)},
		&is_equal_func));
}

static t_bool	is_equal_func(void *a, void *b)
{
	int	ia;
	int	ib;

	ia = *((int *)a);
	ib = *((int *)b);
	return (ia == ib);
}
