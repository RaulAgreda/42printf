/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <ragreda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:41:19 by ragreda-          #+#    #+#             */
/*   Updated: 2022/10/01 12:51:43 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_puthex_fd(unsigned int n, int fd, int mayus, int print_zero)
{
	char	c;
	char	buffer[16];
	int		i;

	if (n == 0 && print_zero)
	{
		write(fd, "0", 1);
		return (1);
	}
	i = 0;
	while (n != 0 && i < 16)
	{
		if (n % 16 >= 10)
			c = n % 16 - 10 + 'a' - 32 * mayus;
		else
			c = n % 16 + '0';
		buffer[15 - i] = c;
		n /= 16;
		i += 1;
	}
	write(fd, buffer + 16 - i, i);
	return (i);
}
