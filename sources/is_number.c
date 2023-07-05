/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:38:35 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/05 22:59:21 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static t_bool	is_not_digit_wrapper(void *c, void *none);

t_bool	is_number(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (false);
	i = 0;
	if (str[0] == '-')
		i++;
	return (!contains(
			(t_array){(void *)(str + i), ft_strlen(str + i), sizeof(char)},
			NULL,
			&is_not_digit_wrapper
		));
}

static t_bool	is_not_digit_wrapper(void *c, void *none)
{
	if (none) 
		none = NULL;

	return (!ft_isdigit(*((char *)c)));
}
