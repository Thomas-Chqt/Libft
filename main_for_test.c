/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_for_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:25:16 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/22 15:11:17 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <string.h>

#include "libft.h"

char f1(unsigned int index, char c)
{
	return 'a';
}

void f2(unsigned int index, char *c)
{
	(*c) += (index % 10);
}

int main()
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

	str = ft_memset(str, 0xff, 3);

	ft_bzero(str, 0);

	unsigned char buffer1[5] = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE};
	unsigned char buffer2[5];
	ft_memcpy(buffer2 , buffer1, 5);

	unsigned char buffer3[15];
	ft_memset(buffer3, 0x00, 5);
	ft_memcpy(buffer3 + 5, buffer1, 5);
	ft_memset(buffer3 + 10, 0x00, 5);
	// ft_memmove(buffer3 + 3, buffer3 + 5, 5);
	ft_memmove(buffer3 + 7, buffer3 + 5, 5);

	char *str1= "abcd";
	char str2[6] = "     ";
	ft_strlcpy(str2, str1, 6);

	char str3[20] = "ab";
	char str4[20] = "cd";
	ft_strlcat(str3, str4, 6);

	char a = ft_toupper('c');

	a = ft_tolower('C');

	str = "abab";
	str = ft_strchr(str, 'b');

	str = "abab";
	str = ft_strrchr(str, 'a');

	n = ft_strncmp("abcd", "abcde", 5);

	unsigned char buffer4[5] = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE};
	unsigned char str5 = ft_memchr(buffer4, 0xBB, 5);

	unsigned char buffer5[5] = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE};
	unsigned char buffer6[5] = {0xAA, 0xBB, 0xCC, 0xDD, 0x00};
	int diff = ft_memcmp(buffer5, buffer6, 5);

	const char *largestring = "Foo Bar Baz";
	const char *smallstring = "Bar";
	char *ptr;

	ptr = strnstr(largestring, smallstring, 40);

	int nbr = ft_atoi("56");

	return 0; 
}

