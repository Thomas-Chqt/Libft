/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:51:10 by tchoquet          #+#    #+#             */
/*   Updated: 2023/08/14 17:54:12 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	stk_init(void *(*data_dup)(void *), void (*free_data)(void *))
{
	t_stack	new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (new_stack == NULL)
		return (NULL);
	new_stack->head = NULL;
	new_stack->data_dup = data_dup;
	new_stack->free_data = free_data;
	return (new_stack);
}
