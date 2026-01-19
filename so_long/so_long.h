
#ifndef SO_LONG_H
# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <stdlib.h>
# ifndef MAX_LINES
#  define MAX_LINES (5000)
# endif

typedef struct s_sprite
{
	void	*img_ptr;
	int		img_width;
	int		img_height;
	char	*location;
}	t_sprite;

typedef struct s_graph
{
	t_sprite	*wall;
	t_sprite	*open;
	t_sprite	*hero;
	t_sprite	*coin;
	t_sprite	*exit;
	t_sprite	*mons;
}	t_graph;

typedef struct s_data
{
	char	**orig;
	char	**copy;
	int		coins;
	void	*mlx_ptr;
	void	*win_ptr;
	t_graph	*grap;
	int		h_x;
	int		h_y;
	int		moves;
	int		y_lines;
	int		x_li;
	int		exit_reachable;
}	t_data;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

void	inc_move(t_data *data);
void	moveleft(t_data *data);
void	moveright(t_data *data);
void	movedown(t_data *data);
void	moveup(t_data *data);

void	render(t_data *data, int start_x, int start_y);
int		fill(char **copy, t_data *data);
char	*process(char *rawline, t_data *data, int fd);
char	**parse_map(int fd, t_data *exit);

int		handle_destroy(void *param);
void	ft_exit(char *message, t_data *data);
void	term_sprite(t_sprite *sprite, t_data *data);
void	term_graph(t_graph *graphics, t_data *data);
void	terminate(char **map);

int		file_is_dot_ber(char *filename);
void	init_img(t_data *data, t_sprite *name, char *path);
void	initialize_graphics(t_data *data);
int		open_file(char *str);
void	entrybomb(char **copy, int y, int x, t_data *data);

int		handle_keypress(int keycode, t_data *data);
void	ft_print(char **map, t_data *data);
void	start_game(t_data *data);
int		count_coins(char **map);
int		find_entry(char *str);

void	check_path(char **orig, t_data *data);
int		check_line(char **map, int linenumber, int border, t_data *data);
void	count_entryexit_line(char *line, int *entrys, int *exits);
void	check_map(char **map, t_data *data);
int		check_entryexit(char **map, int entrytarget, int exittarget,
			t_data *data);

void	inc_move_and_exit(t_data *data, char *message);
void	*ft_calloc(size_t nmemb, size_t size);

void	spawn_monster(t_data *data, unsigned int semirandom, int randy);
void	move_monsters(t_data *data);
void	check_zombies(t_data *data);

void	move_a_monster(t_data *data, int new_x, int new_y, t_point old_pos);
void	steal_coin(t_data *data);
char	*ft_strdup(const char *s);
void	inc_move_and_exit(t_data *data, char *message);

void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
			int *width, int *height);
int		mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr,
			int x, int y);
void	*mlx_init(void);
void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
int		mlx_hook(void *win_ptr, int x_event, int x_mask,
			int (*funct)(), void *param);
int		mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);
int		mlx_loop(void *mlx_ptr);
int		mlx_destroy_window(void *mlx_ptr, void *win_ptr);
int		mlx_destroy_image(void *mlx_ptr, void *img_ptr);
int		mlx_destroy_display(void *mlx_ptr);
#endif
