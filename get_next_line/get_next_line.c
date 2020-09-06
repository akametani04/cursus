/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akametan <akametan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 01:15:41 by akametan          #+#    #+#             */
/*   Updated: 2020/08/21 00:14:48 by akametan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		process_error(char **buf, char **memo)
{
	free(*buf);
	free(*memo);
	return (ERROR);
}

int		process_zero(char **buf, char **memo, char ***line)
{
	free(*buf);
	**line = ft_strndup(*memo, ft_strlen(*memo));
	free(*memo);
	*memo = NULL;
	return (FIN);
}

void	read_mid(char **buf, char **tmp, int n, char **memo)
{
	(*buf)[n] = '\0';
	if (!*memo)
		*memo = ft_strndup(*buf, n);
	else
	{
		*tmp = ft_strjoin(*memo, *buf);
		free(*memo);
		*memo = *tmp;
		*tmp = NULL;
	}
}

void	leave_memo(char **newline, char **tmp, char **memo)
{
	(*newline)++;
	*tmp = ft_strndup(*newline, ft_strlen(*newline));
	free(*memo);
	*memo = *tmp;
}

int		get_next_line(int fd, char **line)
{
	char		*tmp;
	int			n;
	char		*buf;
	char		*newline;
	static char	*memo;

	if (fd < 0 || !line)
		return (ERROR);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (ERROR);
	while ((newline = ft_strchr(memo, '\n')) == NULL)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n < 0)
			return (process_error(&buf, &memo));
		else if (n == 0)
			return (process_zero(&buf, &memo, &line));
		read_mid(&buf, &tmp, n, &memo);
	}
	free(buf);
	if ((*line = ft_strndup(memo, newline - memo)) == NULL)
		return (ERROR);
	leave_memo(&newline, &tmp, &memo);
	return (!memo ? ERROR : DONE);
}
