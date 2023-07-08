/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_find_median_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:33:03 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/07 17:12:45 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

int	lst_find_median_int(t_list *lst)
{
	int	*array;
	int	ret;

	array = lst_to_int_array(lst);
	if (array == NULL)
		return (0);
	ret = find_median_int(array, ft_lstsize(lst));
	free(array);
	return (ret);
}
