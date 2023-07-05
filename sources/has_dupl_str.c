/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_dupl_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:37:38 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/05 22:52:33 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static t_bool	is_equal_func(void *a, void *b);

t_bool	has_dupl_str(char **array, size_t array_len)
{
	return (has_dupl((t_array){
			.buff = (void *)array,
			.len = array_len,
			.el_size = sizeof(char *)},
		&is_equal_func));
}

static t_bool	is_equal_func(void *s1, void *s2)
{
	char	*cs1;
	char	*cs2;

	cs1 = *((char **)s1);
	cs2 = *((char **)s2);
	return (str_cmp(cs1, cs2) == 0);
}
