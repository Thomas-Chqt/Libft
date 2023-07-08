/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lststr_splitmapf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:43:41 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/08 19:39:00 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_list	*lststr_splitmapf(t_list *lst, char c)
{
	t_list	*new_list;

	if (lst == NULL)
		return (NULL);
	new_list = lststr_splitmap(lst, c);
	ft_lstclear(&lst, &free_wrap);
	return (new_list);
}
