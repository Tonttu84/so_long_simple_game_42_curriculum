/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrimpila <jrimpila@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:48:32 by jrimpila          #+#    #+#             */
/*   Updated: 2024/11/12 16:46:59 by jrimpila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

const char	*ft_print_undec(va_list args, const char *str, int *retval)
{
	unsigned int	basenbr;

	basenbr = va_arg(args, unsigned int);
	ft_putnbr_unsig(basenbr, retval);
	return (str + 2);
}

void	handle_format(va_list args, const char **format, int *retval)
{
	if (**format == '%' && (*(*format + 1) == 'x' || *(*format + 1) == 'X'))
		*format = ft_print_hex(args, *format, *(*format + 1), retval);
	else if (**format == '%' && *(*format + 1) == 'c')
		*format = ft_print_char(args, *format, retval);
	else if (**format == '%' && *(*format + 1) == 's')
		*format = ft_print_str(args, *format, retval);
	else if (**format == '%' && *(*format + 1) == 'p')
		*format = ft_print_hexptr(args, *format, retval);
	else if (**format == '%' && *(*format + 1) == 'd')
		*format = ft_print_int(args, *format, retval);
	else if (**format == '%' && *(*format + 1) == 'u')
		*format = ft_print_undec(args, *format, retval);
	else if (**format == '%' && *(*format + 1) == 'i')
		*format = ft_print_int(args, *format, retval);
	else
		*format = ft_putchar_spec(*format, retval);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		retval;

	retval = 0;
	va_start(args, format);
	while (*format)
	{
		handle_format(args, &format, &retval);
	}
	va_end(args);
	return (retval);
}
