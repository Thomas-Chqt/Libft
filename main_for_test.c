/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_for_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:25:16 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/24 17:51:08 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

// #include "libft.h"
#include "dictionary.h"

# ifdef MEMCHECK

#  include <memory_leak_detector.h>

__attribute__((destructor))
static void	destructor(void)
{
	print_report();
}

# endif // MEMCHECK

// void print_dic_el(void *data)
// {
// 	t_dict_el	*el = data;

// 	ft_printf("(%s | %s)", el->key, el->val);
// }

// void print_dic_debug(t_dictionary dic)
// {
// 	t_dictionary_int *dict_int = (t_dictionary_int *)dic;

// 	for (size_t i = 0; i < dict_int->size; i++)
// 	{
		
// 	}
	
// }

// int main()
// {
	

// 	return 0;
// }
