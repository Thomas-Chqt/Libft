/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstiter_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:13:13 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/15 21:13:53 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lstiter_data(t_list *lst, void (*f)(void*, void*), void *data)
{
	t_list	*watched;

	watched = lst;
	while (watched != NULL)
	{
		f(watched->data, data);
		watched = watched->next;
	}
}
