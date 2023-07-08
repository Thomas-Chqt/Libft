/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:37:18 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/07 23:49:46 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_list	*lst_map(t_list *lst, t_list *(*f)(void *, void *), void *data)
{
	t_list	*lst_wtch;
	t_list	*new_lst;
	t_list	*new_lst_wtch;

	if (lst == NULL || f == NULL)
		return (NULL);
	new_lst = f(lst->data, data);
	lst_wtch = lst->next;
	new_lst_wtch = new_lst;
	while (lst_wtch != NULL)
	{
		while (new_lst_wtch->next != NULL)
			new_lst_wtch = new_lst_wtch->next;
		new_lst_wtch->next = f(lst_wtch->data, data);
		lst_wtch = lst_wtch->next;
	}
	return (new_lst);
}
