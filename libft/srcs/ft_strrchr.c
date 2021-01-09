/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaren <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:19:05 by skaren            #+#    #+#             */
/*   Updated: 2019/09/23 17:10:38 by skaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if ((char)c == '\0')
		return ((char*)s + i);
	while (i)
	{
		if (s[i] == (char)c)
			return ((char*)s + i);
		i--;
	}
	if (s[i] == (char)c)
		return ((char*)s + i);
	return (NULL);
}
