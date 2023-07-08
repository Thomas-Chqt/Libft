/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_ichr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:43:23 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/08 19:49:07 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static t_bool test(void *, void *);

t_uint64	str_ichr(char *str, char c, size_t len)
{
	return (
		arr_ichr((t_array){
			.buff = str,
			.el_size = sizeof(char),
			.len = len
		}, &test, &c)
	);
}

static t_bool test(void *a, void *b)
{
	return (*((char *)a) == *((char *)b));
}
