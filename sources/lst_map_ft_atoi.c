/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_map_ft_atoi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:12:03 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/06 14:25:26 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static t_list	*create_nodes(void *str, void *none);

t_list	*lst_map_ft_atoi(t_list *lst)
{
	return (lst_map(lst, &create_nodes, NULL, &free_wrap));
}

static t_list	*create_nodes(void *str, void *none)
{
	int		*nbr;

	if (none)
		none = NULL;
	nbr = malloc(sizeof(int));
	if (nbr == NULL)
		return (NULL);
	*nbr = atoi((const char *)str);
	return (ft_lstnew((void *)nbr));
}
