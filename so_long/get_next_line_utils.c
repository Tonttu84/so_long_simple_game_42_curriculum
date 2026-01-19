/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrimpila <jrimpila@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:21:37 by jrimpila          #+#    #+#             */
/*   Updated: 2024/12/22 14:20:56 by jrimpila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

void	init_terminate(t_buf *l, ssize_t fdmax, int status)
{
	ssize_t	i;

	i = 0;
	while (i <= fdmax && l != NULL)
	{
		if (status == 2 && l[i].rets != NULL)
		{
			free(l[i].rets);
		}
		l[i].rets = NULL;
		l[i].retl = 0;
		if (status == 2 && l[i].reads != NULL)
			free(l[i].reads);
		l[i].reads = NULL;
		l[i].readl = 0;
		if (status == 2 && l[i].bufs != NULL)
			free(l[i].bufs);
		l[i].bufs = NULL;
		l[i].bufl = 0;
		l[i].st = status;
		i++;
	}
}

void	strsplit(int fd, t_buf *l, ssize_t matchloc, ssize_t i)
{
	ssize_t	new_i;

	while (++i < matchloc)
		l[fd].rets[i] = l[fd].bufs[i];
	l[fd].rets[i] = 0;
	l[fd].retl = i;
	if (i >= l[fd].bufl && l[fd].bufs != NULL)
	{
		free(l[fd].bufs);
		l[fd].bufs = NULL;
		l[fd].bufl = 0;
	}
	else
	{
		new_i = 0;
		while (i < l[fd].bufl)
		{
			l[fd].bufs[new_i] = l[fd].bufs[i];
			i++;
			new_i++;
		}
		l[fd].bufs[new_i] = 0;
		l[fd].bufl = new_i;
	}
}

ssize_t	combine(int fd, t_buf *l, ssize_t i, ssize_t new_i)
{
	char		*tmp;

	tmp = (char *)malloc((l[fd].bufl + l[fd].readl + 2) * sizeof(char));
	if (tmp == NULL)
		return (init_terminate(l, (ssize_t)MAX_FD, 2), 0);
	while (i < l[fd].bufl)
	{
		tmp[i] = l[fd].bufs[i];
		i++;
	}
	while (i < l[fd].bufl + l[fd].readl)
	{
		tmp[i] = l[fd].reads[new_i];
		i++;
		new_i++;
	}
	tmp[i] = 0;
	if (l[fd].bufs != NULL)
		free(l[fd].bufs);
	l[fd].bufs = NULL;
	l[fd].bufs = tmp;
	tmp = NULL;
	l[fd].bufl = i;
	return (l[fd].readl);
}

ssize_t	read_buffer(int fd, t_buf *l)
{
	if (l[fd].reads == NULL)
		l[fd].reads = (char *)malloc(((ssize_t)BUFFER_SIZE +1) * sizeof(char));
	if (l[fd].reads == NULL)
		return (init_terminate(l, (ssize_t)MAX_FD, 2), 0);
	l[fd].readl = read(fd, l[fd].reads, (ssize_t)BUFFER_SIZE);
	if (l[fd].readl <= 0)
	{	
		if (l[fd].readl == -1)
			return (init_terminate(l, (ssize_t)MAX_FD, 2), 0);
		free(l[fd].reads);
		l[fd].reads = NULL;
		if (l[fd].st == 0)
			l[fd].st = 1;
		return (0);
	}
	if (l[fd].bufl < 1 || l[fd].bufs == NULL)
	{
		l[fd].reads[l[fd].readl] = 0;
		l[fd].bufs = l[fd].reads;
		l[fd].reads = NULL;
		l[fd].bufl = l[fd].readl;
		l[fd].readl = 0;
		return (l[fd].bufl);
	}
	return (combine(fd, l, 0, 0));
}

char	*search(int fd, t_buf *l)
{
	ssize_t	i;

	l[fd].rets = NULL;
	if (l[fd].bufs != NULL && l[fd].bufl > 0)
	{
		i = 0;
		while (i < l[fd].bufl)
		{
			if (l[fd].bufs[i] == '\n')
			{
				l[fd].rets = (char *)ft_calloc((i + 2), sizeof(char));
				if (l[fd].rets == NULL)
					return (init_terminate(l, (ssize_t)MAX_FD, 2), NULL);
				strsplit(fd, l, i +1, -1);
				return (l[fd].rets);
			}
			i++;
		}
	}
	return (NULL);
}
