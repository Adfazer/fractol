/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaren <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 01:25:00 by skaren            #+#    #+#             */
/*   Updated: 2019/09/25 02:46:22 by skaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	intlen(long in)
{
	size_t	i;

	i = 1;
	while (in >= 10)
	{
		i++;
		in /= 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	long	in;
	size_t	neg;
	size_t	len;
	char	*str;

	neg = 0;
	in = n;
	if (in < 0)
	{
		neg = 1;
		in = -in;
	}
	len = intlen(in);
	if (!(str = ft_memalloc(neg + len + 1)))
		return (NULL);
	if (neg)
		str[0] = '-';
	while (len)
	{
		str[len + neg - 1] = (in % 10) + '0';
		len--;
		in /= 10;
	}
	return (str);
}
