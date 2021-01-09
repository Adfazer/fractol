/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaren <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 14:52:37 by skaren            #+#    #+#             */
/*   Updated: 2019/09/25 02:48:14 by skaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	i_ln(size_t i, char const *s)
{
	if (s[0] == ' ' || s[0] == '\n' || s[0] == '\t')
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	size_t	l;
	size_t	i;
	size_t	ii;

	i = 0;
	if (!s)
		return (NULL);
	l = ft_strlen(s) - 1;
	i = i_ln(i, s);
	if (s[i] != '\0')
	{
		if (s[l] == ' ' || s[l] == '\n' || s[l] == '\t')
			while (s[l] == ' ' || s[l] == '\n' || s[l] == '\t')
				l--;
		if (!(str = ft_memalloc(l - i + 2)))
			return (NULL);
		ii = 0;
		while (i <= l)
			str[ii++] = s[i++];
		return (str);
	}
	if (!(str = ft_memalloc(1)))
		return (NULL);
	return (str);
}
