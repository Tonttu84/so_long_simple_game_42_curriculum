
#include "so_long.h"

static int	adjust_start_position(t_data *dat, int *x_sh, int *y_sh)
{
	if (dat->h_x > 16 && dat -> x_li >= 32)
	{
		*x_sh = dat->h_x - 16;
		if (dat -> h_x + 17 > dat -> x_li && dat -> x_li - 42 > 0)
			*x_sh = dat->x_li - 32;
	}
	if (dat->h_y > 16 && dat -> y_lines >= 27)
	{
		*y_sh = dat->h_y - 16;
		if (dat -> h_y + 10 > dat -> y_lines)
			*y_sh = dat->y_lines - 26;
	}
	return (*y_sh);
}

static void	img(t_data *dat, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window(dat->mlx_ptr, dat->win_ptr,
		img_ptr, x * 64, y * 64);
}

void	render(t_data *dat, int x_sh, int y_sh)
{
	int	x;
	int	y;

	y = adjust_start_position(dat, &x_sh, &y_sh);
	while (y < y_sh + 27)
	{
		x = x_sh;
		while (x < x_sh + 32)
		{
			if (dat->orig[y] && x < dat -> x_li && dat->orig[y][x] == '0')
				img(dat, dat->grap->open->img_ptr, x - x_sh, y - y_sh);
			else if (dat->orig[y] && x < dat -> x_li && dat->orig[y][x] == 'C')
				img(dat, dat->grap->coin->img_ptr, x - x_sh, y - y_sh);
			else if (dat->orig[y] && x < dat -> x_li && dat->orig[y][x] == 'P')
				img(dat, dat->grap->hero->img_ptr, x - x_sh, y - y_sh);
			else if (dat->orig[y] && x < dat -> x_li && dat->orig[y][x] == 'E')
				img(dat, dat->grap->exit->img_ptr, x - x_sh, y - y_sh);
			else if (dat->orig[y] && x < dat -> x_li && dat->orig[y][x] == 'M')
				img(dat, dat->grap->mons->img_ptr, x - x_sh, y - y_sh);
			else
				img(dat, dat->grap->wall->img_ptr, x - x_sh, y - y_sh);
			x++;
		}
		y++;
	}
}
