/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_el.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:31:08 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/05 19:26:41 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

void	*get_el(t_array array, size_t index)
{
	return (array.buff + (index * array.el_size));
}
