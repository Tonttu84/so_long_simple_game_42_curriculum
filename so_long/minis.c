#include "ftprintf.h"
#include "so_long.h"

void	move_a_monster(t_data *data, int new_x, int new_y, t_point old_pos)
{
	data->orig[new_y][new_x] = 'N';
	data->orig[old_pos.y][old_pos.x] = '0';
}

void	inc_move_and_exit(t_data *data, char *message)
{
	data->moves += 1;
	ft_exit(message, data);
}

void	steal_coin(t_data *data)
{
	data -> coins = data -> coins -1;
	ft_printf("You steal a huge gold coin. ");
	ft_printf("Magical defences summon more zombies.\n");
	spawn_monster(data, (unsigned int)(data -> x_li * data -> y_lines), 0);
	spawn_monster(data, (unsigned int)(data -> x_li * data -> y_lines), 0);
	spawn_monster(data, (unsigned int)(data -> x_li * data -> y_lines), 0);
	inc_move(data);
}
