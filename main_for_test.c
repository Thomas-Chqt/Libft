/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_for_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:25:16 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/19 21:48:39 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "libft.h"

char f1(unsigned int index, char c)
{
	return 'a';
}

void f2(unsigned int index, char *c)
{
	(*c) += (index % 10);
}

int main(int argc, char const *argv[])
{
	size_t len = ft_strlen("qwerty");

	char* str = ft_substr("abcdef", 1, 3);

	str = ft_strjoin("abcd", "efghi");

	str = ft_strtrim(".;[abcd./]", ".;[]/");

	char** split_array = ft_split("  a  b  c  ", ' ');

	str = ft_itoa(INT32_MIN);

	str = ft_strmapi("abcdefgh", &f1);

	ft_striteri(str, &f2);

	int fd = 1; //open("test.txt", O_RDWR);

	ft_putchar_fd('a', fd);

	ft_putstr_fd("\nazerty\n", fd);

	ft_putendl_fd("azerty", fd);

	ft_putnbr_fd(INT32_MIN, fd);
	
	int n = ft_isalpha('a');

	n = ft_isdigit('0');

	n = ft_isalnum('a');

	n = ft_isascii('a');

	n = ft_isprint('a');

	return 0; 
}

