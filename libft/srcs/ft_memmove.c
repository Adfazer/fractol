/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaren <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:45:01 by skaren            #+#    #+#             */
/*   Updated: 2019/09/23 15:42:53 by skaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;
	unsigned char		*lasts;
	unsigned char		*lastd;

	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	if (!dest && !src)
		return (NULL);
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
	{
		lasts = ((unsigned char*)s) + (len - 1);
		lastd = d + (len - 1);
		while (len--)
			*lastd-- = *lasts--;
	}
	return (dest);
}
