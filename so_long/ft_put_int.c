#include "ftprintf.h"

void	ft_putnbr_unsig(unsigned int n, int *retval)
{
	if (n > 9)
	{
		ft_putnbr_unsig(n / 10, retval);
		ft_putnbr_unsig(n % 10, retval);
	}
	else
		ft_putchar(n + '0', retval);
}

void	ft_putnbr(int n, int *retval)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", retval);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', retval);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, retval);
		ft_putnbr(n % 10, retval);
	}
	else
		ft_putchar(n + '0', retval);
}

const char	*ft_print_int(va_list args, const char *str, int *retval)
{
	int	num;

	num = va_arg(args, int);
	ft_putnbr(num, retval);
	return (str + 2);
}
