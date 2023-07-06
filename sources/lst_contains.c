/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_contains.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:58:26 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/06 16:02:52 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_bool	lst_contains(t_list *lst, void *searched,
					t_bool (*is_equal)(void *, void *))
{
	t_list	*watched;

	watched = lst;
	while (watched != NULL)
	{
		if (is_equal(watched->data, searched) == true)
			return (true);
		watched = watched->next;
	}
	return (false);
}
