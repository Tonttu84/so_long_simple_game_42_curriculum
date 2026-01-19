#include "ftprintf.h"

const char	*ft_putchar_spec(const char *c, int *retval)
{
	write(1, c, 1);
	*retval += 1;
	if (*c == '%' && *(c + 1) == '%')
		return (c + 2);
	else
		return (c + 1);
}

void	ft_putchar(char c, int *retval)
{
	write(1, &c, 1);
	*retval += 1;
}

void	ft_putstr(const char *s, int *retval)
{
	while (*s)
	{
		write(1, s++, 1);
		*retval += 1;
	}
}

const char	*ft_print_str(va_list args, const char *str, int *retval)
{
	char	*stream;

	stream = va_arg(args, char *);
	if (stream == NULL)
	{
		ft_putstr("(null)", retval);
		return (str + 2);
	}
	ft_putstr(stream, retval);
	return (str + 2);
}

const char	*ft_print_char(va_list args, const char *str, int *retval)
{
	int				num;
	char			c;

	num = va_arg(args, int);
	c = (char) num;
	ft_putchar(c, retval);
	return (str + 2);
}
