/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:09:45 by tchoquet          #+#    #+#             */
/*   Updated: 2023/08/14 18:11:19 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	*stk_get(t_stack stack)
{
	t_list	*node;
	void	*duped_data;

	node = lst_rmvfrst(&stack->head);
	if (node == NULL)
		return (NULL);
	duped_data = stack->data_dup(node->data);
	stack->free_data(node->data);
	free(node);
	return (duped_data);
}
