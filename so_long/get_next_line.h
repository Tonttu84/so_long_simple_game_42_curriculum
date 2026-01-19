#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE (10000000)
# endif
# ifndef MAX_FD
#  define MAX_FD (500)
# endif
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct s_buffer
{
	char	*rets;
	ssize_t	retl;
	char	*reads;
	ssize_t	readl;
	char	*bufs;
	ssize_t	bufl;
	int		st;
}	t_buf;

void	init_terminate(t_buf *l, ssize_t fdmax, int status);
char	*get_next_line(int fd);
void	strsplit(int fd, t_buf *l, ssize_t matchloc, ssize_t i);
ssize_t	read_buffer(int fd, t_buf *l);
char	*search(int fd, t_buf *l);
ssize_t	combine(int fd, t_buf *l, ssize_t i, ssize_t new_i);
#endif
