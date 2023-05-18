/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_for_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:25:16 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/18 09:36:29 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(int argc, char const *argv[])
{
	size_t len = ft_strlen("qwerty");

	char* str = ft_strjoin("abcd", "efghi");

	// ft_substr

	// str = ft_strtrim(".;[abcd./]", ".;[]/");

	ft_itoa(42);

	return 0;
}
