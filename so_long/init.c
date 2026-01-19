/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrimpila <jrimpila@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:17:05 by jrimpila          #+#    #+#             */
/*   Updated: 2024/12/22 14:36:30 by jrimpila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include "so_long.h"

void	entrybomb(char **copy, int y, int x, t_data *data)
{
	if (copy[y] == NULL || x < 0 || y < 0)
		ft_exit ("Error\n Map is not legal\n", data);
	if (copy[y][x] == 0)
		ft_exit ("Error\n Map is not legal\n", data);
	if (copy[y][x] == 'E')
		data -> exit_reachable = 1;
	if (copy[y][x] == 'C' || copy[y][x] == '0')
	{
		copy[y][x] = 'P';
		entrybomb(copy, y + 1, x, data);
		entrybomb(copy, y - 1, x, data);
		entrybomb(copy, y, x + 1, data);
		entrybomb(copy, y, x - 1, data);
	}
}

int	file_is_dot_ber(char *filename)
{
	int	i;

	i = 0;
	while (filename[i] != '\0')
		i++;
	if (i < 5)
		ft_exit("Error\nIllegal file type", NULL);
	if (filename[i - 4] != '.')
		ft_exit("Error\n Illegal file type", NULL);
	if (filename[i - 3] != 'b')
		ft_exit("Error\nIllegal file type", NULL);
	if (filename[i - 2] != 'e')
		ft_exit("Error\nIllegal file type", NULL);
	if (filename[i - 1] != 'r')
		ft_exit("Error\nIllegal file type", NULL);
	return (1);
}

int	open_file(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nError opening file");
		return (-1);
	}
	return (fd);
}

void	init_img(t_data *data, t_sprite *name, char *path)
{
	if (name == NULL)
		ft_exit("Error\nMemory allocation failed\n", data);
	if (open(path, O_RDONLY) == -1)
	{
		name->img_width = 30;
		name->img_height = 30;
		name->location = NULL;
		name->img_ptr = NULL;
		ft_exit("Error\nCant open texture file\n", data);
	}
	name->img_width = 30;
	name->img_height = 30;
	name->location = path;
	name->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, path,
			&name->img_width, &name->img_height);
	if (name->img_ptr == NULL)
	{
		name->img_width = 30;
		name->img_height = 30;
		name->location = NULL;
		ft_exit("Error\nFailed to load image\n", data);
	}
}

void	initialize_graphics(t_data *data)
{
	data->grap = (t_graph *)ft_calloc(1, sizeof(t_graph));
	if (data->grap == NULL)
		ft_exit("Error\nMemory allocation failed\n", data);
	data->grap->wall = (t_sprite *)ft_calloc(1, sizeof(t_sprite));
	data->grap->open = (t_sprite *)ft_calloc(1, sizeof(t_sprite));
	data->grap->coin = (t_sprite *)ft_calloc(1, sizeof(t_sprite));
	data->grap->hero = (t_sprite *)ft_calloc(1, sizeof(t_sprite));
	data->grap->exit = (t_sprite *)ft_calloc(1, sizeof(t_sprite));
	data->grap->mons = (t_sprite *)ft_calloc(1, sizeof(t_sprite));
	init_img(data, data->grap->mons, "textures/mons.xpm");
	init_img(data, data->grap->wall, "textures/wall.xpm");
	init_img(data, data->grap->open, "textures/open.xpm");
	init_img(data, data->grap->coin, "textures/coin.xpm");
	init_img(data, data->grap->hero, "textures/hero.xpm");
	init_img(data, data->grap->exit, "textures/exit.xpm");
}
