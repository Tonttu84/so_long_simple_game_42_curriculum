
#include "ftprintf.h"
#include "so_long.h"

void	term_sprite(t_sprite *sprite, t_data *data)
{
	if (sprite -> img_ptr != NULL)
		mlx_destroy_image(data -> mlx_ptr, sprite -> img_ptr);
	sprite -> img_ptr = NULL;
	if (sprite != NULL)
		free (sprite);
	sprite = NULL;
}

void	terminate(char **map)
{
	int	i;

	i = 0;
	if (map == NULL)
		return ;
	while (i < MAX_LINES)
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
}

int	handle_destroy(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	ft_exit("Game over!", data);
	return (0);
}

void	term_graph(t_graph *graph, t_data *data)
{
	if (graph == NULL)
		return ;
	if (graph && graph -> wall != NULL)
		term_sprite(graph -> wall, data);
	if (graph && graph -> open != NULL)
		term_sprite(graph -> open, data);
	if (graph && graph -> hero != NULL)
		term_sprite (graph -> hero, data);
	if (graph && graph -> coin != NULL)
		term_sprite (graph -> coin, data);
	if (graph && graph -> exit != NULL)
		term_sprite (graph -> exit, data);
	if (graph && graph -> mons != NULL)
		term_sprite (graph -> mons, data);
	graph -> wall = NULL;
	graph -> open = NULL;
	graph -> hero = NULL;
	graph -> coin = NULL;
	graph -> exit = NULL;
	free(graph);
	graph = NULL;
}

void	ft_exit(char *message, t_data *data)
{
	if (message == NULL)
		ft_printf("Error\nNULL pointer for error message\n");
	else
		ft_printf("%s \n", message);
	if (data != NULL)
	{
		term_graph(data ->grap, data);
		terminate(data -> orig);
		terminate(data -> copy);
		mlx_destroy_window(data -> mlx_ptr, data -> win_ptr);
		mlx_destroy_display(data -> mlx_ptr);
		if (data -> mlx_ptr)
			free(data -> mlx_ptr);
	}
	exit(EXIT_FAILURE);
}
