/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaren <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:19:55 by skaren            #+#    #+#             */
/*   Updated: 2019/09/24 23:18:24 by skaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)	(unsigned int, char))
{
	size_t	i;
	char	*str;

	if (s != NULL && f != NULL)
	{
		i = ft_strlen(s) + 1;
		str = ft_memalloc(i);
		if (str == NULL)
			return (NULL);
		i = 0;
		while (s[i] != '\0')
		{
			str[i] = f(((unsigned int)i), ((char)s[i]));
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
