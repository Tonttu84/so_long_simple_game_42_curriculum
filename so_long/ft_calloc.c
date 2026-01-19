
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>
#include "so_long.h"

static void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	int				counter;

	ptr = (unsigned char *)s;
	counter = 0;
	while (n--)
	{
		ptr[counter] = (unsigned char)c;
		counter++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = (void *)malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, (nmemb * size));
	return (ptr);
}
