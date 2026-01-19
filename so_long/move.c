
#include "so_long.h"
#include "ftprintf.h"

void	inc_move(t_data *data)
{
	data -> moves += 1;
	if (data -> moves % 8 == 0)
	{
		spawn_monster(data, (unsigned int)(data -> x_li * data -> y_lines), 0);
	}
	check_zombies(data);
	move_monsters(data);
	render(data, 0, 0);
	ft_printf("Moves: %d\n", data -> moves);
}

void	moveup(t_data *data)
{
	if (data -> orig[data -> h_y -1][data -> h_x] == 'M')
	{
		data -> orig[data -> h_y -1][data -> h_x] = '0';
		ft_printf("You attack the zombie. It is tough but slow, finally you ");
		ft_printf("manage to kill it.\n");
		inc_move(data);
	}
	else if (data -> orig[data -> h_y -1][data -> h_x] == '0')
	{
		data -> orig[data -> h_y -1][data -> h_x] = 'P';
		data -> orig[data -> h_y][data -> h_x] = '0';
		data -> h_y = data -> h_y - 1;
		inc_move(data);
	}
	else if (data -> orig[data -> h_y -1][data -> h_x] == 'C')
	{
		data -> orig[data -> h_y -1][data -> h_x] = 'P';
		data -> orig[data -> h_y][data -> h_x] = '0';
		data -> h_y = data -> h_y - 1;
		steal_coin(data);
	}
	else if (data -> orig[data -> h_y -1][data -> h_x] == 'E'
	&& data -> coins == 0)
		inc_move_and_exit(data, "You won!");
}

void	movedown(t_data *data)
{
	if (data -> orig[data -> h_y +1][data -> h_x] == 'M')
	{
		data -> orig[data -> h_y +1][data -> h_x] = '0';
		ft_printf("You attack the zombie. It is tough but slow, ");
		ft_printf("finally you manage to kill it.\n");
		inc_move(data);
	}
	else if (data -> orig[data -> h_y +1][data -> h_x] == '0')
	{
		data -> orig[data -> h_y +1][data -> h_x] = 'P';
		data -> orig[data -> h_y][data -> h_x] = '0';
		data -> h_y = data -> h_y +1;
		inc_move(data);
	}
	else if (data -> orig[data -> h_y +1][data -> h_x] == 'C')
	{
		data -> orig[data -> h_y +1][data -> h_x] = 'P';
		data -> orig[data -> h_y][data -> h_x] = '0';
		data -> h_y = data -> h_y +1;
		steal_coin(data);
	}
	else if (data -> orig[data -> h_y +1][data -> h_x] == 'E'
	&& data -> coins == 0)
		inc_move_and_exit(data, "You won!");
}

void	moveright(t_data *data)
{
	if (data -> orig[data -> h_y][data -> h_x + 1] == 'M')
	{
		data -> orig[data -> h_y][data -> h_x + 1] = '0';
		ft_printf("You attack the zombie. It is tough but slow, ");
		ft_printf("finally you manage to kill it.\n");
		inc_move(data);
	}
	else if (data -> orig[data -> h_y][data -> h_x +1] == '0')
	{
		data -> orig[data -> h_y][data -> h_x +1] = 'P';
		data -> orig[data -> h_y][data -> h_x] = '0';
		data -> h_x = data -> h_x + 1;
		inc_move(data);
	}
	else if (data -> orig[data -> h_y][data -> h_x +1] == 'C')
	{
		data -> orig[data -> h_y][data -> h_x +1] = 'P';
		data -> orig[data -> h_y][data -> h_x] = '0';
		data -> h_x = data -> h_x + 1;
		steal_coin(data);
	}
	else if (data -> orig[data -> h_y][data -> h_x +1] == 'E'
	&& data -> coins == 0)
		inc_move_and_exit(data, "You won!");
}

void	moveleft(t_data *data)
{
	if (data -> orig[data -> h_y][data -> h_x - 1] == 'M')
	{
		data -> orig[data -> h_y][data -> h_x - 1] = '0';
		ft_printf("You attack the zombie. It is tough but slow, ");
		ft_printf("finally you manage to kill it.\n");
		inc_move(data);
	}
	else if (data -> orig[data -> h_y][data -> h_x -1] == '0')
	{
		data -> orig[data -> h_y][data -> h_x -1] = 'P';
		data -> orig[data -> h_y][data -> h_x] = '0';
		data -> h_x = data -> h_x - 1;
		inc_move(data);
	}
	else if (data -> orig[data -> h_y][data -> h_x -1] == 'C')
	{
		data -> orig[data -> h_y][data -> h_x -1] = 'P';
		data -> orig[data -> h_y][data -> h_x] = '0';
		data -> h_x = data -> h_x - 1;
		steal_coin(data);
	}
	else if (data -> orig[data -> h_y][data -> h_x -1] == 'E'
	&& data -> coins == 0)
		inc_move_and_exit(data, "You won!");
}
