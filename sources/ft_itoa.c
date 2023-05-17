/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:08:50 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/17 18:48:57 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_absintlen(long nb, unsigned short *len);
static unsigned short	ft_intlen(int n);

char	*ft_itoa(int n)
{
	char			*str;	

	str = malloc(ft_intlen(n) * sizeof(char));
	
}

static unsigned short	ft_intlen(int n)
{
	unsigned short	len;
	long			l_n;

	len = 0;
	l_n = (long)n;

	if (l_n < 0)
	{
		len++;
		l_n *= -1;
	}
	ft_absintlen(l_n, &len);
	return (len);
}

static void	ft_absintlen(long nb, unsigned short *len)
{
	if ((nb / 10) > 0)
	{
		ft_absintlen(nb / 10, len);
	}
	(*len)++;
}