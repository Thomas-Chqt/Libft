/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<<< HEAD:sources/ft_split.c
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:48:37 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/17 17:53:54 by tchoquet         ###   ########.fr       */
========
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:49:01 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/17 11:29:31 by tchoquet         ###   ########.fr       */
>>>>>>>> f4b59d9 (MacBook):sources/ft_substr.c
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<<< HEAD:sources/ft_split.c
char **ft_split(char const *s, char c)
{

}
========
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*output_str;
	int		i;

	output_str = malloc(sizeof(char) * (len + 1));
	while ((s + start)[i] && i < len)
	{
		output_str[i] = (s + start)[i];
		i++;
	}
	output_str[i] = 0;
	return (output_str);
}
>>>>>>>> f4b59d9 (MacBook):sources/ft_substr.c
