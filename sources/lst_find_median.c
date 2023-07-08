/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_find_median.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:15:07 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/07 17:13:00 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

void	*lst_find_median(t_list *lst, size_t el_size,
			t_bool (*diff)(void *a, void *b))
{
	t_array	array;
	void	*ret;

	array.buff = lst_to_array(lst, el_size);
	if (array.buff == NULL)
		return (NULL);
	array.len = ft_lstsize(lst);
	array.el_size = el_size;
	ret = find_median(array, diff);
	free(array.buff);
	return (ret);
}
