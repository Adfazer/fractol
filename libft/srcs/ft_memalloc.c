/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaren <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:42:27 by skaren            #+#    #+#             */
/*   Updated: 2019/09/24 23:17:40 by skaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*aa;
	size_t	i;

	i = 0;
	if (!(aa = (char*)malloc(size * sizeof(char))))
		return (NULL);
	else
	{
		while (i != size)
		{
			aa[i] = 0;
			i++;
		}
	}
	return (aa);
}
