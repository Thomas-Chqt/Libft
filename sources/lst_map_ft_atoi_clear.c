/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_map_ft_atoi_clear.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:28:48 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/06 16:29:50 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_list	*lst_map_ft_atoi_clear(t_list **lst)
{
	t_list	*new_list;

	if (lst == NULL || *lst == NULL)
		return (NULL);
	new_list = lst_map_ft_atoi(*lst);
	ft_lstclear(lst, &free_wrap);
	return (new_list);
}
