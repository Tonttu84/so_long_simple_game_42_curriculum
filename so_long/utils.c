/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrimpila <jrimpila@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:41:06 by jrimpila          #+#    #+#             */
/*   Updated: 2024/12/18 15:15:26 by jrimpila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include "so_long.h"

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == 65307)
		handle_destroy(data);
	if (keycode == 119 || keycode == 65362)
		moveup(data);
	if (keycode == 115 || keycode == 65364)
		movedown(data);
	if (keycode == 100 || keycode == 65363)
		moveright(data);
	if (keycode == 97 || keycode == 65361)
		moveleft(data);
	return (0);
}

void	ft_print(char **map, t_data *data)
{
	int	i;

	i = 0;
	if (map == NULL)
		ft_exit("Error\nTried to print an invalid map", data);
	while (map[i] != NULL)
	{
		ft_printf("Line%d: %s\n", i, map[i]);
		i++;
	}
}

void	start_game(t_data *data)
{
	initialize_graphics(data);
	render (data, 0, 0);
	data -> coins = count_coins(data -> orig);
	if (data -> coins == 0)
		ft_exit("Error\nNo coins", data);
	if (data -> exit_reachable != 1)
		ft_exit("Error\nExit not reachable", data);
}

int	count_coins(char **map)
{
	int	line;
	int	i;
	int	coins;

	line = 0;
	coins = 0;
	while (map[line] != NULL)
	{
		i = 0;
		while (map[line][i] != 0)
		{
			if (map[line][i] == 'C')
				coins++;
			i++;
		}
		line++;
	}
	return (coins);
}

int	find_entry(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'P')
			return (i);
		i++;
	}
	return (-1);
}
