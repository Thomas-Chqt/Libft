/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:11:51 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/15 21:13:10 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*watched;
	t_list	*temp;

	watched = *lst;
	while (watched != NULL)
	{
		del(watched->data);
		temp = watched->next;
		free(watched);
		watched = temp;
	}
	(*lst) = NULL;
}
