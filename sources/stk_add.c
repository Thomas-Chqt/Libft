/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:55:18 by tchoquet          #+#    #+#             */
/*   Updated: 2023/08/14 18:02:07 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stk_add(t_stack stack, void *data)
{
	t_list	*new_node;

	new_node = ft_lstnew(new_node);
	if (new_node == NULL)
		return (1);
	ft_lstadd_front(&stack->head, new_node);
	return (0);
}
