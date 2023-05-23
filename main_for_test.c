/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_for_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:25:16 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/23 16:13:25 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <string.h>

#include "libft.h"

int main()
{
	unsigned char src[5] = {0xAA, 0xBB, 0xCC} ;
	unsigned char des[5] = {0x00, 0x00, 0x00} ;

	unsigned char *s = ft_memcpy(NULL, NULL, 2);

	return 0; 
}

