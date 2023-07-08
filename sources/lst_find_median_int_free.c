/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_find_median_int_free.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:59:27 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/07 17:12:22 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

int	lst_find_median_int_free(t_list *lst)
{
	int	median;

	median = lst_find_median_int(lst);
	ft_lstclear(&lst, &free_wrap);
	return (median);
}
