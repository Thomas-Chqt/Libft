/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_contain_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:19:52 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/05 19:46:48 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static t_bool	is_equal_func(void *a, void *b);

t_bool	contains_int(int *array, size_t array_len, int searched)
{
	return (contains((t_array){
			.buff = (void *)array,
			.len = array_len,
			.el_size = sizeof(int)},
		(void *)(&searched), &is_equal_func));
}

static t_bool	is_equal_func(void *a, void *b)
{
	int	ia;
	int	ib;

	ia = *((int *)a);
	ib = *((int *)b);
	return (ia == ib);
}
