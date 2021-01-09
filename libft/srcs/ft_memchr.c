/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaren <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:59:12 by skaren            #+#    #+#             */
/*   Updated: 2019/09/22 17:23:36 by skaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int val, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
	{
		if (*((char*)buf + i) == val)
			return ((char*)buf + i);
		i++;
	}
	return (NULL);
}
