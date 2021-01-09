/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaren <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 16:45:53 by skaren            #+#    #+#             */
/*   Updated: 2019/11/11 17:35:06 by skaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*check_balance(char *balance, char **line)
{
	char	*find_n_in_buf;

	find_n_in_buf = NULL;
	if (balance)
		if ((find_n_in_buf = ft_strchr(balance, '\n')))
		{
			*find_n_in_buf = '\0';
			*line = ft_strdup(balance);
			find_n_in_buf++;
			ft_strcpy(balance, find_n_in_buf);
		}
		else
		{
			*line = ft_strdup(balance);
			ft_strclr(balance);
		}
	else
		*line = ft_strnew(0);
	return (find_n_in_buf);
}

void	new_balance(char **find_n_in_buf, char **trash, char ***balance)
{
	**find_n_in_buf = '\0';
	*trash = **balance;
	(*find_n_in_buf)++;
	**balance = (char *)ft_strdup((const char *)(*find_n_in_buf));
	free(*trash);
}

int		get_next_line2(const int fd, char **line, char **balance)
{
	int			how_b;
	char		buf[BUFF_SIZE + 1];
	char		*trash;
	char		*find_n_in_buf;

	find_n_in_buf = check_balance(*balance, line);
	how_b = -1;
	while (!find_n_in_buf && (how_b = read(fd, buf, BUFF_SIZE)))
	{
		if (how_b <= 0)
			return (-1);
		buf[how_b] = '\0';
		if ((find_n_in_buf = ft_strchr(buf, '\n')))
			new_balance(&find_n_in_buf, &trash, &balance);
		trash = *line;
		if (!(*line = ft_strjoin(*line, buf)))
		{
			free(line);
			return (-1);
		}
		free(trash);
	}
	if (how_b || ft_strlen(*line))
		return (1);
	return (0);
}

t_gnl	*nlist(const int fd)
{
	t_gnl	*n;

	if (!(n = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	n->fd = fd;
	n->balance = ft_strnew(BUFF_SIZE);
	n->next = NULL;
	return (n);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*list;
	t_gnl			*trash;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (!list)
		list = nlist(fd);
	trash = list;
	while (trash->fd != fd)
	{
		if (trash->next == NULL)
		{
			if (!(trash->next = nlist(fd)))
				return (-1);
		}
		trash = trash->next;
	}
	return (get_next_line2(fd, line, &trash->balance));
}
