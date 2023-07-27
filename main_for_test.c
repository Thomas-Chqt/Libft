/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_for_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:25:16 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/27 13:35:44 by tchoquet         ###   ########.fr       */
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
	char	*pid;
	char	*cmd;

	print_report();
	pid = ft_itoa(getpid());
	cmd = ft_strjoin("leaks -q ", pid);
	system((const char *)cmd);
	free(pid);
	free(cmd);
}


# endif // MEMCHECK

// int main()
// {
// 	char	*str = "abcdef";
// 	char	**str_ptr = mem_dup(&str, sizeof(&str));
// 	ft_printf("%s\n", *str_ptr);
// 	free(str_ptr);
// 	return 0;
// }

void print_dic_el(void *data)
{
	t_dict_el	*el = data;

	ft_printf("(%s | %s) -> ", *((char **)el->key), *((char **)el->val));
}

void print_dic_debug(t_dictionary dic)
{
	t_dictionary_int *dict_int = (t_dictionary_int *)dic;

	for (size_t i = 0; i < dict_int->size; i++)
	{
		ft_lstiter(dict_int->vals[i]->data, &print_dic_el);
		ft_printf("\n");
	}
	
}

int main()
{
	t_dictionary dict = dicstrstr_new(10);
	dicstrstr_set(dict, "thomas", "");
	return 0;
}