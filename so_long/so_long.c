

#include "get_next_line.h"
#include "so_long.h"
#include "ftprintf.h"

static char	*drain_rawline(char *rawline, int fd)
{
	free(rawline);
	rawline = NULL;
	rawline = get_next_line(fd);
	return (rawline);
}

int	fill(char **copy, t_data *data)
{
	int	linenbr;
	int	charnbr;
	int	retval;

	linenbr = 0;
	while (find_entry(copy[linenbr]) == -1)
	{
		linenbr++;
	}
	data -> h_y = linenbr;
	charnbr = find_entry(copy[linenbr]);
	data -> h_x = charnbr;
	entrybomb(copy, linenbr +1, charnbr, data);
	entrybomb(copy, linenbr -1, charnbr, data);
	entrybomb(copy, linenbr, charnbr + 1, data);
	entrybomb(copy, linenbr, charnbr - 1, data);
	retval = check_entryexit(copy, -1, 1, data);
	if (count_coins(copy) != 0)
		retval = -1;
	if (copy != NULL)
		terminate(copy);
	return (retval);
}

char	*process(char *rawline, t_data *data, int fd)
{
	int	count;

	count = 0;
	while (rawline && rawline[count])
	{
		if (rawline[count] != '0' && rawline[count] != '1'
			&& rawline[count] != 'C' && rawline[count] != 'E'
			&& rawline[count] != 'P' && !(rawline[count] == '\n'
				&& count -1 >= 0 && rawline[count - 1] == '1'))
		{
			while (rawline != NULL)
			{
				rawline = drain_rawline(rawline, fd);
			}
			ft_exit("Error\nIllegal character, map is not valid", data);
		}
		if (rawline[count] == '\n')
		{
			rawline[count] = '\0';
			return (rawline);
		}
		count++;
	}
	return (rawline);
}

char	**parse_map(int fd, t_data *exit)
{
	static char	*map[MAX_LINES];
	int			i;
	char		*test;

	exit->orig = map;
	i = 0;
	while (i < MAX_LINES)
	{
		test = get_next_line(fd);
		map[i] = process(test, exit, fd);
		if (map[i] == NULL)
		{
			if (i == 0)
				ft_exit("Error\nNo map", exit);
			return (map);
		}
		i++;
	}
	ft_exit("Error\nNo map", exit);
	return (map);
}

int	main(int argc, char *argv[])
{
	int				fd;
	char			*buffer;
	static t_data	data[1];

	if (argc != 2)
		ft_exit("Error\nWrong amount of arguments", NULL);
	file_is_dot_ber(argv[1]);
	buffer = NULL;
	fd = open_file(argv[1]);
	if (read(fd, buffer, 0) != 0)
		ft_exit("Error\nCant read file", NULL);
	data -> mlx_ptr = mlx_init();
	if (data -> mlx_ptr == NULL)
		ft_exit("Error\nMemory allocation failed", data);
	data -> win_ptr = mlx_new_window(data -> mlx_ptr, 2048, 1664, "./so_long");
	if (data -> win_ptr == NULL)
		ft_exit("Error\nMemory allocation failed", data);
	data -> orig = parse_map(fd, data);
	check_map(data -> orig, data);
	mlx_hook(data->win_ptr, 17, 0, (int (*)())handle_destroy, (void *)data);
	mlx_key_hook(data -> win_ptr, handle_keypress, data);
	start_game(data);
	mlx_loop(data -> mlx_ptr);
	close(fd);
	return (0);
}
