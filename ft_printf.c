#include <stdarg.h>
#include <unistd.h>
#include "libft/libft.h"
#include "ft_printf.h"

int	treat_macro(char c, va_list argptr)
{
	if (ft_strchr("cspdiuxX%", c) != 0)
	{
		if (c == 'c')
			ft_putchar_fd(*va_arg(argptr, char *), 1);
		else if (c == 's')
			ft_putstr_fd(va_arg(argptr, char *), 1);
		else if (c == 'p')
			ft_putpointer_fd(va_arg(argptr, void *), 1);
		else if (c == 'd' || c == 'i')
			ft_putnbr_fd(va_arg(argptr, int), 1);
		else if (c == 'u')
			ft_putnbr_fd(va_arg(argptr, unsigned int), 1);
		else if (c == 'x')
			ft_puthex_fd(va_arg(argptr, unsigned int), 1, 0);
		else if (c == 'X')
			ft_puthex_fd(va_arg(argptr, unsigned int), 1, 1);
		else if (c == '%')
			ft_putchar_fd('%', 1);
	}
	return (-1);
}

int	ft_printf(char const *str, ...)
{
	int	i;
	va_list argptr;
	va_start(argptr, str);

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '%')
		{
			treat_macro(str[i + 1], argptr);
			i += 2;
			continue;
		}
		write(1, str + i, 1);
		i++;
	}
}