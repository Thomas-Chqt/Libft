/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_for_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:25:16 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/29 12:41:55 by tchoquet         ###   ########.fr       */
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

t_bool diff_func(void *a, void *b)
{
	return (*((int *)b) < *((int *)a));
}

int main()
{
	int	array[5] = { 3, 5, 8, 3, 1};

	int *best = (int *)find_best(array, 5, sizeof(int), &diff_func);

	return 0; 
}
