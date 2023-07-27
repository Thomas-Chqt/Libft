/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdic_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:15:31 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/26 23:40:36 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

t_list_dict	*lstdic_new(t_dictionary_int *funcs, void *key, void *val)
{
	t_list_dict	*new_node;

	new_node = malloc(sizeof(t_list_dict));
	if (new_node != NULL)
	{
		new_node->next = NULL;
		new_node->data = malloc(sizeof(t_dict_el));
		if (new_node->data != NULL)
		{
			new_node->data->key = funcs->dup_key(key);
			if (new_node->data->key != NULL)
			{
				new_node->data->val = funcs->dup_val(val);
				if (new_node->data->val != NULL)
					return (new_node);
				free(new_node->data->key);
			}
			free(new_node->data);
		}
		free(new_node);
	}
	return (NULL);
}
