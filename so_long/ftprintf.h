
#ifndef FTPRINTF_H
# define FTPRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

void		ft_put_hex(unsigned int num, int big, int *retval);
const char	*ft_putchar_spec(const char *c, int *retval);
void		ft_put_hexptr(unsigned long num, int big, int *retval);
void		ft_putstr(const char *s, int *retval);
void		ft_putnbr_unsig(unsigned int n, int *retval);
void		ft_putnbr(int n, int *retval);
const char	*ft_print_str(va_list args, const char *str, int *retval);
const char	*ft_print_hexptr(va_list args, const char *str, int *retval);
const char	*ft_print_char(va_list args, const char *str, int *retval);
const char	*ft_print_int(va_list args, const char *str, int *retval);
const char	*ft_print_undec(va_list args, const char *str, int *retval);
const char	*ft_print_hex(va_list args, const char *str, char x, int *retval);
int			ft_printf(const char *format, ...);
void		ft_putchar(char c, int *retval);
void		handle_format(va_list args, const char **format, int *retval);

#endif
