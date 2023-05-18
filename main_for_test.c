/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_for_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:25:16 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/18 16:35:09 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(int argc, char const *argv[])
{
	size_t len = ft_strlen("qwerty");

	char* str = ft_substr("abcdef", 1, 3);

	str = ft_strjoin("abcd", "efghi");

	str = ft_strtrim(".;[abcd./]", ".;[]/");

	char** split_array = ft_split("  a  b  c  ", ' ');

	str = ft_itoa(INT32_MIN);

	return 0; 
}