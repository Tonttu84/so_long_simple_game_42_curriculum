/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrimpila <jrimpila@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:12:11 by jrimpila          #+#    #+#             */
/*   Updated: 2024/11/18 13:12:17 by jrimpila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

void	ft_put_hexptr(unsigned long num, int big, int *retval)
{
	if (num >= 16)
		ft_put_hexptr(num / 16, big, retval);
	if (num % 16 <= 9)
		ft_putchar((num % 16) + '0', retval);
	if ((num % 16) > 9 && big == 0)
		ft_putchar((num % 16) + ('a' - 10), retval);
	else if ((num % 16) > 9 && big == 1)
		ft_putchar((num % 16) + ('A' - 10), retval);
}

void	ft_put_hex(unsigned int num, int big, int *retval)
{
	if (num >= 16)
		ft_put_hex(num / 16, big, retval);
	if (num % 16 <= 9)
		ft_putchar((num % 16) + '0', retval);
	if ((num % 16) > 9 && big == 0)
		ft_putchar((num % 16) + ('a' - 10), retval);
	else if ((num % 16) > 9 && big == 1)
		ft_putchar((num % 16) + ('A' - 10), retval);
}

const char	*ft_print_hexptr(va_list args, const char *str, int *retval)
{
	void			*ptr;
	uintptr_t		adr;

	ptr = va_arg(args, void *);
	if (ptr == NULL)
	{
		ft_putstr("(nil)", retval);
		return (str + 2);
	}
	adr = (uintptr_t)ptr;
	ft_putstr("0x", retval);
	ft_put_hexptr(adr, 0, retval);
	return (str + 2);
}

const char	*ft_print_hex(va_list args, const char *str, char x, int *retval)
{
	unsigned int	adr;

	adr = va_arg(args, unsigned int);
	if (x == 'x')
		ft_put_hex(adr, 0, retval);
	else if (x == 'X')
		ft_put_hex(adr, 1, retval);
	return (str + 2);
}
