/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_for_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:25:16 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/05 22:53:21 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

# ifdef MEMCHECK

#  include <memory_leak_detector.h>

__attribute__((destructor))
static void	destructor(void)
{
	print_report();
}

# endif // MEMCHECK

#define ARRAY_LEN 10


int main()
{
	char *str = "AA BB CC CC";
	char **splited_str = ft_split(str, ' ');

	t_bool result = has_dupl_str(splited_str, 4);

	return 0; 
}
