/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_for_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:25:16 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/04 19:32:59 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

#include "libft.h"

# ifdef MEMCHECK

#  include <memory_leak_detector.h>

__attribute__((destructor))
static void	destructor(void)
{
	print_report();
}

# endif // MEMCHECK

void print_int(void *data)
{
	printf("%d\n", *((int *)data));
}

int main()
{
	t_list *head = NULL;

	int a = 1;
	int b = 2;
	int c = 3;

	ft_lstadd_front(&head, ft_lstnew(&c));
	ft_lstadd_front(&head, ft_lstnew(&b));
	ft_lstadd_front(&head, ft_lstnew(&a));

	ft_lstiter(head, &print_int);
	ft_lstclear(&head, NULL);
	return 0; 
}
