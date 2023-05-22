/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:48:37 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/22 17:36:41 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*output_str;
	size_t	i;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	output_str = malloc(sizeof(char) * (len + 1));
	if (output_str == NULL)
		return (NULL);
	i = 0;
	while (((start + i) < s_len) && (s + start)[i] && i < len)
	{
		output_str[i] = (s + start)[i];
		i++;
	}
	output_str[i] = 0;
	return (output_str);
}
