/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_contain.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:01:17 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/05 19:27:20 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_bool	contains(t_array array, void *searched,
			t_bool (*is_equal)(void *, void *))
{
	size_t	i;

	i = 0;
	while (i < array.len)
	{
		if (is_equal(get_el(array, i), searched) == true)
			return (true);
		i++;
	}
	return (false);
}
