/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:38:35 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/17 15:41:44 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	is_number(const char *str)
{
	if (str == NULL)
		return (false);
	if (!ft_isdigit(str[0]) && ft_atoi(str) == 0)
		return (false);
	return (true);
}