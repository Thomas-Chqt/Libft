/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_for_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:25:16 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/25 15:51:20 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

# ifdef MEMCHEK

#  include <memory_leak_detector.h>

__attribute__((destructor))
static void	destructor(void)
{
	print_report();
}

# endif // MEMCHEK

int main()
{
	char **splited_str = ft_split("a b cde fg", ' ');

	size_t len = array_len(splited_str, sizeof(char *));

	free_splited_str(splited_str);

	return 0; 
}

