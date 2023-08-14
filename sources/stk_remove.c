/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:03:17 by tchoquet          #+#    #+#             */
/*   Updated: 2023/08/14 18:08:02 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	*stk_remove(t_stack stack)
{
	t_list	*node;
	void	*data;

	node = lst_rmvfrst(&stack->head);
	if (node == NULL)
		return (NULL);
	data = node->data;
	free(node);
	return (data);
}
