/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 13:13:18 by exam              #+#    #+#             */
/*   Updated: 2019/09/25 02:54:49 by skaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	char_to_int(int i, const char *str)
{
	unsigned int	chi;
	unsigned int	pip;

	chi = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	i--;
	pip = 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		chi = chi + ((str[i] - '0') * pip);
		pip = pip * 10;
		i--;
	}
	return (chi);
}

int			ft_atoi(const char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '+' ||\
	str[i] == '-' || (str[i] >= '0' && str[i] <= '9') ||\
	(str[i] >= 7 && str[i] <= 13))
	{
		if ((str[i] == '+' || str[i] == '-') &&\
		!(str[i + 1] >= '0' && str[i + 1] <= '9'))
			return (0);
		if ((str[i] == '-' || str[i] == '+') &&\
		(str[i + 1] == '-' || str[i + 1] == '+'))
			return (0);
		if (str[i] == '-' && str[i + 1] >= '0' &&\
		str[i + 1] <= '9')
			return (char_to_int(i + 1, str) * -1);
		if (str[i] == '+' && str[i + 1] >= '0' &&\
		str[i + 1] <= '9')
			return (char_to_int(i + 1, str));
		if (str[i] >= '0' && str[i] <= '9')
			return (char_to_int(i, str));
		i++;
	}
	return (0);
}
