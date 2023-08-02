/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_for_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:25:16 by tchoquet          #+#    #+#             */
/*   Updated: 2023/08/02 11:55:13 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "libft.h"
// #include "dictionary.h"

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

/*
int main()
{
	char	*str = "abcdef";
	char	**str_ptr = mem_dup(&str, sizeof(&str));
	ft_printf("%s\n", *str_ptr);
	free(str_ptr);
	return 0;
}
*/

/*
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
		ft_lstiter((t_list *)(dict_int->vals[i]), &print_dic_el);
		ft_printf("\n");
	}
	
}

int main()
{
	t_dictionary dict = dicstrstr_new(10);
	dicstrstr_set(dict, "hello", "world");
	dicstrstr_set(dict, "thomas", "choquet");
	dicstrstr_set(dict, "test", "test");
	dicstrstr_set(dict, "a", "b");

	char *str = dicstrstr_get(dict, "thomas");
	ft_printf("%s\n", str);
	free(str);

	str = dicstrstr_get(dict, "hello");
	ft_printf("%s\n", str);
	free(str);

	str = dicstrstr_get(dict, "abcde");
	ft_printf("%s\n", str);

	// print_dic_debug(dict);
	dic_clear(dict);
	return 0;
}
*/

/*
void print_node(void *data)
{
	ft_printf("%s\n", (char *)data);
}

int main(int argc, char const *argv[])
{
	t_list	*list;
	t_list	**last_ptr;

	if (argc < 2)
		return (ft_printf("Error : no args\n"));
	for (size_t i = 1; i < argc; i++)
		ft_lstadd_back(&list, ft_lstnew((void *)(argv[i])));
	last_ptr = lst_lastnext(&list);

	ft_printf("%s\n\n", (*last_ptr)->data);

	ft_lstiter(list, &print_node);

	ft_lstadd_back(last_ptr, ft_lstnew((void *)"abcdef"));

	ft_printf("\n");

	ft_lstiter(list, &print_node);

	ft_lstclear(&list, NULL);
	return (0);
}
*/

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}

