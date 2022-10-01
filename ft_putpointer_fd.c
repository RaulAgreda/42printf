/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <ragreda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 13:12:12 by ragreda-          #+#    #+#             */
/*   Updated: 2022/10/01 13:13:03 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	n_digits(unsigned int n)
{
	int	counter;

	counter = 0;
	while (n != 0)
	{
		n /= 16;
		counter++;
	}
	return (counter);
}

int	ft_putpointer_fd(void *p, int fd)
{
	unsigned long long	lp;
	int					counter;
	int					first_counter;

	if (!p)
	{
		write(fd, "(nil)", 5);
		return (5);
	}
	counter = 2;
	write(1, "0x", 2);
	lp = (unsigned long long)p;
	first_counter = ft_puthex_fd(lp >> 32, fd, 0, 0);
	if (first_counter > 0)
	{
		counter += 8 - n_digits(lp);
		write(fd, "00000000", counter - 2);
	}
	counter += ft_puthex_fd(lp, fd, 0, 0);
	counter += first_counter;
	return (counter);
}
