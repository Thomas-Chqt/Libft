/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_for_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:25:16 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/05 19:45:18 by tchoquet         ###   ########.fr       */
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

t_bool	equal(void *a, void *b)
{
	int	ia;
	int	ib;

	ia = *((int *)a);
	ib = *((int *)b);
	return (ia == ib );
}

int main()
{
	int *array = malloc(sizeof(int) * ARRAY_LEN);
	ft_memcpy(array, (int[]){ 9, 8, 35, 7, 0, 34, 87, 28, 86, 9 }, sizeof(int) * ARRAY_LEN);
	
	quick_sort_int(array, ARRAY_LEN);

	printf("%d\n", has_dupl_int(array, ARRAY_LEN));

	free(array);
	return 0; 
}
