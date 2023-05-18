/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:48:37 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/18 15:39:53 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static uint32_t	count_split(char const *s, char c);
static char		**free_str_array(char **array, uint32_t len);
char			*substr(char const *s, unsigned int start, uint32_t *len);

char	**ft_split(char const *s, char c)
{
	char		**split_array;
	uint32_t	split_count;
	uint32_t	split_len;
	uint32_t	i;

	if (s == NULL)
		return (NULL);
	split_array = malloc((count_split(s, c) + 1) * sizeof(char *));
	if (split_array == NULL)
		return (NULL);
	split_count = 0;
	split_len = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] != c)
			split_len++;
		else if (split_len > 0)
			split_array[split_count++]
				= substr(s, i - split_len, &split_len);
	}
	if (split_len > 0)
		split_array[split_count++] = ft_substr(s, i - split_len, split_len);
	split_array[split_count] = NULL;
	return (split_array);
}

static uint32_t	count_split(char const *s, char c)
{
	uint32_t	split_count;
	uint32_t	split_len;
	uint32_t	i;

	split_count = 0;
	split_len = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			split_len++;
		else if (s[i] == c && split_len > 0)
		{
			split_count++;
			split_len = 0;
		}
		i++;
	}
	if (split_len > 0)
		split_count++;
	return (split_count);
}

static char	**free_str_array(char **array, uint32_t len)
{
	uint32_t	i;

	i = 0;
	while (i < len)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

char	*substr(char const *s, unsigned int start, uint32_t *len)
{
	char	*output_str;
	int		i;

	if (s == NULL)
		return (NULL);
	output_str = malloc(sizeof(char) * (*len + 1));
	if (output_str == NULL)
		return (NULL);
	i = 0;
	while ((s + start)[i] && i < *len)
	{
		output_str[i] = (s + start)[i];
		i++;
	}
	output_str[i] = 0;
	*len = 0;
	return (output_str);
}
