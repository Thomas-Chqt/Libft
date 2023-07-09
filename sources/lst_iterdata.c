/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_iterdata.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 12:05:16 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/09 12:06:22 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

void	lst_iterdata(t_list *lst, void (*func)(void *, void *), void *data)
{
	t_list	*current;

	current = lst;
	while (current != NULL)
	{
		func(current->data, data);
		current = current->next;
	}
}