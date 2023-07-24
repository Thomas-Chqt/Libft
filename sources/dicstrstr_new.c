/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dicstrstr_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:54:03 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/24 18:09:56 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

static t_uint64	hash_func(void *key_ptr, size_t dict_size);

t_dictionary	dicstrstr_new(size_t size)
{
	return (dic_new(size, &hash_func, &free_str_ptr, &free_str_ptr));
}

static t_uint64	hash_func(void *key_ptr, size_t dict_size)
{
	char		*key;
	t_uint64	hash;
	t_uint64	i;
	size_t		key_len;


	key = *((char **)key_ptr);
	hash = 7;
	key_len = ft_strlen(key);
	i = 0;
	while (i < key_len)
	{
		hash = (hash * 31) + key[i];
		i++;
	}
	return (hash % dict_size);
}
