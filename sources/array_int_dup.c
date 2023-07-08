/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_int_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:40:41 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/07 17:10:56 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

int	*array_int_dup(int *array, t_uint64 array_len)
{
	t_array	new_array;

	new_array.buff = array;
	new_array.len = array_len;
	new_array.el_size = sizeof(int);
	new_array = array_dup(new_array);
	return ((int *)new_array.buff);
}
