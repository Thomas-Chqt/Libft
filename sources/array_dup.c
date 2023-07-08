/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:33:48 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/07 13:48:27 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_array	array_dup(t_array array)
{
	t_array		new_array;
	t_uint64	i;

	new_array = (t_array){
		.buff = malloc(array.el_size * array.len),
		.len = array.len,
		.el_size = array.el_size
	};
	if (new_array.buff == NULL)
		return ((t_array){.buff = NULL});
	i = 0;
	while (i < array.len)
	{
		ft_memcpy(get_el(new_array, i), get_el(array, i), array.el_size);
		i++;
	}
	return (new_array);
}
