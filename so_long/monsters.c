/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monsters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrimpila <jrimpila@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:40:31 by jrimpila          #+#    #+#             */
/*   Updated: 2024/12/19 15:08:43 by jrimpila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ftprintf.h"

void	spawn_monster(t_data *data, unsigned int semirandom, int randy)
{
	int	randx;

	semirandom += 5 * data->moves;
	while (semirandom > 0)
	{
		randx = 0;
		while (randx < data->x_li)
		{
			if (data->orig[randy][randx] == '0')
			{
				if (semirandom == 1)
				{
					data->orig[randy][randx] = 'M';
					return ;
				}
				semirandom--;
			}
			randx++;
		}
		randy++;
		if (randy >= data->y_lines)
			randy = 0;
		semirandom--;
	}
}

static void	convert_n_to_m(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->y_lines)
	{
		x = 0;
		while (x < data->x_li)
		{
			if (data->orig[y][x] == 'N')
				data->orig[y][x] = 'M';
			x++;
		}
		y++;
	}
}

static void	zomb_determs_dir(t_data *data, int x, int y)
{
	int		dir;
	t_point	old_pos;

	if (data->orig[y][x] == 'M')
	{
		dir = (x + y + data->moves + data->h_x + data->h_y) % 4;
		old_pos = (t_point){x, y};
		if (dir == 0 && y > 0 && data->orig[y - 1][x] == '0')
			move_a_monster(data, x, y - 1, old_pos);
		else if (dir == 1 && y < data->y_lines - 1
			&& data->orig[y + 1][x] == '0')
			move_a_monster(data, x, y + 1, old_pos);
		else if (dir == 2 && x > 0 && data->orig[y][x - 1] == '0')
			move_a_monster(data, x - 1, y, old_pos);
		else if (dir == 3 && x < data->x_li - 1 && data->orig[y][x + 1] == '0')
			move_a_monster(data, x + 1, y, old_pos);
	}
}

void	move_monsters(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->y_lines)
	{
		x = 0;
		while (x < data->x_li)
		{
			zomb_determs_dir(data, x, y);
			x++;
		}
		y++;
	}
	convert_n_to_m(data);
}

void	check_zombies(t_data *data)
{
	if (data->orig[data->h_y - 1][data->h_x] == 'M')
	{
		render(data, 0, 0);
		ft_printf("Suddenly the zombie smells fresh brains and moves with ");
		ft_exit("surprising speed. You die.", data);
	}
	if (data->orig[data->h_y + 1][data->h_x] == 'M')
	{
		render(data, 0, 0);
		ft_printf("Suddenly the zombie smells fresh brains and moves with ");
		ft_exit("surprising speed. You die.", data);
	}
	if (data->orig[data->h_y][data->h_x - 1] == 'M')
	{
		render(data, 0, 0);
		ft_printf("Suddenly the zombie smells fresh brains and moves with ");
		ft_exit("surprising speed. You die.", data);
	}
	if (data->orig[data->h_y][data->h_x + 1] == 'M')
	{
		render(data, 0, 0);
		ft_printf("Suddenly the zombie smells fresh brains and moves with ");
		ft_exit("surprising speed. You die.", data);
	}
}
