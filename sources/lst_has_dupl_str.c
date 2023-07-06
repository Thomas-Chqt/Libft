/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_has_dupl_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:07:51 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/06 16:11:21 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static t_bool	is_equal_func(void *s1, void *s2);

t_bool	lst_has_dupl_str(t_list *lst)
{
	return (lst_has_dupl(lst, &is_equal_func));
}

static t_bool	is_equal_func(void *s1, void *s2)
{
	char	*cs1;
	char	*cs2;

	cs1 = (char *)s1;
	cs2 = (char *)s2;
	return (str_cmp(cs1, cs2) == 0);
}
