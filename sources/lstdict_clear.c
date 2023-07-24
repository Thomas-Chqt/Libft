/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdict_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:42:24 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/24 17:44:39 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

void	lstdict_clear(t_list_dict **lst, void (*free_key)(void *), void (*free_val)(void *))
{
	t_list	*watched;
	t_list	*temp;

	watched = *lst;
	while (watched != NULL)
	{
		free_dict_el(watched->data, free_key, free_val);
		temp = watched->next;
		free(watched);
		watched = temp;
	}
	(*lst) = NULL;
}
