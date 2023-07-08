/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_for_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:25:16 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/07 17:07:50 by tchoquet         ###   ########.fr       */
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

void	print_wrap(void *nbr)
{
	printf("%d ", *((int *)nbr));
}

int main()
{
	char *str = "1 4 6 3 2";
	char **splited_str = ft_split(str, ' ');
	t_list *list = lst_from_str_array(splited_str, array_len(splited_str, sizeof(char *)));
	list = lst_map_ft_atoi_clear(&list);

	printf("Median : %d\n", lst_find_median_int_free(sub_lst_int(list, 3)));

	free_splited_str(splited_str);
	ft_lstclear(&list, &free_wrap);

	return 0; 
}
