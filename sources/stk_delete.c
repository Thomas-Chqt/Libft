/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:07:19 by tchoquet          #+#    #+#             */
/*   Updated: 2023/08/14 18:09:08 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stk_delete(t_stack stack)
{
	t_list	*node;

	node = lst_rmvfrst(&stack->head);
	if (node == NULL)
		return ;
	stack->free_data(node->data);
	free(stack);
}
