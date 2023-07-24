/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dic_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:39:34 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/24 18:31:13 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

int	dic_set(t_dictionary dict, void *key, void *val,
		t_bool (*is_equal)(void *, void *))
{
	t_dictionary_int	*dict_int;
	t_list_dict			*found_head;
	t_list_dict			*found_el;
	t_list_dict			*new_el;

	dict_int = (t_dictionary_int *)dict;
	if (key == NULL || val == NULL || is_equal == NULL)
		return (1);
	found_head = dict_int->vals[dict_int->hash_func(key, dict_int->size)];
	found_el = lst_chr((t_list *)found_head, is_equal, key);
	if (found_el != NULL)
	{
		dict_int->free_key(found_el->data->key);
		found_el->data->key = key;
		dict_int->free_val(found_el->data->val);
		found_el->data->val = val;
		return (0);
	}
	new_el = new_dic_el(key, val);
	if (new_el == NULL)
		return (1);
	ft_lstadd_front((t_list **)&found_el, (t_list *)new_el);
	return (0);
}
