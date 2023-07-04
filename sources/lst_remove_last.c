/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_remove_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:59:50 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/04 18:35:47 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_list	*lst_remove_last(t_list **head)
{
	t_list	**watched;
	t_list	*temp;

	if (head == NULL || (*head) == NULL)
		return (NULL);
	watched = head;
	while ((*watched)->next != NULL)
		watched = &((*watched)->next);
	temp = *watched;
	*watched = NULL;
	return (temp);
}
