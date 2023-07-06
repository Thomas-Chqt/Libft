/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_has_dupl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:03:59 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/06 16:07:37 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_bool	lst_has_dupl(t_list *lst, t_bool (*is_equal)(void *, void *))
{
	t_list	*watched;

	watched = lst;
	while (watched != NULL)
	{
		if (lst_contains(watched->next, watched->data, is_equal) == true)
			return (true);
		watched = watched->next;
	}
	return (false);
}
