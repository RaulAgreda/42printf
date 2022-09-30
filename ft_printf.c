#include <ft_printf.h>
#include <stdarg.h>
#include "libft.h"

void	treat_macro(char c)
{
	if (ft_strchr("cspdiuxX%", c) != 0)
	{
		
	}
}

int	ft_printf(char const *str, ...)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '%')
		{
			treat_macro(str[i + 1]);
		}
		write(1, str + i, 1);
		i++;
	}
}