/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrimpila <jrimpila@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:58:19 by jrimpila          #+#    #+#             */
/*   Updated: 2024/12/22 14:13:38 by jrimpila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_path(char **orig, t_data *data)
{
	static char	*copy[MAX_LINES];
	int			i;

	data->copy = copy;
	i = 0;
	while (i < MAX_LINES && orig[i] != NULL)
	{
		copy[i] = ft_strdup(orig[i]);
		if (copy[i] == NULL)
			ft_exit("Error\nMemory allocation failed\n", data);
		i++;
	}
	data -> y_lines = i;
	if (fill(copy, data) == -1)
	{
		ft_exit("Error\nNo legal path to all resources", data);
	}
}

int	check_line(char **map, int linenumber, int border, t_data *data)
{
	int	i;

	i = 0;
	if (map[linenumber][0] != '1')
	{
		ft_exit("Error\nLeft side lacks wall", data);
	}
	while (map[linenumber][i] != 0)
	{
		if (map[linenumber][i] != '1' && border == 1)
			ft_exit("Error\nTop or bottom walls missing", data);
		i++;
	}
	if (map[linenumber][i - 1] != '1')
	{
		ft_exit("Error\nRight side lacks wall", data);
	}
	return (i);
}

void	count_entryexit_line(char *line, int *entrys, int *exits)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'E')
			(*exits)++;
		if (line[i] == 'P')
			(*entrys)++;
		i++;
	}
}

void	check_map(char **map, t_data *data)
{
	static int	linelenght = -1;
	int			i;

	i = 0;
	while (i < MAX_LINES && map[i] != NULL)
	{
		if (linelenght == -1)
			linelenght = check_line(map, i, 1, data);
		if (linelenght != check_line(map, i, 0, data))
		{
			ft_exit("Error\nLines are different lenght", data);
		}
		i++;
	}
	data -> x_li = linelenght;
	check_line(map, i - 1, 1, data);
	if (check_entryexit(map, 1, 1, data) == -1)
	{
		ft_exit("Error\nIncorrect amount of exits", data);
	}
	check_path(map, data);
}

int	check_entryexit(char **map, int entrytarget, int exittarget, t_data *data)
{
	int	exits;
	int	entrys;
	int	line;

	line = 0;
	entrys = 0;
	exits = 0;
	while (map[line] != NULL)
	{
		count_entryexit_line(map[line], &entrys, &exits);
		line++;
	}
	if (exits != exittarget || (entrytarget > -1 && entrys != entrytarget))
	{
		ft_exit("Error\nMap is not valid", data);
		return (-1);
	}
	return (0);
}
