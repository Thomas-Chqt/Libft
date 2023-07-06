/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_for_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:25:16 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/06 16:14:09 by tchoquet         ###   ########.fr       */
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

void print_wrapper(void *nbr)
{
	printf("%d\n", *((int *)nbr));
}

int main()
{
	char *str = "123,456 789";
	char **splited_str = ft_split(str, ' ');
	t_list *one = lst_from_str_array(splited_str, array_len(splited_str, sizeof(char *)));
	t_list *two = lst_map_ft_split(one, ',');
	t_list *tree = lst_map_ft_atoi(two);

	ft_lstiter(tree, &print_wrapper);

	printf("%d\n", lst_has_dupl_str(tree));

	free_splited_str(splited_str);
	ft_lstclear(&one, &free_wrap);
	ft_lstclear(&two, &free_wrap);
	ft_lstclear(&tree, &free_wrap);

	return 0; 
}
