/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaren <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:14:23 by skaren            #+#    #+#             */
/*   Updated: 2019/09/22 17:47:20 by skaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	int		len;

	len = ft_strlen(src);
	str = malloc(len + 1);
	if (str)
		ft_memcpy(str, src, len + 1);
	return (str);
}
