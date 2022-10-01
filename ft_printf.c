/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <ragreda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:41:06 by ragreda-          #+#    #+#             */
/*   Updated: 2022/10/01 13:15:14 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"

int	treat_macro(char c, va_list argptr)
{
	if (ft_strchr("cspdiuxX%", c) != 0)
	{
		if (c == 'c')
			return (ft_putchar_fd(va_arg(argptr, int), 1));
		else if (c == 's')
			return (ft_putstr_fd(va_arg(argptr, char *), 1));
		else if (c == 'p')
			return (ft_putpointer_fd(va_arg(argptr, void *), 1));
		else if (c == 'd' || c == 'i')
			return (ft_putnbr_fd(va_arg(argptr, int), 1));
		else if (c == 'u')
			return (ft_putnbr_fd(va_arg(argptr, unsigned int), 1));
		else if (c == 'x')
			return (ft_puthex_fd(va_arg(argptr, unsigned int), 1, 0, 1));
		else if (c == 'X')
			return (ft_puthex_fd(va_arg(argptr, unsigned int), 1, 1, 1));
		else if (c == '%')
			return (ft_putchar_fd('%', 1));
	}
	return (0);
}

int	ft_printf(char const *str, ...)
{
	int				i;
	unsigned int	n_char;
	va_list			argptr;

	va_start(argptr, str);
	i = 0;
	n_char = 0;
	while (str[i] != 0)
	{
		if (str[i] == '%')
		{
			n_char += treat_macro(str[i + 1], argptr);
			i += 2;
			continue ;
		}
		ft_putchar_fd(str[i], 1);
		i++;
		n_char++;
	}
	return (n_char);
}
