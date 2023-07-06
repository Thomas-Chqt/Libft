/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_from_str_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:50:53 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/06 14:27:01 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static void	*make_data(void *data);

t_list	*lst_from_str_array(char **array, size_t array_len)
{
	return (
		lst_from_array((t_array){array, array_len, sizeof(char *)},
		&make_data, &free_wrap)
	);
}

static void	*make_data(void *data)
{
	size_t	len;
	char	*str;

	len = ft_strlen(*((char **)data));
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, *((char **)data), len + 1);
	return (str);
}
