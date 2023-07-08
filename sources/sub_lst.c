/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:49:22 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/07 17:15:16 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static t_list	*node_dup(void *data, void *(*data_dup)(void *),
					void (*del)(void *));
static t_list	*ft_lstclear_wrap(t_list **lst, void (*del)(void *));

t_list	*sub_lst(t_list *lst, size_t new_len, void *(*data_dup)(void *),
			void (*del)(void *))
{
	t_list		*new_lst;
	t_list		*lst_current;
	t_list		*new_lst_current;
	t_uint64	i;

	if (lst == NULL || data_dup == NULL)
		return (NULL);
	new_lst = node_dup(lst->data, data_dup, del);
	if (new_lst == NULL)
		return (NULL);
	lst_current = lst->next;
	new_lst_current = new_lst;
	i = 1;
	while (lst_current != NULL && i < new_len)
	{
		new_lst_current->next = node_dup(lst_current->data, data_dup, del);
		if (new_lst_current->next == NULL)
			return (ft_lstclear_wrap(&new_lst, del));
		lst_current = lst_current->next;
		new_lst_current = new_lst_current->next;
		i++;
	}
	new_lst_current->next = NULL;
	return (new_lst);
}

static t_list	*node_dup(void *data, void *(*data_dup)(void *),
					void (*del)(void *))
{
	void	*duped_data;
	t_list	*new_node;

	if (data == NULL)
		return (ft_lstnew(NULL));
	duped_data = data_dup(data);
	if (duped_data == NULL)
		return (NULL);
	new_node = ft_lstnew(duped_data);
	if (new_node == NULL)
		del(duped_data);
	return (new_node);
}

static t_list	*ft_lstclear_wrap(t_list **lst, void (*del)(void *))
{
	ft_lstclear(lst, del);
	return (NULL);
}
