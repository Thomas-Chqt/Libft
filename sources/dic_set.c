/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dic_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:39:34 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/27 01:36:33 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

#define INPUT_NOT_VALID 1
#define UNKNOWN_ERROR 2

typedef t_bool	(*t_is_equal_func)(void *, void *);

t_bool	is_equal_wapper(void *el, void *data);

int	dic_set(t_dictionary dict, void *key, void *val,
		t_bool (*is_key_equal)(void *, void *))
{
	t_dictionary_int	*dict_int;
	t_list_dict			*found_lst_head;
	t_list_dict			*found_lst_node;
	t_list_dict			*new_node;

	dict_int = (t_dictionary_int *)dict;
	if (!dic_isvalid(dict) || key == NULL || is_key_equal == NULL)
		return (INPUT_NOT_VALID);
	found_lst_head = dict_int->vals[dict_int->hash_func(key, dict_int->size)];
	found_lst_node = (t_list_dict *)lst_chr((t_list *)dict_int->vals, &is_equal_wapper,
			(void *[2]){key, is_key_equal});
	if (found_lst_node != NULL)
	{
		dict_int->free_val(found_lst_node->data->val);
		found_lst_node->data->val = dict_int->dup_val(val);
		if (found_lst_node->data->val == NULL)
			return (UNKNOWN_ERROR);
		return (0);
	}
	new_node = lstdic_new(dict_int, key, val);
	if (new_node == NULL)
		return (UNKNOWN_ERROR);
	ft_lstadd_front((t_list **)&found_lst_head, (t_list *)new_node);
	return (0);
}

t_bool	is_equal_wapper(void *el, void *data)
{
	t_is_equal_func	is_key_equal;

	is_key_equal = ((void **)data)[1];
	return (is_key_equal(((t_dict_el *)el)->key, ((void **)data)[0]));
}
