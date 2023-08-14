/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:48:25 by tchoquet          #+#    #+#             */
/*   Updated: 2023/08/14 17:51:07 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft_internal.h"

struct s_stack
{
	t_list	*head;
	void	*(*data_dup)(void *);
	void	(*free_data)(void *);
};

#endif // STACK_H