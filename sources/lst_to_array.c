/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:06:53 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/07 13:23:53 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

void	*lst_to_array(t_list *lst, size_t el_size)
{
	void	*array;
	t_list	*current;
	size_t	i;

	if (lst == NULL)
		return (NULL);
	array = malloc(el_size * ft_lstsize(lst));
	if (array == NULL)
		return (NULL);
	current = lst;
	i = 0;
	while (current != NULL)
	{
		ft_memcpy(array + (i * el_size), current->data, el_size);
		current = current->next;
		i++;
	}
	return (array);
}
