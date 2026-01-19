#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_buf	l[MAX_FD + 1];

	while (fd <= (int)MAX_FD && fd >= 0 && BUFFER_SIZE > 0 && l[fd].st != 2)
	{
		if (l[fd].bufl > 0 && search(fd, l) != NULL)
			return (l[fd].rets);
		if (l[fd].st == 1)
		{
			l[fd].st = 2;
			if (l[fd].bufl > 0)
				return (l[fd].bufs);
			return (NULL);
		}
		if (l[fd].st <= 1)
			read_buffer(fd, l);
	}
	return (NULL);
}
