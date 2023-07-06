/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_map_ft_split_clear.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:43:41 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/06 16:17:45 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_list	*lst_map_ft_split_clear(t_list **lst, char c)
{
	t_list	*new_list;

	if (lst == NULL || *lst == NULL)
		return (NULL);
	new_list = lst_map_ft_split(*lst, c);
	ft_lstclear(lst, &free_wrap);
	return (new_list);
}
