/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaren <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:48:43 by skaren            #+#    #+#             */
/*   Updated: 2019/09/24 23:15:10 by skaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	if (*s1 != *s2++)
		return (*(const unsigned char *)s1\
			- *(const unsigned char *)(s2 - 1));
		if (*s1++ == '\0')
		return (0);
	while (--n != 0)
	{
		if (*s1 != *s2++)
			return (*(const unsigned char *)s1\
				- *(const unsigned char *)(s2 - 1));
			if (*s1++ == '\0')
			return (0);
	}
	return (0);
}
