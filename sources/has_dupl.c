/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_dupl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:36:33 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/05 19:47:56 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_bool	has_dupl(t_array array, t_bool (*is_equal)(void *, void *))
{
	size_t	i;

	i = 1;
	while (i < array.len)
	{
		if (contains((t_array){array.buff, i, array.el_size},
			get_el(array, i), is_equal) == true)
			return (true);
		i++;
	}
	return (false);
}
