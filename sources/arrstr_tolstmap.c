/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrstr_tolstmap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:50:53 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/08 18:12:37 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static void *el_dup(void *el);
static void del(void *data);

t_list	*arrstr_tolstmap(char **array, size_t array_len)
{
	return (
		arr_tolstmap((t_array){
			.buff = array,
			.len = array_len,
			.el_size = sizeof(char *)
		}, &el_dup, &del )
	);
}

static void *el_dup(void *el)
{
	char	**strptr;
	char	**duped_strptr;

	strptr = (char **)el;
	duped_strptr = malloc(sizeof(char *));
	if (duped_strptr == NULL)
		return (NULL);
	*duped_strptr = ft_strdup(*strptr);
	if (*duped_strptr == NULL)
	{
		free(duped_strptr);
		return (NULL);
	}
	return (duped_strptr);
}

static void del(void *data)
{
	char	**strptr;

	strptr = (char **)data;
	free(*strptr);
}
