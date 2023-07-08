/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_from_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:09:32 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/07 20:57:35 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_list	*lst_from_array(t_array array, void *(*make_data)(void *), void (*del))
{
	size_t	i;
	t_list	*new_lst;
	t_list	*new_lst_wtch;

	if (array.buff == NULL || array.el_size < 1 || make_data == NULL)
		return (NULL);
	if (array.len == 0)
		return (NULL);
	new_lst = ft_lstnew(make_data(get_el(array, 0)));
	if (new_lst == NULL || new_lst->data == NULL)
		return (NULL);
	new_lst_wtch = new_lst;
	i = 1;
	while (i < array.len)
	{
		new_lst_wtch->next = ft_lstnew(make_data(get_el(array, i)));
		if (new_lst_wtch->next == NULL || new_lst_wtch->next->data == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		new_lst_wtch = new_lst_wtch->next;
		i++;
	}
	return (new_lst);
}
