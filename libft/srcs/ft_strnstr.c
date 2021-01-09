/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaren <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:14:16 by skaren            #+#    #+#             */
/*   Updated: 2019/09/23 18:41:32 by skaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t ilen;

	if (*needle == '\0')
		return ((char*)haystack);
	ilen = ft_strlen(needle);
	while (*haystack && ilen <= len--)
	{
		if (!ft_strncmp(haystack, needle, ilen))
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
