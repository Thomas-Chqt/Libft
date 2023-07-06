/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_map_ft_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:57:50 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/06 14:25:44 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static t_list	*create_nodes(void *str, void *c);

t_list	*lst_map_ft_split(t_list *lst, char c)
{
	return (lst_map(lst, &create_nodes, &c, &free_wrap));
}

static t_list	*create_nodes(void *str, void *c)
{
	char	**splited_str;
	t_list	*lst;

	splited_str = ft_split((char *)str, (*(char *)c));
	if (splited_str == NULL)
		return (NULL);
	lst = lst_from_str_array(splited_str,
			array_len(splited_str, sizeof(char *)));
	free_splited_str(splited_str);
	return (lst);
}
