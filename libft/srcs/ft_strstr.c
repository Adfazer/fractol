/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaren <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:11:36 by skaren            #+#    #+#             */
/*   Updated: 2019/09/23 17:28:49 by skaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack)
	{
		if ((*haystack == *needle) &&\
			(ft_strncmp(haystack, needle, ft_strlen(needle)) == 0))
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
