/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_for_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:25:16 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/05 17:34:02 by tchoquet         ###   ########.fr       */
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

void	print_node(void *node)
{
	printf("%s\n", *((char **)node));
}

int main()
{
	char *str = "A B C D E F G H I J";
	char **splited_str = ft_split(str, ' ');

	t_list *head = list_from_array(splited_str, 10, sizeof(char *));

	ft_lstadd_front(&head, lst_remove_last(&head));
	ft_lstadd_back(&head,lst_remove_first(&head));

	ft_lstiter(head, &print_node);
	ft_lstclear(&head, NULL);
	free_splited_str(splited_str);

	return 0; 
}
