/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_from_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:35:22 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/05 17:37:47 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_list	*list_from_array(void *array, size_t array_len, size_t el_size)
{
	t_list	*head;
	t_list	*new_node;
	ssize_t	i;

	if (array == NULL || array_len == 0 || el_size == 0)
		return (NULL);
	i = array_len - 1;
	head = ft_lstnew(array + (i * el_size));
	if (head == NULL)
		return (NULL);
	i--;
	while (i >= 0)
	{
		new_node = ft_lstnew(array + (i * el_size));
		if (head == NULL)
		{
			ft_lstclear(&head, NULL);
			return (NULL);
		}
		ft_lstadd_front(&head, new_node);
		i--;
	}
	return (head);
}
