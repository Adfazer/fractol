/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaren <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:24:21 by skaren            #+#    #+#             */
/*   Updated: 2019/09/24 22:52:47 by skaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const char *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	if (!dest && !src)
		return (NULL);
	while (len--)
		*d++ = *s++;
	return (dest);
}
