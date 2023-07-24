/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_dic_el.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:36:37 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/24 17:39:28 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

t_dict_el	*new_dic_el(void *key, void *val)
{
	t_dict_el	*new_el;

	new_el = malloc(sizeof(t_dict_el));
	if (new_el == NULL)
		return (NULL);
	new_el->key = key;
	new_el->val = val;
	return (new_el);
}
